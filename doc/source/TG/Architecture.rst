============
Architecture
============

Overview
--------

amforth is an indirect threading Forth. The dictionary is on 
a memory that allows execution of code. The RAM contains buffers, 
variables and the stacks. Depending on the platform, either the 
EEPROM or a special section of the flash is used for vital data 
such as pointers or configuration settings. 

The compiler is a classic compiler without any optimization
support.

Amforth uses all of the CPU registers internally: The
data stack pointer, the instruction pointer, the user pointer, and
the Top-Of-Stack cell. The hardware stack is used as the return
stack. Some registers are used for temporary data in primitives.

Core System
-----------

Threading Model
...............

AmForth implements the classic indirect threaded variant of
forth. The registers and their mappings are shown in table
:ref:`avr8_register_mappings`.

.. _Inner Interpreter:

Inner Interpreter
.................

For the indirect threading model an inner interpreter is
needed. The inner interpreter does the interrupt handling too.
It repeatedly reads the cell, the :command:`IP` points to, takes this number
as the address for the next code segment and jumps to that code.
It is expected that this code segment does a jump back to the
inner interpreter (NEXT). The :command:`IP` is incremented by 1 just before
the jumps are done to get the next cell.

.. code-block:: none

   Check_Interrupt
   W  <- [IP]   ; read at IP
   IP <- IP+1   ; advance IP
   X  <- [W]    ; EXECUTE phase, W points to execution token
   JMP [X]      ; read execution token and execute its code

NEXT
~~~~

The NEXT routine is the core of the inner interpreter. It does the
mapping between the execution tokens and the corresponding machine
code. It consists of 4 steps which are executed for every forth word.

The first step is to check whether an interrupt needs to
be handled. In that case, the interrupt service is called first.

The next step is to read the cell the :command:`IP` points to and
stores this value in the W register. For a COLON word
W contains the address of the code field.

The 3rd step is to increase the :command:`IP` register by 1.

The 4th step is the EXECUTE step.


EXECUTE
~~~~~~~

This operation is the JUMP.  It reads the content of the cell the
:command:`W` register points to. The result is stored in a scratch pad
register The data in it is the address of the machine code to be
executed in the last step. This step is used by the forth command
:command:`EXECUTE` too. The forth command does not get the address
of the next destination from the current :command:`IP` but from the data stack.

This last step finally jumps to the machine code pointed to
by the scratch pad register.


DO COLON
~~~~~~~~

DO COLON (aka NEST) is the subroutine call. It pushes the
:command:`IP` onto the return stack. It then increments :command:`W`
by one cell, so that it points to the body of the (colon) word,
and sets :command:`IP` to that value. Then it continues with
:command:`NEXT`, which begins executing the words in the body
of the (parent) colon word. Note that :command:`W` points to
the execution token of the current word, so the next cell points 
to the parameter field (body) of the forth word.

.. code-block:: none

  push IP
  IP <- W+1
  JMP NEXT

EXIT
~~~~

The code for EXIT (aka UNNEST) is the return from a subroutine.
It is defined in the forth word :command:`EXIT` in the dictionary.
It reads the :command:`IP` from the return stack and jumps to NEXT. 

.. code-block:: none

  pop IP
  JMP NEXT


Text Interpreter
----------------

The interpreter is a line based command interpreter. It based upon 
::command:`REFILL` to acquire the next line of characters, 
located at a position :command:`SOURCE` points to. While processing 
the line, the pointer :command:`>IN` is adjusted accordingly. Both
words :command:`REFILL` and :command:`SOURCE` are USER based 
deferred words which allows to use any input source on a thread 
specific level. The interpreter itself does not use any static 
buffers or variables (:command:`>IN` is a USER variable as well).

A given string is handled by :command:`INTERPRET` which splits it
into whitespace delimited words. Every word is processed using a 
list of recognizers. Processing ends either when the string end is 
reached or an exception occurs.

SOURCE and REFILL
.................

:command:`SOURCE` provides an addr/len string pair that does not 
change during processing. The task of :command:`REFILL` is to fill
the string buffer, :command:`SOURCE` points to when finished.

There is one default input source: The terminal input buffer. 
This buffer gets filled with :command:`REFILL-TIB` that reads 
from the serial input buffers (:command:`KEY`). :command:`SOURCE` 
points to the Terminal Input Buffer itself. Another input source 
are plain strings, used by :command:`EVALUATE`.

.. _Recognizers:

Recognizer
..........

Recognizer are a part of the text (command) interpreter.
They are responsible for analyzing a single word. The
result consists of two elements: The actual data (if any)
and an object like identifier connected with certain methods.

.. digraph:: Recognizer

   "Interpret" -> "Get Next Word"
   "Get Next Word" -> "Recognize" [label="Got one"]
   "Get Next Word" -> "End" [label="No More Words"];
   "Recognize" -> "Check State"
   "Check State" -> "Compile" [label="Compile"];
   "Check State" -> "Execute" [label="Interpret"];
   "Compile" -> "Get Next Word"
   "Execute" -> "Get Next Word"

The Forth text interpreter reads from the input source 
and splits it into whitespace delimited words. Each word
is fed into a list of actions which parse it. If the
parsing is successful (e.g. it is a number or a word from
the dictionary) the recognizer leaves the data and
an method table to deal with it. Depending on the
interpreter state one of the methods is executed to
finally process the data. The first method is called
in interpreter state. It is usually a noop, since
the recognizer has done all the work already.

The 2nd method is responsible to perform the compile
time semantics. That usually means to write it into
the dictioanary or to execute immediate words.

The third method is used by :command`postpone` to compile the
compilation semantics. It honors the immediate flags as well.

``Recognize`` is an iteration over a recognizer
stack until the first parsing methods returns something
different than :command:`DT:NULL`. If the recognizer stack is
exhausted without a match, the :command:`DT:NULL` return value
is generated. The string location that is passed to the 
parse actions is preserved and is restored for every iteration
cycle.

.. digraph:: Recognize

   "Get Recognizer Stack" -> "Rec-Stack Exhausted?"
   "Rec-Stack Exhausted?" -> "RECTYPE-NULL"  [label="Yes"]
   "Rec-Stack Exhausted?" -> "Call Parse Action"  [label="Consume Rec-TOS"]
   "Call Parse Action" -> "Rec-Stack Exhausted?" [label="RECTYPE-NULL"]
   "Call Parse Action" -> "End" [label="Success"]
   "RECTYPE-NULL" -> "End"

A recognizer consists of a few words that work together.
To ease maintenance, a naming convention is used: The
recognizer itself is named with the prefix ``rec-``. The
method table name gets the prefix ``rectype-`` followed by
the same name as the recognizer.

:command:`POSTPONE` serialises the parsed data as literals and
adds the compile action from the method table. This an
almost generic operation, it depends only on the number
of cells from the parsing actions.

Recognizer Stack
~~~~~~~~~~~~~~~~

The interpreter uses a default stack of recognizers. It is managed
with the words :command:`get-recognizers` and :command:`set-recognizers`.

The entries in the list are called in order until the first 
one returns a different result but :command:`RECTYPE-NULL`. If the list
is exhausted and no one succeeds, the :command:`RECTYPE-NULL` is delivered
nevertheless and leads to the error reactions.

The standard recognizer stack is defined as follows

.. code-block:: forth

   : default-recs
     ['] rec:intnum ['] rec:word
     2 forth-recognizer set-recognizers
   ;

The standard word :command:`marker` resets the recognizer list as well.

INTERPRET
~~~~~~~~~

The interpreter is responsible to split the source into words
and to call the recognizers. It also maintains the state.

.. code-block:: forth

   : interpret
     begin
       parse-name ?dup if drop exit then
       forth-recognizer recognize ( addr len -- i*x r:table )
       state @ if i-cell+ then \ get compile time action
       @i execute ?stack
     again
   ;

:command:`recognize` always returns a valid method table. If no
recognizer succeeds, the :command:`RECTYPE-NULL` is returned with the 
addr/len of the unknown-to-handle word.

API
~~~

Every recognizer has a method table for the interpreter to handle 
the data and a word to check (and convert) whether a string matches
the criteria for a certain data type.

.. code-block:: forth
   
   \ order is important!
   :noname ... ;  \ interpret action
   :noname ... ;  \ compile action
   :noname ... ;  \ postpone action
   rectype: rectype-foo

   : rec:foo ( addr len -- i*x rectype-foo | RECTYPE-NULL ) ... ;

The word :command:`rec-foo` is the actual parsing action of the
recognizer. It analyzes the string it gets. There are two results 
possible: Either the word is recognized and the address of the data
token is returned or the NULL data token is used which is 
actually a predefined method table named :command:`RECTYPE-NULL`.

The calling parameters to :command:`rec-foo` are the address and 
the length of a word in RAM. The recognizer must not change it. 
The result (i*x) is the parsed and converted data and the method
table to deal with it.

There is a standard method table that does not require
additional data (i*x is empty) and which is used to communicate
the "not-recognized" information: :command:`RECTYPE-NULL`. Its 
method table entries throw the exception -13 if called.

Other pre-defined method tables are :command:`rectype-num` to deal 
with single cell numeric data, :command:`rectype-dnum` to work with
double cell numerics and :command:`rectype-xt` to execute, compile 
and postpone execution tokens XT from the dictionary.

The words in the method tables get the output of the recognizer 
as input on the data stack. They are excpected to consume them 
during their work.

Default (NULL)
~~~~~~~~~~~~~~

This is a special system level recognizer. It is
never called actually but its data token (RECTYPE-NULL) 
is used as both a error flag and for the final error 
actions. Its methods get the addr/len of a single 
word. They consume it by printing the string and 
throwing an exception when called. The effect is 
to get back to the command prompt if catched 
inside the :command:`quit` loop.

.. code-block:: forth

   :noname type -13 throw ; dup dup
   rectype: RECTYPE-NULL

   \ this definition is never called actually
   : rec-null ( addr len -- rectype-null)
     2drop rectype-null
   ;

NUMBER
~~~~~~

The number recognizer identifies numeric data in both
single and double precision. Depending on the actual
data width, two different data tokens are returned.

The postpone action follows the standard definitions by
not allowing to postpone numbers. Instead the number is
printed and an exception is thrown.

.. code-block:: forth

   ' noop
   ' literal
   :noname . -48 throw ; \ subject to disput
   recognizer: rectype-num

   ' noop
   ' 2literal
   :noname d. -48 throw ; \ subject to dispute
   recognizer: rectype-dnum

   : rec:intnum ( addr len -- n rectype-num | d rectype-dnum | rectype-null )
     number if
      1 = if rectype-num else rectype-dnum then
     else 
       rectype-null
     then
   ;


FIND
~~~~

This recognizer tries to find the word in the dictionary. If
sucessful, the execution token and the flags are returned. The
data token contains words to execute and correctly deal with
immediate words for compiling and postponing.

.. code-block:: forth

   ( XT flags -- )
   :noname drop execute ; 
   :noname 0> if compile, else execute then ; 
   :noname 0> if postpone [compile] then , ; 
   recognizer: rectype-xt

   : rec-find ( addr len -- XT flags rectype-xt | rectype-null )
     find-name ?dup if
       rectype-xt
     else
       rectype-null
     then
   ;

Multitasking
------------

amforth does not implement multitasking directly. It
provides the basic functionality however. Within IO
words the deferred word :command:`PAUSE` is called 
whenever possible. This word is initialized to do 
nothing (:command:`NOOP`).

.. _ExceptionTable:

Exceptions
----------

Amforth uses and supports exceptions as specified in the
ANS wordset. It provides the :command:`CATCH`
and :command:`THROW` commands. The outermost catch
frame is located at the interpreter level in the word
:command:`QUIT`. If an exception with a negative value is
catched, :command:`QUIT` will print a message with this
number and and re-start itself. Positive values silently
restart :command:`QUIT`.

The next table lists the exceptions, amforth uses itself.

+-----------+---------------------+---------------+
| Exception |         Meaning     | Thrown in     |
+-----------+---------------------+---------------+
|    -1     |  silent abort       | ABORT         |
+-----------+---------------------+---------------+
|    -2     |  abort with message | ABORT"        |
+-----------+---------------------+---------------+
|    -4     |  stack underflow    | ?STACK        |
+-----------+---------------------+---------------+
|   -13     |  undefined word     | rec-notfound, |
|           |                     | tick          |
+-----------+---------------------+---------------+
|   -16     |  Invalid word       | (create)      |
+-----------+---------------------+---------------+
|   -50     |  search order       | SET-ORDER     |
|           |  exhausted          |               |
+-----------+---------------------+---------------+

Memory Allocation
-----------------

The ANS 94 standard defines three major data regions: name space,
code space and data space. The amforth system architecture
maps these  memory types to the built-in ones: Flash, RAM and 
(if available) EEPROM. These three memory types have their own
address space independently from the others. Amforth does not
unify these address spaces into one.

Amforth uses the flash memory as the location for all standard data 
spaces: name, code and data space. Contrary to the standard some 
words that should operate on the data space use RAM adresses instead.  
These words are HERE, @ (fetch), ! (store) and simimliar. Similiarly
the so called transient regions are in RAM as well. 

Other words like , (comma) operate on the flash address and thus
directly in the dictionary.

User Area
---------

The User Area is a special RAM storage area. It
contains the USER variables and the User deferred
definitions. Access is based upon the value of the
user pointer UP. It can be changed with the word
:command:`UP!` and read with :command:`UP@`
. The UP itself is stored in a register pair.

The size of the user area is determined by the size the system
itself uses plus a configurable number at compile time. For self
defined tasks this user supplied number can be changed for task
local variables.

The first USER area is located at the first data address
(usually RAMSTART).

.. _userarea:

+--------------------------+-----------------------------+
| Address offset (bytes)   | Purpose                     |
+--------------------------+-----------------------------+
| 0                        | Multitasker Status          |
+--------------------------+-----------------------------+
| 2                        | Multitasker Follower        |
+--------------------------+-----------------------------+
| 4                        | RP0                         |
+--------------------------+-----------------------------+
| 6                        | SP0                         |
+--------------------------+-----------------------------+
| 8                        | SP (used by multitasker)    |
+--------------------------+-----------------------------+
| 10                       | HANDLER (exception handling)|
+--------------------------+-----------------------------+
| 12                       | BASE (number conversion)    |
+--------------------------+-----------------------------+

The AVR8 and MSP430 support deferred words based in the
USER area.

+--------------------------+-----------------------------+
| 14                       | EMIT (deferred)             |
+--------------------------+-----------------------------+
| 16                       | EMIT? (deferred)            |
+--------------------------+-----------------------------+
| 18                       | KEY (deferred)              |
+--------------------------+-----------------------------+
| 20                       | KEY? (deferred)             |
+--------------------------+-----------------------------+
| 22                       | SOURCE (deferred)           |
+--------------------------+-----------------------------+
| 24                       | >IN                         |
+--------------------------+-----------------------------+
| 26                       | REFILL (deferred)           |
+--------------------------+-----------------------------+

The command line prompt can be changed with the following
defers. More information is in the recipe :ref:`prompts`

+--------------------------+-----------------------------+
| 28                       | .OK  (deferred)             |
+--------------------------+-----------------------------+
| 30                       | .ERROR (deferred)           |
+--------------------------+-----------------------------+
| 32                       | .READY (deferred)           |
+--------------------------+-----------------------------+
| 34                       | .INPUT (deferred)           |
+--------------------------+-----------------------------+



The User Area is used to provide task local
information. Without an active multitasker it
contains the starting values for the stackpointers,
the deferred words for terminal IO, the BASE
variable and the exception handler.

The multitasker uses the first 2 cells to store the
status and the link to the next entry in the task
list. In that situation the user area is/can be seen
as the task control block.

The size available to application programs is determined
at compile time. This size is set to 0 initially, can be
changed in the application master file.
