.nolist
.include "m8def.inc"
.list

  ; first address of RAM
  .equ ramstart = $60

  .equ INTVECTORS = 19 ; INT_VECTORS_SIZE
  .equ intvecsize = 1

  .equ amforth_interpreter = $0c00

  .equ BAUDRATE_LOW = UBRRL+$20
  .equ BAUDRATE_HIGH = UBRRH+$20
  .equ USART_C = UCSRC+$20
  .equ USART_B = UCSRB+$20
  .equ USART_A = UCSRA+$20
  .equ USART_B_VALUE = (1<<TXEN) | (1<<RXEN) | (1<<RXCIE)
  .equ USART_C_VALUE = (1<<URSEL) | ( 3<<UCSZ0)

  .equ SPMCSR = SPMCR
  .equ EEPE   = EEWE
  .equ EEMPE  = EEMWE

.macro jmp_
    rjmp @0
.endmacro

.macro call_
    rcall @0
.endmacro

.macro readflashcell
    lsl zl
    rol zh
    lpm @0, Z+
    lpm @1, Z+
.endmacro

.macro writeflashcell
    lsl zl
    rol zh
.endmacro

.org	INT0addr ; External Interrupt0 Vector Address
    rcall isr
.org	INT1addr ; External Interrupt1 Vector Address
    rcall isr
.org	OC2addr  ; Output Compare2 Interrupt Vector Address
    rcall isr
.org	OVF2addr ; Overflow2 Interrupt Vector Address
    rcall isr
.org	ICP1addr
    rcall isr	; Input Capture1 Interrupt Vector Address
.org	OC1Aaddr
    rcall isr	; Output Compare1A Interrupt Vector Address
.org	OC1Baddr
    rcall isr	; Output Compare1B Interrupt Vector Address
.org	OVF1addr
    rcall isr	; Overflow1 Interrupt Vector Address
.org	OVF0addr
    rcall isr	; Overflow0 Interrupt Vector Address
.org	SPIaddr
    rcall isr	; SPI Interrupt Vector Address
;.org	URXCaddr
;    rcall isr	; USART Receive Complete Interrupt Vector Address
;.org	UDREaddr
;    rcall isr	; USART Data Register Empty Interrupt Vector Address
.org	UTXCaddr
    rcall isr	; USART Transmit Complete Interrupt Vector Address
.org	ADCCaddr ; ADC Interrupt Vector Address
    rcall isr
.org	ERDYaddr
    rcall isr	; EEPROM Interrupt Vector Address
.org	ACIaddr
    rcall isr	; Analog Comparator Interrupt Vector Address
.org    TWIaddr
    rcall isr   ; Irq. vector address for Two-Wire Interface

mcustring:
  .dw 7
  .db "ATmega8 "
.set codestart = pc
