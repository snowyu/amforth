; Settings for the eval board with Atmega8 & 8 MHz
.include "macros.asm"
.include "devices/atmega16.asm"

  .equ HLDSIZE  = $10  ; 16 bit cellsize with binary representation
  .equ TIBSIZE  = $64  ; 80 characters is one line...
  .equ CELLSIZE = 2    ;
  .equ APPUSERSIZE = 0 ; size of user area

; cpu clock in hertz
.equ F_CPU = 8000000
; baud rate of terminal
.equ BAUD = 9600
.equ USART_B_VALUE = (1<<TXEN) | (1<<RXEN) ; | (1<<RXCIE)
.equ USART_C_VALUE = (3<<UCSZ0)

.set heap = ramstart
.set rstackstart = RAMEND
.set stackstart  = RAMEND - 80
.set amforth_interpreter = max_dict_addr
.set want_fun = 1
.set NUMWORDLISTS = 8

.include "amforth.asm"
