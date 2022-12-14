; generic macros and register definitions
.include "macros.asm"

; controller specific file selected via include
; directory definition when calling the assembler (-I)
.include "device.asm"

; some defaults, change them in your application master file
; see template.asm for an example

; enabling Interrupts, disabling them affects
; other settings as well. 
.set WANT_INTERRUPTS = 1

; count the number of interrupts individually.
; requires a lot of RAM (one byte per interrupt)
; disabled by default.
.set WANT_INTERRUPT_COUNTERS = 1

; receiving is asynchronously, so an interrupt queue is useful.
.set WANT_ISR_RX = 1

; case insensitve dictionary lookup.
.set WANT_IGNORECASE = 0

; map all memories to one address space. Details in the
; technical guide
.set WANT_UNIFIED = 0

; terminal input buffer
.set TIB_SIZE  = 90    ; ANS94 needs at least 80 characters per line

; USER variables *in addition* to system ones
.set APPUSERSIZE = 10  ; size of application specific user area in bytes

; addresses of various data segments
.set rstackstart = RAMEND      ; start address of return stack, grows downward
.set stackstart  = RAMEND - 80 ; start address of data stack, grows downward
; change only if you know what to you do
.set NUMWORDLISTS = 8 ; number of word lists in the searh order, at least 8
.set NUMRECOGNIZERS = 4 ; total number of recognizers, two are always used.

; 10 per mille (1 per cent) is ok.
.set BAUD = 38400
.set BAUD_MAXERROR = 10

; Dictionary setup
.set VE_HEAD = $0000
.set VE_ENVHEAD = $0000
.set AMFORTH_RO_SEG = NRWW_START_ADDR