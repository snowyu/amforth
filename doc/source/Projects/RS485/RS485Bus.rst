
====================
Nodes on a RS485 Bus
====================

    :Author: Erich Wälde
    :Contact: amforth-devel@lists.sourceforge.net
    :Date: 2015-04-19

.. contents::

1 Abstract
----------

The cookbook style recipes presented below are interconnected by the
desire to create a solution connecting several controller nodes together
by rs485 network for periodic data collection. A few decisions have been
taken upfront:

* The rs485-bus is wired up as "simplex" (not duplex).
* There is exactly one node on the rs485 network acting as bus-master (the
  data collecting Linux system) and initiating any data transfer.
* Every node has to exlicitly switch its bus transceiver to "send" mode
  when writing data onto the bus.
* There must be a means to address one node whereas all the other nodes
  must remain silent.

Substantial parts of this solution were inspired or recycled from a project
published by Lubos Pekny.

The author is running a set of currently 5 data collecting controller
nodes on one rs485 bus for several years now. The code provided stable
operation so far.

For this article the author decided to "redo everything" in plain
amForth, well almost everything, as it turned out.



2 Motivation: The Project "collector"
-------------------------------------

When starting with microcontrollers years ago I needed to do something
with them, that looked useful at least to me. So very soon I started to
deal with sensors to measure temperature, pressure, and humidity of
air. The classical "weather station" project. This worked, but soon I
wanted to have the values not only displayed but rather collected ---
some day nice graphs would be interesting, or so I thought. So I
connected a small single-board-computer [1] to the only one controller
with a serial cable. This worked for a long time.

Later I had the idea to collect temperatures at other points in the
house as well. I could have added more sensors and long cables to the
only one controller, but instead I decided to add another controller at
the end of a long cable. Now I needed a way to talk to two (or more)
controllers connected "somehow" the the single board computer. I could
have added more serial interfaces, one for each controller, but I
didn't like the idea. Instead I decided to connect two (or more)
controllers via one long cable using the RS485-Bus specification.

The RS485-Bus is an electrical specification. A (possibly twisted) pair
of wires is used to connect two nodes. The signal is differential, the
difference in potential between the two wires is used as information.
That way the whole setup is fairly immune against noise, as this
normally adds the same shift in potential to both wires. The standard
is good for a distance up to 1200 m, but should work much longer
distances with slow data rates and proper termination.


In order to exchange information on the RS485-bus the same timing and
encoding is used as on a normal serial interface (RS232). The idle
levels are interpreted as 1, the first bit is the start bit and always
0, then 8 data bits follow, and then one or more stop bits are sent.
The stop bits are also 1 and correspond to the idle levels. So there is
nothing new here. 

However, if several nodes are on the bus, to which one am I talking?
And if it is the wrong one, how do I "address" the correct one? In
order to distinguish addresses (or control bytes) from ordinary data,
some agreement has to be established, for example

* Bytes with the most significant bit set are treated as addresses or
  control bytes

* Bytes with the most significant bit cleared are treated as ordinary
  data

If the bytes ``0x00 .. 0x7f`` (the lower half of the ascii table) are
sufficient for all data exchange, then 8 data bits are still good. If
not, 9 data bits can be used in many cases. AVR controllers provide
that possibility. There is a project using 9bit communication on Linux
as well (uLan), Links section.

In my case I decided to transfer all information as ascii strings, e.g.

.. code-block:: none

   7F01:8,22.40,22.87,23.24

where ``7F`` is the station address (stationID) in hex, ``01`` is the
sensor number on that node (also in hex), and after the colon a list of
4 numerical values, their precise meaning being entirely irrelevant at
this point. The main advantage is that I can just read everything on
the bus in clear with little technical overhead.

Currently I run a set of 5 controllers with a variety of sensors:

* temperature and humidity (indoors and outdoors), pressure of air
* voltage of an accumulator providing power to a remote system
* distance (ultrasonic range finder) which translates to the amount of
  water in a tank
* counts of meters (electricity, water, natural gas)

The "collector" is a perl script running on the single board computer
and collecting the data from the controllers every 2 or 10 minutes.
This program acts as the bus master, the other nodes do not initiate
any data exchange. The data is then accumulated in a sqlite database.
A "viewer" perl script will then produce graphs of selected values over
time. Other options are possible, of course.


3 Hardware Requirements
-----------------------

All controller nodes need to have a RS485-transceiver. The transceiver
needs 3 connections to the controller:

1. TX --> Data Out

2. RX <-- Data In

3. Port D7 --> Write/Read select (idle = read = low)

.. figure:: p_rs485_bus.png


An RS232 -- RS485 converter of some sort is needed to connect the
serial interface of the collector computer to the bus. USB -- RS485
dongles are available as well. Please note, that the connector should
not produce a local echo of the bytes transmitted, or software needs to
take care of the double echo. The controllers are sending an echo
character as well, this serves as handshake when uploading forth code,
too.

Power supply can be local to any node, but serving power on 2 more
wires is also possible. When having long cables +12V supply voltage and
step down converters on every board seem like a good idea.

4 Software Requirements
-----------------------

1. Any node should be quiet and not write anything to the bus unless
   explicitly requested to do so. This explicit request translates into
   some sort of addressing. Preventing any output is most easily
   achieved by changing ``emit``.

2. Bytes ``0x00 .. 0x7f`` are considered *normal* data, bytes
   ``0x80 .. 0xff`` are considered adresses (or control bytes).

3. every node needs to have an address or stationID assigned

4. The controllers make use of the so called multi processor
   communication (MPC) mode to ignore traffic between other nodes
   already in hardware.

5. a write operation to the bus must assert the W/R pin to write before
   transmission.

6. Upon completion of the (asynchronous) data transmit the W/R pin has
   to be released, e.g. automatically by using the transmit complete
   interrupt.

7. The implementation should be in Forth entirely. A few exceptions
   showed up during implementation.

8. If a node is power cycled, nothing weird should happen on power up.
   Especially nothing should be written to the bus at all.

9. a modified prompt shall include the address (stationID) of the node
   at the other end of the communication. This is solely to provide
   immediate visible feedback, it is not needed for proper
   communication.

10. While experimenting it turned out that sometimes more than one
    controller is in normal mode. They will produce what I call "echo
    loops". The output (mostly error messages) of one node will trigger
    more output (error messages) of the other node. I decided to
    implement harsh measures: whenever command line will produce an
    error message, then instead put the node back to quiet mode.



5 Implementation Plan
---------------------

In order to achieve the above goals, a set of mutually independant
things were implemented.

1. :command:`stationID`, prompts

   This is to satisfy requirements 3 and 9. The code is fairly simple,
   even short.

   :command:`stationID` is an eeprom backed value with a cache place in RAM.

   The prompt itself is produced by :command:`.ready`. This is a deferred
   word and therefore can be overridden easily by another
   function. So we implement a new function :command:`p_id_rd` which will 
   then be registered into the deferred function :command:`.ready`.

2. :command:`-emit` / :command:`+emit`

   In order to prevent **any** output from the controller, I chose to make
   :command:`emit` point to :command:`drop` rather than :command:`tx`.
   :command:`-emit` will take care of this. This word will be called in the
   next part at startup time.

3. rs485 read/write pin handling

   One pin on the controller has to be selected to drive the read/write-pin of
   the transceiver. The idle state should be low (`0`) or `read`, which is
   achieved by a pull-down resistor.

   - provide constants to declare the selected pin

   - switch the pin to output on startup

   - set the pin to write (`1`) before transmission

   - release the pin to read (`0`) upon completion. Use the transmit
     complete interrupt to achieve this.

   We can now write to and read from the RS485 bus. We can handle only
   one controller so far.

4. mpc --- multi processor communication

   This is the most complex part.

   - set quiet mode
     set the serial interface to `7N2` (7 data bits, no parity bit, 2
     stop bits), set the `MPCM0` bit in register `UCSR0C`

   - when receiving a byte with the most significant bit set, inspect the
     byte and decide whether this is the local address or not

   - if not, remain in quiet mode

   - if yes, then switch the serial interface to normal mode (`8N1`) and
     handle all incoming data

   - set normal mode:
     set the serial interface to `8N1`,
     clear the `MPCM0` bit in register `UCSR0C`

   It turned out that the function :command:`usart_rx_isr` is implemented
   in assembly and registered as a *low* level interrupt service routine
   (ISR). This prevents overriding the registered interrupt service routine
   with another function. I decided to change this and make
   :command:`usart_rx_isr` a forth level routine (assembly change 2) and
   register it as a *high* level interrupt. This way the ISR can be
   replaced by some other function.

   Unsurprisingly replacing the ISR needs explicit access to the ring
   buffer that the original ISR is using. It is accessed by :command:`key`
   as well and should not change. So I added forth level headers to make
   the space in RAM available as forth constants/variables (assembly
   change 3)

5. recognizer: go quiet if command not found

   amForth provides recognizers. There is a list of them, which can be
   changed. The first in the list is :command:`rec:word`, it will try to
   find the token in the word list. If it fails, the next one in the list
   is called: :command:`rec:num`. It will try to parse the input token as a
   number. If it fails the list is exhausted and the final
   :command:`r:fail` will be called to issue an error message and do some
   cleanup.

   I decided to add a third recognizer to the end of the list named
   :command:`rec:quiet`. It will not parse the input token again, but clean
   up the arguments. Then it will set the controller to quiet mode (call
   :command:`-emit` :command:`+mpc7`) and signal success rather than error.
   This way the pointer in :command:`r:fail` is not called.

6. startup / turnkey

   In the end all of the above things need to be put together to ensure
   correct startup and initialization of all parts involved. Pay
   attention to turnkey and power cycle.


6 Code
------

This code was re-developed and tested on an atmega644p running amForth
5.5.

6.1 start
~~~~~~~~~

The remainder of this article assumes that we have a working setup
derived from the

.. code-block:: none

  amforth/releases/5.5/appl/template


directory. Set appropriate values for the controller type, crystal
frequency, and baud rate to appropriate values for your board.

- Makefile

  .. code-block:: none

    MCU=atmega644p

- main.asm

  .. code-block:: none

    .equ F_CPU = 11059200
    .set BAUD=115200

Now we are at the point where the controller should talk to us on the
serial interface using a terminal program, e.g. minicom:

.. code-block:: none

  Welcome to minicom 2.7
  
  OPTIONS: I18n 
  Compiled on Jan  1 2014, 09:30:18.
  Port /dev/ttyUSB1, 16:46:00
  
  Press CTRL-A Z for help on special keys
  
  amforth 5.5 ATmega644P
  > 

6.2 changing the prompts
~~~~~~~~~~~~~~~~~~~~~~~~

With the release 6.3 and newer the appearance of the prompt can be changed if we
so desire:

.. code-block:: forth

   amforth 6.3 ATmega644P
   > variable (p_rd)
   ok
   > ' .ready defer@ (p_rd) !
   ok
   > : new_p_rd  cr ." --new> " ; 
    ok
   > ' new_p_rd is .ready
    ok
   --new> 1 3 + .
   4  ok
   --new> (p_rd) @ is .ready
    ok
   > 


This will be used in the next step to display the content represented by
:command:`stationID` in the ready-prompt.

6.3 stationID
~~~~~~~~~~~~~

:command:`StationID` is a value, permanently stored in EEPROM and copied
to a RAM location on startup. So we need to load the appropriate
word :command:`Evalue`:

.. code-block:: forth

  include lib/forth2012/core/value.frt


After that we are able to create a value, the content of which is
backed in EEPROM:

.. code-block:: forth

  $007f Evalue stationID


With this in place we are now in a position to create a new function
implementing a new prompt. In order to make it always look the same (two
digits, leading zeros) we add the word :command:`u0.r` to the dictionary in
``dict_appl.inc`` (please note the leading dot and the quotes, since this
is assembly syntax):

.. code-block:: none

  .include "words/uzerodotr.asm"

reassemble and reflash amForth. Then define the new word :command:`p_id_rd`

.. code-block:: forth

  : p_id_rd
    cr
    base @
    hex
    [char] ~ emit
    stationID 2 u0.r
    [char] > emit
    space
    base !
  ;


We should also take care to save and restore the content of
:command:`base`, since I decided to print out the value of
:command:`stationID` in hexadecimal. Using the new things should work like
this:

.. code-block:: none

  amforth 6.3 ATmega644P ok
  > stationID decimal .
  127  ok
  > p_id_rd
  
  ~7F>  ok
  > ' p_id_rd is .ready
   ok
  ~7F> $42 to stationID
   ok
  ~42> 



The value ``$007F`` is the highest address available for the above
mentioned 7-bit addressing scheme, so I chose it as the default. The exact
value can be changed here or overwritten later when loading the code with
something like

.. code-block:: forth

   $42 to stationID


6.4 emit-on-off
~~~~~~~~~~~~~~~

In order to prevent the controller from writing to the rs485 bus **unless**
explicitly requested, I decided to defer :command:`emit` to :command:`drop`
just to make sure. This requires two fairly simple words

.. code-block:: forth

  variable old-emit
  ' emit defer@ old-emit !
  : -emit
    ['] emit defer@ old-emit !
    ['] drop is emit
  ;
  : +emit
    old-emit @ is emit
  ;


After loading the code we can test this:

.. code-block:: forth

  amforth 6.3 ATmega644P ok
  ~42> 
  ~42> : hi ." howdy, mate!" cr ;
   ok
  ~42> hi
  howdy, mate!
   ok
  ~42> -emit hi +emit
   ok


6.5 adding rs485 r/w handling
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In order to drive the rs485 transceiver, we need to implement the
following things:

1. select W/R pin

This pin needs to be selected, initialized as output and set to
low.

.. code-block:: forth
 
     $2B constant RS485_PORT         \ memory mapped
     $2A constant RS485_DDR          \ .
     $80 constant RS485_PIN_MASK
     : rs485-pin-output
       RS485_DDR c@ RS485_PIN_MASK or RS485_DDR c!
     ;

Of course the functions in ``lib/bitnames.frt`` could be used as well,
but for the argument of smaller dependencies, I decided to implement
this directly.


2. set W/R pin high (write) or low (read)

Two simple functions will do this:

.. code-block:: forth

     : rs485-write
       RS485_PORT c@ RS485_PIN_MASK or RS485_PORT c!
     ;
     : rs485-read
       RS485_PORT c@ RS485_PIN_MASK invert and RS485_PORT c!
     ;


3. set W/R pin to `write` (`1`) before sending a byte

   Before sending any byte, we need to set the W/R pin high. So we
   reimplement :command:`tx-poll`, the function that transfers one byte to
   the serial interface.

   .. code-block:: forth

     $C6 constant UDR0 \ usart0 data register
     : rs485-tx-poll ( c -- )
       begin  tx?-poll  until
       rs485-write
       UDR0 c!
     ;
   

4. release W/R pin upon transfer completion

   After sending the byte, the W/R pin should be released to zero.
   This happens `some` time after initiating a transfer. However, the
   Atmel engineers have anticipated this problem and provided the
   `transfer complete` interrupt for our convenience.

   .. code-block:: forth

     : tx-complete-isr
       RS485_PORT c@ RS485_PIN_MASK invert and RS485_PORT c!
     ;
     
     $2C  constant USART0__TXAddr \ USART0, Tx Complete
     $40  constant UCSR0B_TXCIE0
     $C1  constant UCSR0B
     : +rs485
       rs485-pin-output
       rs485-read
       ['] tx-complete-isr USART0__TXAddr int!
       ['] rs485-tx-poll is emit
       UCSR0B c@ UCSR0B_TXCIE0 or UCSR0B c!
     ;
     : -rs485
       ['] noop USART0__TXAddr int!
       ['] tx-poll is emit
       UCSR0B c@ UCSR0B_TXCIE0 invert and UCSR0B c!
     ;


   The functions :command:`+rs485` and :command:`-rs485` enable and disable
   the whole rs485 bus connection. Apart from changing the deferred word
   :command:`emit` and registering the interrupt service routine to the
   `transfer complete interrupt`, the interrupt itself must be enabled in
   the register ``UCSR0B``.


At this point we have everything in place to connect to the controller via
the rs485 bus. :command:`+rs485`` needs to be called during startup, which
is the only missing piece at this point.


6.6 mpc 1: making `usart_rx_isr` a forth level word
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

While working on this particular implemention of my code, namely
reimplementation in as much Forth code as possible, I came across a
subtle feature of the amForth implementation (as of version 5.5).
Interrupt handling in amForth is twofold: the low level part (written
in assembly) is basically doing the bookkeeping, clearing the
interrupt and then calling into a amForth table of registered
functions. This provides the possibility to write interrupt service
routines (ISR) in `high level` Forth rather than assembly. Registering
your own ISR is a matter of one line:

.. code-block:: forth

  ' your-own-isr  Interrupt-Vector-Addr  int!


6.6.1 replace `usart_tx_isr` with a Forth word
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This part is not particularly difficult, because a Forth equivalent
is found already as a comment in the asm file.

.. code-block:: forth

   ; forth code:
   ; : rx-isr USART_DATA c@
   ;    usart_rx_data usart_rx_in c@ dup >r
   ;    + !
   ;    r> 1+ usart_rx_mask and usart_rx_in c!
   ; ;
   ; setup with
   ; ' rx-isr URXCaddr int!


I kept the name, but please note that it does not refer to the asm label
any more --- :command:`usart_rx_isr` is now a proper Forth word.


6.6.2 register the new function as ISR
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The new function must be registered somewhere in the startup of amForth,
because otherwise there will be no access to the command loop via the
serial interface. So in function :command:`applturnkey` we add the
equivalent of

.. code-block:: forth

  ' usart_rx_isr  USART0__RXAddr  int!


just before globally enabling interrupts.

.. code-block:: asm

    ; ( -- ) System
    ; R( -- )
    ; application specific turnkey action
    VE_APPLTURNKEY:
        .dw $ff0b
        .db "applturnkey",0
        .dw VE_HEAD
        .set VE_HEAD = VE_APPLTURNKEY
    XT_APPLTURNKEY:
        .dw DO_COLON
    PFA_APPLTURNKEY:
        .dw XT_USART

        ; register usart_rx_isr
        .dw XT_DOLITERAL            ; ' usart_rx_isr URXCaddr int!
        .dw XT_USART_RX_ISR
        .dw XT_DOLITERAL
        .dw URXCaddr
        .dw XT_INTSTORE

        .dw XT_INTON
        .dw XT_VER
        .dw XT_EXIT


Assembling amForth and programming the controller with these changes
must result in an equally usable system as it was before.


6.7 mpc 2: adding mpc after all
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Entering MPC mode in this case means configuring the serial interface
to `7N2` (7 data bits, no parity bit, 2 stop bits) and setting the
``MPCM0`` bit in register ``USCR0A``.

In that mode, if a data frame is received with the most significant
bit cleared (0), the the data frame is silently ignored.

In that mode, if a data frame is received with the most significant bit set
(1), then the data frame shows up in register ``UDR0``, the data register
of the serial interface. An interrupt is generated and the corresponding
ISR is called.

All nodes on the bus will inspect the just arrived address byte. If the
value of the address byte is the same as the configured node address (also
known as :command:`stationID`), only then the serial interface is
reconfigured to `8N1` and the ``MPCM0`` bit is cleared. This node is then
*awake* from a communication point of view. It will receive all following
data frames and is expected to act on them.

All other nodes on the bus will keep the `7N2` mode of the serial
interface and remain *silent* from a communication point of view.

The *awake* state will not end and must be changed explicitly.

Things that need to be done are

1. provide a few definitions for readability (recycled from
   ``devices/$(MCU)/$(MCU).frt`` --- make sure to load the correct file
   for your controller!)

   .. code-block:: forth

     $2C  constant USART0__TXAddr \ USART0, Tx Complete
     $28  constant USART0__RXAddr \ USART0, Rx Complete
     $40  constant UCSR0B_TXCIE0
     $C0  constant UCSRA \ UCSR0A, really
     $10  constant UCSRA_FE0          \ frame error
     $08  constant UCSRA_DOR0         \ data over run
     $04  constant UCSRA_UPE0         \ parity error
     $01  constant UCSRA_MPCM0        \ mpc mode enabled
     $C1  constant UCSR0B
     $C2  constant UCSRC
     $C6  constant UDR0


2. waiting for the currently active transfer to complete (reusing
   definitions from the rs485 section above)

   .. code-block:: forth

     : txc  begin  RS485_PORT c@  RS485_PIN_MASK  and 0= until ;


   This is needed whenever we want to switch to mpc mode. Without
   waiting we will destroy any ongoing transmit.

3. enabling MPC mode (`7N2`)

   .. code-block:: forth

     : +mpc7
       txc
       $0C UCSRC c!                      \ 7N2
       UCSRA c@ $01 or UCSRA c!          \ MPCM0=1
     ;


4. disabling MPC mode (`8N1`)

   .. code-block:: forth

     : -mpc7 (  --  )
       UCSRA c@ $01 invert and UCSRA c!  \ MPCM=0
       $06 UCSRC c!                      \ 8N1
     ;


5. access to the RX data ring buffer

   Handling incoming data unfortunately requires access to the
   variables of the rx ring buffer, which are not readily available in
   forth. In a local copy of ``drivers/usart-isr-rx.asm`` we add
   appropriate provisions. The existing declaration of the used RAM
   space and sizes

   .. code-block:: asm

     ; sizes have to be powers of 2!
     .equ usart_rx_size = $10
     .equ usart_rx_mask = usart_rx_size - 1
     .dseg
     usart_rx_data: .byte usart_rx_size+2
     usart_rx_in:   .byte 2
     usart_rx_out:  .byte 2
     .cseg


   will be made available as amForth constants and variables.

   .. code-block:: forth

     \ variable USART_RX_DATA N allot \ &buffer[0]
     \ variable USART_RX_IN           \ index
     \ N 1- constant USART_RX_MASK    \ length-1, length=2^n
     
     ; ( -- value ) constant USART_RX_DATA
     VE_USART_RX_DATA:
         .dw $FF0D
         .db "USART_RX_DATA",$00
         .dw VE_HEAD
         .set VE_HEAD = VE_USART_RX_DATA
     XT_USART_RX_DATA:
         .dw PFA_DOVARIABLE
     PFA_USART_RX_DATA:
         .dw usart_rx_data
     
     ; ( -- addr ) variable USART_RX_IN
     VE_USART_RX_IN:
         .dw $ff0b
         .db "USART_RX_IN",$00
         .dw VE_HEAD
         .set VE_HEAD = VE_USART_RX_IN
     XT_USART_RX_IN:
         .dw PFA_DOVARIABLE
     PFA_USART_RX_IN:
         .dw usart_rx_in
     
     ; ( -- value ) constant USART_RX_MASK
     VE_USART_RX_MASK:
         .dw $FF0D
         .db "USART_RX_MASK",$00
         .dw VE_HEAD
         .set VE_HEAD = VE_USART_RX_MASK
     XT_USART_RX_MASK:
         .dw PFA_DOVARIABLE
     PFA_USART_RX_MASK:
         .dw usart_rx_mask


   This provides the words :command:`USART_RX_DATA` :command:`USART_RX_IN`
   :command:`USART_RX_MASK` for our usage. Alternately we could setup our
   own variables and replace :command:`rx-isr` with a version looking at
   them.

6. handling an incoming byte according to MPC-mode

   .. code-block:: forth

       UCSRA_FE0
       UCSRA_DOR0  or
       UCSRA_UPE0  or constant UCSRA_RX_ERR
       : mpc?     UCSRA c@  UCSRA_MPCM0 and ;
       : rx-err?  UCSRA c@  UCSRA_RX_ERR and ;
       : rx-store ( udata -- )
         USART_RX_DATA USART_RX_IN c@  dup >r
         + !
         r> 1+ USART_RX_MASK and USART_RX_IN c!
       ;
       : mpc-rx-isr
         rx-err? 0= if
           UDR0 c@             \ -- udata
           mpc? if
             stationID = if
               -mpc7
             then
           else
             rx-store
           then
         then
       ;


   The new word command:`mpc-rx-isr` will inspect incoming data according
   to whether we are in MPC mode or not. It requires the node address in
   the value :command:`stationID` as defined before.

7. string everything together

   In order to use all of the above we basically need to switch it on
   (and off):

   .. code-block:: forth

     : +rs485.mpc
       ['] prompt_rd is p_rd         \ overwrite p_rd
       +rs485
       ['] mpc-rx-isr USART0__RXAddr int! \ overwrite usart_rx_isr
       -emit
       +mpc7
     ;
     
     : -rs485.mpc
       ['] (p_rd) is p_rd
       ['] usart_rx_isr USART0__RXAddr int!
       -rs485
       -mpc7
       +emit
     ;


   When using this in a turnkey word, make sure to disable :command:`emit`
   before calling the original word :command:`applturnkey`, because
   otherwise the output of :command:`ver` will be written to the bus.

   .. code-block:: forth

     : run-turnkey
       -emit
       applturnkey
       +rs485.mpc
     
       \ more initialization here
     
     \ begin
     \   your periodic work goes here
     \ again
     ;


We are all ready to go. Please note that you need some means to send
``0x80 | 0xStationAddress`` to the bus to address the desired node. Once
connected you need to issue :command:`+emit`, and only after that the
ok-prompt will show up.


6.8 going to quiet mode on unparsable input
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

After everything worked thus far I found out, that sometimes more than
one controller on the bus will be *awake* receiving data and acting on
it. Most of the time this would result in error messages being sent to
the bus, which in turn will create another round of error messages. I
called this *the echo loop*. I did not find out, what really caused
this behaviour, but instead I decided: whenever a node receives
*illegible* input that cannot be handled properly, the node shall
return to mpc *quiet* mode and not write any error messages at all.

The desired behaviour is a fairly fundamental change to the command
loop, however, it is easy to install thanks to the availability of
recognizers.

Any input will be parsed by a list of recognizers, the first to
*understand* the input will trigger the corresponding work. The last in the
list will be the one to possibly issue an error message. So we create a new
recognizer and insert it into the list of recognizers before the one
issueing error messages.

First we need to load the word :command:`recognizer:`

.. code-block:: forth

  include lib/recognizer.frt


After that we create a table holding 3 execution tokens. The first is
to be called at runtime, the second at compile time, and the third
during a postpone operation.

.. code-block:: forth

  :noname -emit +mpc7 ;    \ at runtime call the equivalent of ~end
  ' noop                   \ nothing to do at compile time
  :noname type -48 throw ; \ postpone would be an error
  recognizer: r:quiet


The parsing word does basically nothing. If this recognizer is called,
:command:`rec:word` and :command:`rec:num` have not been able to handle the
input. So we simply drop the references to the unhandled input before the
call into an entry of the newly created table :command:`r:quiet`.

.. code-block:: forth

  : rec:quiet  ( addr length -- t/f ) drop drop r:quiet ;


Registering and deregistering the new recognizer is a little involved,
because we want to place it at the last position --- if the last
recognizer fails, the content of r:fail is called. After some
fiddling, I decided to compare the last value with the one to be
inserted or removed, such that repeated calls to "+rec:quiet" or
"-rec:quiet" will not cause a problem.

.. code-block:: forth

  : +rec:quiet
    ['] rec:quiet         \ -- r0
    forth-recognizer get-recognizers       \ -- r0 r1 r2 2
    dup pick              \ -- r0 r1 r2 2 r1
    ['] rec:quiet <> if   \ -- r0 r1 r2 2
      1+
      forth-recognizer set-recognizers
    else
      drop
    then
  ;

  : -rec:quiet
    forth-recognizer get-recognizers       \ -- r0 r1 r2 3
    dup pick 
    ['] rec:quiet = if
      1- forth-recognizer set-recognizers drop
    else
      0 ?do drop loop
    then
  
  ;


:command:`+rec:quiet` needs to be called in :command:`+rs485.mpc` and
similar for :command:`-rec:quiet`.

.. code-block:: forth

  $28 constant USART0__RXAddr
  : +rs485.mpc
    ['] prompt_rd is p_rd         \ overwrite p_rd
    +rs485
    ['] mpc-rx-isr USART0__RXAddr int! \ overwrite usart_rx_isr
    +rec:quiet
    -emit
    +mpc7
  ;
  
  : -rs485.mpc
    ['] (p_rd) is p_rd
    ['] usart_rx_isr USART0__RXAddr int!
    -rec:quiet
    -rs485
    -mpc7
    +emit
  ;


6.9 turnkey
~~~~~~~~~~~

We are done. We can now put this together in a function to be called at
system boot. The controller will immediately switch off any output and go
to *quiet* mpc mode. As such the controller will behave well on a bus
with possibly other nodes.

.. code-block:: forth

  : run-turnkey
    -emit
    applturnkey
    +rs485.mpc
  ;


Please note that :command:`-emit` must be called before
:command:`applturnkey`, because the later does call :command:`ver`
producing the well known output

.. code-block:: none

  amforth 6.3 ATmega644P ok

or similar. But we do **not** want to write anything on the bus unless
explicitly asked to do so.



7 creating a node
-----------------

While the above implementation is *complete*, it may not be obvious,
how to create a sensor node with all the required bits around it. So at
least the description of a working example seems needed.

In my case the ``collector`` is a perl script, which will periodically
address a list of nodes and for each of these

- write the address byte ``0x80 | addr`` to the bus

- write :command:`+emit` after that (no echo characters expected)

- wait for the ok prompt

- write :command:`~data` to the bus (waiting for each echo character, since
  those are coming from the controller now)

- read all the characters which come as an answer, e.g.

  .. code-block:: none

    __Q 42:0005 4200:0  4201:0  4202:0  4203:0 C-- ok

  or

  .. code-block:: none

    __Q 7F:0005 7F01:3,+19.50,+19.50,+19.50  7F02:3,514,516,518 C-- ok


- write :command:`~end` to the bus (again waiting for each echo character)

The answer string is then parsed into pieces, and individual
measurements are then inserted into a database table.

The ``__Q`` and ``C--`` tokens were inserted only to make parsing simpler.
The second token consists of ``stationID:softwareVersion``, both as a hex
number. Tokens after that are either ``sensorID:Counter`` or
``sensorID:N,xlow,xmean,xhigh`` collections. Other formats are certainly
possible, this is just my choice based on the decision *its all plain ascii*.


This represents the *high level* view of the node as seen from the
*network* (aka bus).
So the words

- :command:`+emit`

- :command:`~data`

- :command:`~end`

must be available on the node.

So there are at least two ways to make :command:`~data` report meaningful output.

1. interrupt only sensors

   If all sensors can be handled by appropriate interrupt service routines,
   those shall fill the variables with meaningful values. :command:`~data`
   will then only read those values and report them over the bus.

   This setup is used for counters or *meters*. In my case the
   electricity meter has a so called `S0` interface with two pins ``+``
   and ``-``. ``+`` must be pulled high by a pullup resistor and connected
   to a controller pin. The meter will short the ``+`` to the ``-`` pin for
   a few milliseconds thus reporting one *count*. If the pin at the
   controller either can react on such a pulse by issueing an interrupt
   (external or pin change interrrupt) or if the pin is connected to a
   counter register, that's all there needs to be done. Every low pulse
   will increment the value reported by :command:`~data`.

.. figure:: p_S0_interface.png

2. using the multitasker to do the work in the background

   If there is more work to be done, either on event or periodically,
   then using the multitasker is an option. There are only two tasks
   involved: the task serving the command line and the task
   periodically collecting sensor readouts into variables. The handling
   of sensors or events could be spread over more tasks, if needed for
   some reason.

   If :command:`~data` is called on the command line, it will report the
   stored values and optionally reset the variables.


7.1 counter sensor
~~~~~~~~~~~~~~~~~~

As an example I will outline the needed bits for a counter node. It
will count *active-low* pulses on one of 4 pins. The controller is an
atmega168, which features *pin-change-interrupts* on all port pins. The
pulses are produced by an electricity meter with a so called `S0`
interface. This particular electricity meter will produce 1000 counts
per kWh consumed, each count consists of pulling pin ``+`` down for
90 milliseconds.


The pin change interrupt will trigger on falling and rising edges.
There is only one interrupt for a group of eight pins (one port). So
the interrupt service routine needs to find out, which pin exaclty
triggered the interrupt, and whether a falling or rising edge did
occur. On the falling edge we need to increment the associated counter
for this pin.

.. code-block:: forth

    \ --- data handling -------------------------
    variable Count 4 cells allot
    variable Pins_old
    : pci1_isr
      ledsensor high
      PINC c@ $0F and       \ -- pins 
      Pins_old c@           \ -- pins alt
      over                  \ -- pins alt pins
      xor                   \ -- pins diff
      dup if                \ -- pins diff

        4 0 do                          \ for each (consequtive input) pin
          dup  1 i lshift  and if       \ . bit one changed?
            over  1 i lshift  and 0= if \ . leading edge?
              1  Count i cells +  +!    \ . increment
            then
          then
        loop

      then
      ( diff ) drop
      ( pins ) Pins_old c!
      ledsensor low
    ;
    : +pci1
      $0F PCMSK1 c!  \ pcint 8..11 active
      $02 PCICR  c!  \ pci1 active
      $02 PCIFR  c!  \ clear PCI1, just in case
      PINC c@ $0F and  Pins_old !
      ['] pci1_isr PCINT1Addr int!
    ;
    : -pci1
      $00 PCICR  c!
      $02 PCIFR  c!  \ clear PCI1, just in case
     ;

The function :command:`~data` will then read the counter and report the value
found as a plain ascii string on the serial interface. No provisions
are taken to implement any access locking, reading the two bytes of
the counter might result in inconsistent values.

.. code-block:: forth

    \ counters are expected signed. A rollover can then be detected
    \ and distinguished from restart of the controller.
    \ therefore '.' not 'u.' in data.ls
    : data.ls
      4 0 do
        space stationID @ >< i + &4 hex u0.r colon  Count i cells + @ decimal .
      loop
    ;  
    : ~data
      leddata high     \ fixme: leddata

      ." __Q"       \ datagram start
      .id+ver       \ stationID + swVersion
      data.ls
      ." C--"       \ datagram end 
      leddata low
    ;

Since data is updated using an interrrupt service routine only, the
available command loop is available to service any requests from the
rs485--serial connection. If work has to be done outside the interrupt
service routine, a multitasker can be used to run two tasks: one to
read and process sensor data, and another one to run the command loop.



8 The *somtimes-not-so-obvious* things
--------------------------------------

As one of my lecturers kept saying: `**Afterwards** everything is obvious`.
However, the path to obviousness can be long and windy at times. 

1. Always provide a jumper to optionally disconnect the RX pin of the
   transceiver, IF you want to keep the existing RS232 transceiver
   working.

2. Consider adding jumpers to disconnect the bus. This is occasionally
   useful.


There is probably more to be said ...



9 Finally
---------

Like always this work would not have been possible without substantial
help from others. Special thanks go to Matthias Trute for amForth, for
providing valuable feedback and picking up suggestions; Lubos Pekny for
proving, that it can be done; the members of the amforth-devel mailing
list, the weekly IRC round and of the German "Forth Gesellschaft e.V.";
countless authors of documentation, code, or processes for all the
countless pieces of software that comprise my workstation setup, e.g.
bash, emacs and perl to name just three.


10 References
-------------

1. net4801 single board computer running the collector

   - `http://www.soekris.com <http://www.soekris.com>`_

2. Lubos Peknys `mFC` project using rs485 and mpc mode highly inspired this
   code and project

   - `http://www.forth.cz <http://www.forth.cz>`_

3. Pavel Pisa, implementing a 9-bit microLAN

   - `http://cmp.felk.cvut.cz/~pisa/papers/pi-ulan-prot.pdf <http://cmp.felk.cvut.cz/~pisa/papers/pi-ulan-prot.pdf>`_
   - `http://ulan.sourceforge.net/ <http://ulan.sourceforge.net/>`_
