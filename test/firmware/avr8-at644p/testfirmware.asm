; This is a template for an amforth project.
;
; The order of the entries (esp the include order) must not be
; changed since it is very important that the settings are in the
; right order
;
; note: .set is like a variable, .equ is like a constant
;
; first is include the preamble. It contains macro definitions,
; default settings and mcu specific stuff like register names.
; The files included with it depend on the -I order of the
; assembler.

.include "preamble.inc"

; The amforth code is split into two segments, one starting
; at address 0 (the RWW area) and one starting in
; the NRWW region. The latter part cannot be changed
; at runtime so it contains most of the core system
; that would never be changed. If unsure what it
; means, leave it as it is. This address may be
; adjusted to give room for other code fragments (e.g.
; bootloaders). The amforth code will start here and may
; occupy all space until flash-end.

; If you want leave out the first 512 bytes of the NRWW section
; for e.g. a bootloader change the line to
; .equ AMFORTH_RO_SEG = NRWW_START_ADDR+512/2
; note the /2 since the flash is 16bit per address
; default is the whole NRWW section
; .equ AMFORTH_RO_SEG = NRWW_START_ADDR

.set AMFORTH_RO_SEG = NRWW_START_ADDR

; amforth needs two essential parameters: CPU clock
; and command terminal line.
; cpu clock in hertz, 1MHz is factory default
.equ F_CPU = 11059200

; terminal settings
; check http://amforth.sourceforge.net/TG/recipes/Usart.html
; for further information

; serial line settings. The defaults are set in avr8/preamble.inc.
; You should not change that file but use your own settings *here*
; since it may get changed in future versions of amforth.
.set BAUD=115200
;.set BAUD_MAXERROR=10
;.set WANT_ISR_RX = 1 ; interrupt driven receive
;.set WANT_ISR_TX = 0 ; send slowly but with less code space

; define which usart to use.
.include "drivers/usart_0.asm"


; now define your own options, if the settings from
; the files included above are not ok. Use the .set
; instruction, not the .equ. e.g.:
;
; .set WANT_XY = 1
;
; there are many options available. There are two
; places where they are defined initially: core/macros.asm
; and core/devices/<mcutype>/device.asm. Setting the value
; to 1 enables the feature, setting to 0 disables it.
; Most options are disabled by default. You should never
; change the files mentioned above, setting the options here
; is absolutly sufficient.

; the dictionary search treats lowercase and uppercase
; letters the same. Set to 0 if you do not want it
.set WANT_IGNORECASE = 1


; default settings as specified in core/macros.asm. Uncomment and
; change them if necessary.

; Size of the Terminal Input Buffer. This is the command line buffer.
; .set TIBSIZE  = $64    ; bytes; ANS94 needs at least 80 characters per line

; The total USER size is the sum of the system internal USER area plus
; the size specified here.
; .set APPUSERSIZE = 10  ; size of application specific user area in bytes

; addresses of various data segments.
;.set rstackstart = RAMEND      ; start address of return stack, grows downward
;.set stackstart  = RAMEND - 80 ; start address of data stack, grows downward
; change only if you know what to you do

; Total number of entries in the search order.
; The standard requires 8 wordlists in the search oder, amforth uses
; already one for itself. So you'll have 7 slots available.
;.set NUMWORDLISTS = 8

; Total number of recognizers.
; There are 2 recognizers already in the core system. That makes
; 2 for you.
;.set NUMRECOGNIZERS = 4


; DRIVER SECTION
;
; settings for 1wire interface, uncomment to use it
;.equ OW_PORT=PORTB
;.equ OW_BIT=4
;.include "drivers/1wire.asm"

; Interrupts.
; globally enable (or disable) the interrupt support. It is
; enabled by default and some other settings (usart receive)
; depend on it. disabling it makes the inner interpreter
; slightly faster and frees some code space.
; .set WANT_INTERRUPTS = 1

; reserve a RAM region to count each interrupt individually.
; each interrupt of the given controller type gets a byte
; that is incremented for each interrupt. Needs a lot of
; RAM but may be useful for debugging interrupts or get rid
; of random effects. disabled by default.
; .set WANT_INTERRUPT_COUNTERS = 0


; include the whole source tree.
.include "amforth.asm"
