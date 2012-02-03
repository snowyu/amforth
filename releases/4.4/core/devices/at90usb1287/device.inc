; Partname:  AT90USB1287
; Built using part description XML file version 66
; generated automatically, no not edit

; ********
.if WANT_AD_CONVERTER == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; ADC Data Register High Byte
VE_ADCH:
	.dw $ff04
	.db "ADCH"
	.dw VE_HEAD
	.set VE_HEAD=VE_ADCH
XT_ADCH:
	.dw PFA_DOVARIABLE
PFA_ADCH:
	.dw $79
; ( -- addr ) System Constant
; R( -- )
; ADC Data Register Low Byte
VE_ADCL:
	.dw $ff04
	.db "ADCL"
	.dw VE_HEAD
	.set VE_HEAD=VE_ADCL
XT_ADCL:
	.dw PFA_DOVARIABLE
PFA_ADCL:
	.dw $78
; ( -- addr ) System Constant
; R( -- )
; The ADC Control and Status register
VE_ADCSRA:
	.dw $ff06
	.db "ADCSRA"
	.dw VE_HEAD
	.set VE_HEAD=VE_ADCSRA
XT_ADCSRA:
	.dw PFA_DOVARIABLE
PFA_ADCSRA:
	.dw $7A
; ( -- addr ) System Constant
; R( -- )
; ADC Control and Status Register B
VE_ADCSRB:
	.dw $ff06
	.db "ADCSRB"
	.dw VE_HEAD
	.set VE_HEAD=VE_ADCSRB
XT_ADCSRB:
	.dw PFA_DOVARIABLE
PFA_ADCSRB:
	.dw $7B
; ( -- addr ) System Constant
; R( -- )
; The ADC multiplexer Selection Register
VE_ADMUX:
	.dw $ff05
	.db "ADMUX",0
	.dw VE_HEAD
	.set VE_HEAD=VE_ADMUX
XT_ADMUX:
	.dw PFA_DOVARIABLE
PFA_ADMUX:
	.dw $7C
; ( -- addr ) System Constant
; R( -- )
; Digital Input Disable Register 1
VE_DIDR0:
	.dw $ff05
	.db "DIDR0",0
	.dw VE_HEAD
	.set VE_HEAD=VE_DIDR0
XT_DIDR0:
	.dw PFA_DOVARIABLE
PFA_DIDR0:
	.dw $7E

.endif

; ********
.if WANT_ANALOG_COMPARATOR == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; Analog Comparator Control And Status Register
VE_ACSR:
	.dw $ff04
	.db "ACSR"
	.dw VE_HEAD
	.set VE_HEAD=VE_ACSR
XT_ACSR:
	.dw PFA_DOVARIABLE
PFA_ACSR:
	.dw $50
; ( -- addr ) System Constant
; R( -- )
; 
VE_DIDR1:
	.dw $ff05
	.db "DIDR1",0
	.dw VE_HEAD
	.set VE_HEAD=VE_DIDR1
XT_DIDR1:
	.dw PFA_DOVARIABLE
PFA_DIDR1:
	.dw $7F

.endif

; ********
.if WANT_BOOT_LOAD == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; Store Program Memory Control Register
VE_SPMCSR:
	.dw $ff06
	.db "SPMCSR"
	.dw VE_HEAD
	.set VE_HEAD=VE_SPMCSR
XT_SPMCSR:
	.dw PFA_DOVARIABLE
PFA_SPMCSR:
	.dw $57

.endif

; ********
.if WANT_CPU == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; 
VE_CLKPR:
	.dw $ff05
	.db "CLKPR",0
	.dw VE_HEAD
	.set VE_HEAD=VE_CLKPR
XT_CLKPR:
	.dw PFA_DOVARIABLE
PFA_CLKPR:
	.dw $61
; ( -- addr ) System Constant
; R( -- )
; Extended Indirect Register
VE_EIND:
	.dw $ff04
	.db "EIND"
	.dw VE_HEAD
	.set VE_HEAD=VE_EIND
XT_EIND:
	.dw PFA_DOVARIABLE
PFA_EIND:
	.dw $5C
; ( -- addr ) System Constant
; R( -- )
; General Purpose IO Register 0
VE_GPIOR0:
	.dw $ff06
	.db "GPIOR0"
	.dw VE_HEAD
	.set VE_HEAD=VE_GPIOR0
XT_GPIOR0:
	.dw PFA_DOVARIABLE
PFA_GPIOR0:
	.dw $3E
; ( -- addr ) System Constant
; R( -- )
; General Purpose IO Register 1
VE_GPIOR1:
	.dw $ff06
	.db "GPIOR1"
	.dw VE_HEAD
	.set VE_HEAD=VE_GPIOR1
XT_GPIOR1:
	.dw PFA_DOVARIABLE
PFA_GPIOR1:
	.dw $4A
; ( -- addr ) System Constant
; R( -- )
; General Purpose IO Register 2
VE_GPIOR2:
	.dw $ff06
	.db "GPIOR2"
	.dw VE_HEAD
	.set VE_HEAD=VE_GPIOR2
XT_GPIOR2:
	.dw PFA_DOVARIABLE
PFA_GPIOR2:
	.dw $4B
; ( -- addr ) System Constant
; R( -- )
; MCU Control Register
VE_MCUCR:
	.dw $ff05
	.db "MCUCR",0
	.dw VE_HEAD
	.set VE_HEAD=VE_MCUCR
XT_MCUCR:
	.dw PFA_DOVARIABLE
PFA_MCUCR:
	.dw $55
; ( -- addr ) System Constant
; R( -- )
; MCU Status Register
VE_MCUSR:
	.dw $ff05
	.db "MCUSR",0
	.dw VE_HEAD
	.set VE_HEAD=VE_MCUSR
XT_MCUSR:
	.dw PFA_DOVARIABLE
PFA_MCUSR:
	.dw $54
; ( -- addr ) System Constant
; R( -- )
; Oscillator Calibration Value
VE_OSCCAL:
	.dw $ff06
	.db "OSCCAL"
	.dw VE_HEAD
	.set VE_HEAD=VE_OSCCAL
XT_OSCCAL:
	.dw PFA_DOVARIABLE
PFA_OSCCAL:
	.dw $66
; ( -- addr ) System Constant
; R( -- )
; Power Reduction Register0
VE_PRR0:
	.dw $ff04
	.db "PRR0"
	.dw VE_HEAD
	.set VE_HEAD=VE_PRR0
XT_PRR0:
	.dw PFA_DOVARIABLE
PFA_PRR0:
	.dw $64
; ( -- addr ) System Constant
; R( -- )
; Power Reduction Register1
VE_PRR1:
	.dw $ff04
	.db "PRR1"
	.dw VE_HEAD
	.set VE_HEAD=VE_PRR1
XT_PRR1:
	.dw PFA_DOVARIABLE
PFA_PRR1:
	.dw $65
; ( -- addr ) System Constant
; R( -- )
; RAM Page Z Select Register
VE_RAMPZ:
	.dw $ff05
	.db "RAMPZ",0
	.dw VE_HEAD
	.set VE_HEAD=VE_RAMPZ
XT_RAMPZ:
	.dw PFA_DOVARIABLE
PFA_RAMPZ:
	.dw $5B
; ( -- addr ) System Constant
; R( -- )
; Sleep Mode Control Register
VE_SMCR:
	.dw $ff04
	.db "SMCR"
	.dw VE_HEAD
	.set VE_HEAD=VE_SMCR
XT_SMCR:
	.dw PFA_DOVARIABLE
PFA_SMCR:
	.dw $53
; ( -- addr ) System Constant
; R( -- )
; Stack Pointer High
VE_SPH:
	.dw $ff03
	.db "SPH",0
	.dw VE_HEAD
	.set VE_HEAD=VE_SPH
XT_SPH:
	.dw PFA_DOVARIABLE
PFA_SPH:
	.dw $5E
; ( -- addr ) System Constant
; R( -- )
; Stack Pointer Low
VE_SPL:
	.dw $ff03
	.db "SPL",0
	.dw VE_HEAD
	.set VE_HEAD=VE_SPL
XT_SPL:
	.dw PFA_DOVARIABLE
PFA_SPL:
	.dw $5D
; ( -- addr ) System Constant
; R( -- )
; Status Register
VE_SREG:
	.dw $ff04
	.db "SREG"
	.dw VE_HEAD
	.set VE_HEAD=VE_SREG
XT_SREG:
	.dw PFA_DOVARIABLE
PFA_SREG:
	.dw $5F
; ( -- addr ) System Constant
; R( -- )
; External Memory Control Register A
VE_XMCRA:
	.dw $ff05
	.db "XMCRA",0
	.dw VE_HEAD
	.set VE_HEAD=VE_XMCRA
XT_XMCRA:
	.dw PFA_DOVARIABLE
PFA_XMCRA:
	.dw $74
; ( -- addr ) System Constant
; R( -- )
; External Memory Control Register B
VE_XMCRB:
	.dw $ff05
	.db "XMCRB",0
	.dw VE_HEAD
	.set VE_HEAD=VE_XMCRB
XT_XMCRB:
	.dw PFA_DOVARIABLE
PFA_XMCRB:
	.dw $75

.endif

; ********
.if WANT_EEPROM == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; EEPROM Address Register Low Byte
VE_EEARH:
	.dw $ff05
	.db "EEARH",0
	.dw VE_HEAD
	.set VE_HEAD=VE_EEARH
XT_EEARH:
	.dw PFA_DOVARIABLE
PFA_EEARH:
	.dw $42
; ( -- addr ) System Constant
; R( -- )
; EEPROM Address Register Low Byte
VE_EEARL:
	.dw $ff05
	.db "EEARL",0
	.dw VE_HEAD
	.set VE_HEAD=VE_EEARL
XT_EEARL:
	.dw PFA_DOVARIABLE
PFA_EEARL:
	.dw $41
; ( -- addr ) System Constant
; R( -- )
; EEPROM Control Register
VE_EECR:
	.dw $ff04
	.db "EECR"
	.dw VE_HEAD
	.set VE_HEAD=VE_EECR
XT_EECR:
	.dw PFA_DOVARIABLE
PFA_EECR:
	.dw $3F
; ( -- addr ) System Constant
; R( -- )
; EEPROM Data Register
VE_EEDR:
	.dw $ff04
	.db "EEDR"
	.dw VE_HEAD
	.set VE_HEAD=VE_EEDR
XT_EEDR:
	.dw PFA_DOVARIABLE
PFA_EEDR:
	.dw $40

.endif

; ********
.if WANT_EXTERNAL_INTERRUPT == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; External Interrupt Control Register A
VE_EICRA:
	.dw $ff05
	.db "EICRA",0
	.dw VE_HEAD
	.set VE_HEAD=VE_EICRA
XT_EICRA:
	.dw PFA_DOVARIABLE
PFA_EICRA:
	.dw $69
; ( -- addr ) System Constant
; R( -- )
; External Interrupt Control Register B
VE_EICRB:
	.dw $ff05
	.db "EICRB",0
	.dw VE_HEAD
	.set VE_HEAD=VE_EICRB
XT_EICRB:
	.dw PFA_DOVARIABLE
PFA_EICRB:
	.dw $6A
; ( -- addr ) System Constant
; R( -- )
; External Interrupt Flag Register
VE_EIFR:
	.dw $ff04
	.db "EIFR"
	.dw VE_HEAD
	.set VE_HEAD=VE_EIFR
XT_EIFR:
	.dw PFA_DOVARIABLE
PFA_EIFR:
	.dw $3C
; ( -- addr ) System Constant
; R( -- )
; External Interrupt Mask Register
VE_EIMSK:
	.dw $ff05
	.db "EIMSK",0
	.dw VE_HEAD
	.set VE_HEAD=VE_EIMSK
XT_EIMSK:
	.dw PFA_DOVARIABLE
PFA_EIMSK:
	.dw $3D
; ( -- addr ) System Constant
; R( -- )
; Pin Change Interrupt Control Register
VE_PCICR:
	.dw $ff05
	.db "PCICR",0
	.dw VE_HEAD
	.set VE_HEAD=VE_PCICR
XT_PCICR:
	.dw PFA_DOVARIABLE
PFA_PCICR:
	.dw $68
; ( -- addr ) System Constant
; R( -- )
; Pin Change Interrupt Flag Register
VE_PCIFR:
	.dw $ff05
	.db "PCIFR",0
	.dw VE_HEAD
	.set VE_HEAD=VE_PCIFR
XT_PCIFR:
	.dw PFA_DOVARIABLE
PFA_PCIFR:
	.dw $3B
; ( -- addr ) System Constant
; R( -- )
; Pin Change Mask Register 0
VE_PCMSK0:
	.dw $ff06
	.db "PCMSK0"
	.dw VE_HEAD
	.set VE_HEAD=VE_PCMSK0
XT_PCMSK0:
	.dw PFA_DOVARIABLE
PFA_PCMSK0:
	.dw $6B

.endif

; ********
.if WANT_JTAG == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; On-Chip Debug Related Register in I/O Memory
VE_OCDR:
	.dw $ff04
	.db "OCDR"
	.dw VE_HEAD
	.set VE_HEAD=VE_OCDR
XT_OCDR:
	.dw PFA_DOVARIABLE
PFA_OCDR:
	.dw $51

.endif

; ********
.if WANT_PLL == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; PLL Status and Control register
VE_PLLCSR:
	.dw $ff06
	.db "PLLCSR"
	.dw VE_HEAD
	.set VE_HEAD=VE_PLLCSR
XT_PLLCSR:
	.dw PFA_DOVARIABLE
PFA_PLLCSR:
	.dw $49

.endif

; ********
.if WANT_PORTA == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; Port A Data Direction Register
VE_DDRA:
	.dw $ff04
	.db "DDRA"
	.dw VE_HEAD
	.set VE_HEAD=VE_DDRA
XT_DDRA:
	.dw PFA_DOVARIABLE
PFA_DDRA:
	.dw $21
; ( -- addr ) System Constant
; R( -- )
; Port A Input Pins
VE_PINA:
	.dw $ff04
	.db "PINA"
	.dw VE_HEAD
	.set VE_HEAD=VE_PINA
XT_PINA:
	.dw PFA_DOVARIABLE
PFA_PINA:
	.dw $20
; ( -- addr ) System Constant
; R( -- )
; Port A Data Register
VE_PORTA:
	.dw $ff05
	.db "PORTA",0
	.dw VE_HEAD
	.set VE_HEAD=VE_PORTA
XT_PORTA:
	.dw PFA_DOVARIABLE
PFA_PORTA:
	.dw $22

.endif

; ********
.if WANT_PORTB == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; Port B Data Direction Register
VE_DDRB:
	.dw $ff04
	.db "DDRB"
	.dw VE_HEAD
	.set VE_HEAD=VE_DDRB
XT_DDRB:
	.dw PFA_DOVARIABLE
PFA_DDRB:
	.dw $24
; ( -- addr ) System Constant
; R( -- )
; Port B Input Pins
VE_PINB:
	.dw $ff04
	.db "PINB"
	.dw VE_HEAD
	.set VE_HEAD=VE_PINB
XT_PINB:
	.dw PFA_DOVARIABLE
PFA_PINB:
	.dw $23
; ( -- addr ) System Constant
; R( -- )
; Port B Data Register
VE_PORTB:
	.dw $ff05
	.db "PORTB",0
	.dw VE_HEAD
	.set VE_HEAD=VE_PORTB
XT_PORTB:
	.dw PFA_DOVARIABLE
PFA_PORTB:
	.dw $25

.endif

; ********
.if WANT_PORTC == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; Port C Data Direction Register
VE_DDRC:
	.dw $ff04
	.db "DDRC"
	.dw VE_HEAD
	.set VE_HEAD=VE_DDRC
XT_DDRC:
	.dw PFA_DOVARIABLE
PFA_DDRC:
	.dw $27
; ( -- addr ) System Constant
; R( -- )
; Port C Input Pins
VE_PINC:
	.dw $ff04
	.db "PINC"
	.dw VE_HEAD
	.set VE_HEAD=VE_PINC
XT_PINC:
	.dw PFA_DOVARIABLE
PFA_PINC:
	.dw $26
; ( -- addr ) System Constant
; R( -- )
; Port C Data Register
VE_PORTC:
	.dw $ff05
	.db "PORTC",0
	.dw VE_HEAD
	.set VE_HEAD=VE_PORTC
XT_PORTC:
	.dw PFA_DOVARIABLE
PFA_PORTC:
	.dw $28

.endif

; ********
.if WANT_PORTD == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; Port D Data Direction Register
VE_DDRD:
	.dw $ff04
	.db "DDRD"
	.dw VE_HEAD
	.set VE_HEAD=VE_DDRD
XT_DDRD:
	.dw PFA_DOVARIABLE
PFA_DDRD:
	.dw $2A
; ( -- addr ) System Constant
; R( -- )
; Port D Input Pins
VE_PIND:
	.dw $ff04
	.db "PIND"
	.dw VE_HEAD
	.set VE_HEAD=VE_PIND
XT_PIND:
	.dw PFA_DOVARIABLE
PFA_PIND:
	.dw $29
; ( -- addr ) System Constant
; R( -- )
; Port D Data Register
VE_PORTD:
	.dw $ff05
	.db "PORTD",0
	.dw VE_HEAD
	.set VE_HEAD=VE_PORTD
XT_PORTD:
	.dw PFA_DOVARIABLE
PFA_PORTD:
	.dw $2B

.endif

; ********
.if WANT_PORTE == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; Data Direction Register, Port E
VE_DDRE:
	.dw $ff04
	.db "DDRE"
	.dw VE_HEAD
	.set VE_HEAD=VE_DDRE
XT_DDRE:
	.dw PFA_DOVARIABLE
PFA_DDRE:
	.dw $2D
; ( -- addr ) System Constant
; R( -- )
; Input Pins, Port E
VE_PINE:
	.dw $ff04
	.db "PINE"
	.dw VE_HEAD
	.set VE_HEAD=VE_PINE
XT_PINE:
	.dw PFA_DOVARIABLE
PFA_PINE:
	.dw $2C
; ( -- addr ) System Constant
; R( -- )
; Data Register, Port E
VE_PORTE:
	.dw $ff05
	.db "PORTE",0
	.dw VE_HEAD
	.set VE_HEAD=VE_PORTE
XT_PORTE:
	.dw PFA_DOVARIABLE
PFA_PORTE:
	.dw $2E

.endif

; ********
.if WANT_PORTF == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; Data Direction Register, Port F
VE_DDRF:
	.dw $ff04
	.db "DDRF"
	.dw VE_HEAD
	.set VE_HEAD=VE_DDRF
XT_DDRF:
	.dw PFA_DOVARIABLE
PFA_DDRF:
	.dw $30
; ( -- addr ) System Constant
; R( -- )
; Input Pins, Port F
VE_PINF:
	.dw $ff04
	.db "PINF"
	.dw VE_HEAD
	.set VE_HEAD=VE_PINF
XT_PINF:
	.dw PFA_DOVARIABLE
PFA_PINF:
	.dw $2F
; ( -- addr ) System Constant
; R( -- )
; Data Register, Port F
VE_PORTF:
	.dw $ff05
	.db "PORTF",0
	.dw VE_HEAD
	.set VE_HEAD=VE_PORTF
XT_PORTF:
	.dw PFA_DOVARIABLE
PFA_PORTF:
	.dw $31

.endif

; ********
.if WANT_SPI == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; SPI Control Register
VE_SPCR:
	.dw $ff04
	.db "SPCR"
	.dw VE_HEAD
	.set VE_HEAD=VE_SPCR
XT_SPCR:
	.dw PFA_DOVARIABLE
PFA_SPCR:
	.dw $4C
; ( -- addr ) System Constant
; R( -- )
; SPI Data Register
VE_SPDR:
	.dw $ff04
	.db "SPDR"
	.dw VE_HEAD
	.set VE_HEAD=VE_SPDR
XT_SPDR:
	.dw PFA_DOVARIABLE
PFA_SPDR:
	.dw $4E
; ( -- addr ) System Constant
; R( -- )
; SPI Status Register
VE_SPSR:
	.dw $ff04
	.db "SPSR"
	.dw VE_HEAD
	.set VE_HEAD=VE_SPSR
XT_SPSR:
	.dw PFA_DOVARIABLE
PFA_SPSR:
	.dw $4D

.endif

; ********
.if WANT_TIMER_COUNTER_0 == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; General Timer/Counter Control Register
VE_GTCCR:
	.dw $ff05
	.db "GTCCR",0
	.dw VE_HEAD
	.set VE_HEAD=VE_GTCCR
XT_GTCCR:
	.dw PFA_DOVARIABLE
PFA_GTCCR:
	.dw $43
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter0 Output Compare Register
VE_OCR0A:
	.dw $ff05
	.db "OCR0A",0
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR0A
XT_OCR0A:
	.dw PFA_DOVARIABLE
PFA_OCR0A:
	.dw $47
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter0 Output Compare Register
VE_OCR0B:
	.dw $ff05
	.db "OCR0B",0
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR0B
XT_OCR0B:
	.dw PFA_DOVARIABLE
PFA_OCR0B:
	.dw $48
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter  Control Register A
VE_TCCR0A:
	.dw $ff06
	.db "TCCR0A"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCCR0A
XT_TCCR0A:
	.dw PFA_DOVARIABLE
PFA_TCCR0A:
	.dw $44
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter Control Register B
VE_TCCR0B:
	.dw $ff06
	.db "TCCR0B"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCCR0B
XT_TCCR0B:
	.dw PFA_DOVARIABLE
PFA_TCCR0B:
	.dw $45
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter0
VE_TCNT0:
	.dw $ff05
	.db "TCNT0",0
	.dw VE_HEAD
	.set VE_HEAD=VE_TCNT0
XT_TCNT0:
	.dw PFA_DOVARIABLE
PFA_TCNT0:
	.dw $46
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter0 Interrupt Flag register
VE_TIFR0:
	.dw $ff05
	.db "TIFR0",0
	.dw VE_HEAD
	.set VE_HEAD=VE_TIFR0
XT_TIFR0:
	.dw PFA_DOVARIABLE
PFA_TIFR0:
	.dw $35
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter0 Interrupt Mask Register
VE_TIMSK0:
	.dw $ff06
	.db "TIMSK0"
	.dw VE_HEAD
	.set VE_HEAD=VE_TIMSK0
XT_TIMSK0:
	.dw PFA_DOVARIABLE
PFA_TIMSK0:
	.dw $6E

.endif

; ********
.if WANT_TIMER_COUNTER_1 == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 Input Capture Register High Byte
VE_ICR1H:
	.dw $ff05
	.db "ICR1H",0
	.dw VE_HEAD
	.set VE_HEAD=VE_ICR1H
XT_ICR1H:
	.dw PFA_DOVARIABLE
PFA_ICR1H:
	.dw $87
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 Input Capture Register Low Byte
VE_ICR1L:
	.dw $ff05
	.db "ICR1L",0
	.dw VE_HEAD
	.set VE_HEAD=VE_ICR1L
XT_ICR1L:
	.dw PFA_DOVARIABLE
PFA_ICR1L:
	.dw $86
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 Output Compare Register A High Byte
VE_OCR1AH:
	.dw $ff06
	.db "OCR1AH"
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR1AH
XT_OCR1AH:
	.dw PFA_DOVARIABLE
PFA_OCR1AH:
	.dw $89
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 Output Compare Register A Low Byte
VE_OCR1AL:
	.dw $ff06
	.db "OCR1AL"
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR1AL
XT_OCR1AL:
	.dw PFA_DOVARIABLE
PFA_OCR1AL:
	.dw $88
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 Output Compare Register B High Byte
VE_OCR1BH:
	.dw $ff06
	.db "OCR1BH"
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR1BH
XT_OCR1BH:
	.dw PFA_DOVARIABLE
PFA_OCR1BH:
	.dw $8B
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 Output Compare Register B Low Byte
VE_OCR1BL:
	.dw $ff06
	.db "OCR1BL"
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR1BL
XT_OCR1BL:
	.dw PFA_DOVARIABLE
PFA_OCR1BL:
	.dw $8A
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 Output Compare Register C High Byte
VE_OCR1CH:
	.dw $ff06
	.db "OCR1CH"
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR1CH
XT_OCR1CH:
	.dw PFA_DOVARIABLE
PFA_OCR1CH:
	.dw $8D
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 Output Compare Register C Low Byte
VE_OCR1CL:
	.dw $ff06
	.db "OCR1CL"
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR1CL
XT_OCR1CL:
	.dw PFA_DOVARIABLE
PFA_OCR1CL:
	.dw $8C
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 Control Register A
VE_TCCR1A:
	.dw $ff06
	.db "TCCR1A"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCCR1A
XT_TCCR1A:
	.dw PFA_DOVARIABLE
PFA_TCCR1A:
	.dw $80
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 Control Register B
VE_TCCR1B:
	.dw $ff06
	.db "TCCR1B"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCCR1B
XT_TCCR1B:
	.dw PFA_DOVARIABLE
PFA_TCCR1B:
	.dw $81
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter 1 Control Register C
VE_TCCR1C:
	.dw $ff06
	.db "TCCR1C"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCCR1C
XT_TCCR1C:
	.dw PFA_DOVARIABLE
PFA_TCCR1C:
	.dw $82
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 High Byte
VE_TCNT1H:
	.dw $ff06
	.db "TCNT1H"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCNT1H
XT_TCNT1H:
	.dw PFA_DOVARIABLE
PFA_TCNT1H:
	.dw $85
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 Low Byte
VE_TCNT1L:
	.dw $ff06
	.db "TCNT1L"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCNT1L
XT_TCNT1L:
	.dw PFA_DOVARIABLE
PFA_TCNT1L:
	.dw $84
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 Interrupt Flag register
VE_TIFR1:
	.dw $ff05
	.db "TIFR1",0
	.dw VE_HEAD
	.set VE_HEAD=VE_TIFR1
XT_TIFR1:
	.dw PFA_DOVARIABLE
PFA_TIFR1:
	.dw $36
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter1 Interrupt Mask Register
VE_TIMSK1:
	.dw $ff06
	.db "TIMSK1"
	.dw VE_HEAD
	.set VE_HEAD=VE_TIMSK1
XT_TIMSK1:
	.dw PFA_DOVARIABLE
PFA_TIMSK1:
	.dw $6F

.endif

; ********
.if WANT_TIMER_COUNTER_2 == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; Asynchronous Status Register
VE_ASSR:
	.dw $ff04
	.db "ASSR"
	.dw VE_HEAD
	.set VE_HEAD=VE_ASSR
XT_ASSR:
	.dw PFA_DOVARIABLE
PFA_ASSR:
	.dw $B6
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter2 Output Compare Register A
VE_OCR2A:
	.dw $ff05
	.db "OCR2A",0
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR2A
XT_OCR2A:
	.dw PFA_DOVARIABLE
PFA_OCR2A:
	.dw $B3
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter2 Output Compare Register B
VE_OCR2B:
	.dw $ff05
	.db "OCR2B",0
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR2B
XT_OCR2B:
	.dw PFA_DOVARIABLE
PFA_OCR2B:
	.dw $B4
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter2 Control Register A
VE_TCCR2A:
	.dw $ff06
	.db "TCCR2A"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCCR2A
XT_TCCR2A:
	.dw PFA_DOVARIABLE
PFA_TCCR2A:
	.dw $B0
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter2 Control Register B
VE_TCCR2B:
	.dw $ff06
	.db "TCCR2B"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCCR2B
XT_TCCR2B:
	.dw PFA_DOVARIABLE
PFA_TCCR2B:
	.dw $B1
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter2
VE_TCNT2:
	.dw $ff05
	.db "TCNT2",0
	.dw VE_HEAD
	.set VE_HEAD=VE_TCNT2
XT_TCNT2:
	.dw PFA_DOVARIABLE
PFA_TCNT2:
	.dw $B2
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter Interrupt Flag Register
VE_TIFR2:
	.dw $ff05
	.db "TIFR2",0
	.dw VE_HEAD
	.set VE_HEAD=VE_TIFR2
XT_TIFR2:
	.dw PFA_DOVARIABLE
PFA_TIFR2:
	.dw $37
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter Interrupt Mask register
VE_TIMSK2:
	.dw $ff06
	.db "TIMSK2"
	.dw VE_HEAD
	.set VE_HEAD=VE_TIMSK2
XT_TIMSK2:
	.dw PFA_DOVARIABLE
PFA_TIMSK2:
	.dw $70

.endif

; ********
.if WANT_TIMER_COUNTER_3 == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 Input Capture Register High Byte
VE_ICR3H:
	.dw $ff05
	.db "ICR3H",0
	.dw VE_HEAD
	.set VE_HEAD=VE_ICR3H
XT_ICR3H:
	.dw PFA_DOVARIABLE
PFA_ICR3H:
	.dw $97
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 Input Capture Register Low Byte
VE_ICR3L:
	.dw $ff05
	.db "ICR3L",0
	.dw VE_HEAD
	.set VE_HEAD=VE_ICR3L
XT_ICR3L:
	.dw PFA_DOVARIABLE
PFA_ICR3L:
	.dw $96
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 Output Compare Register A High Byte
VE_OCR3AH:
	.dw $ff06
	.db "OCR3AH"
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR3AH
XT_OCR3AH:
	.dw PFA_DOVARIABLE
PFA_OCR3AH:
	.dw $99
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 Output Compare Register A Low Byte
VE_OCR3AL:
	.dw $ff06
	.db "OCR3AL"
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR3AL
XT_OCR3AL:
	.dw PFA_DOVARIABLE
PFA_OCR3AL:
	.dw $98
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 Output Compare Register B High Byte
VE_OCR3BH:
	.dw $ff06
	.db "OCR3BH"
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR3BH
XT_OCR3BH:
	.dw PFA_DOVARIABLE
PFA_OCR3BH:
	.dw $9B
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 Output Compare Register B Low Byte
VE_OCR3BL:
	.dw $ff06
	.db "OCR3BL"
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR3BL
XT_OCR3BL:
	.dw PFA_DOVARIABLE
PFA_OCR3BL:
	.dw $9A
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 Output Compare Register B High Byte
VE_OCR3CH:
	.dw $ff06
	.db "OCR3CH"
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR3CH
XT_OCR3CH:
	.dw PFA_DOVARIABLE
PFA_OCR3CH:
	.dw $9D
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 Output Compare Register B Low Byte
VE_OCR3CL:
	.dw $ff06
	.db "OCR3CL"
	.dw VE_HEAD
	.set VE_HEAD=VE_OCR3CL
XT_OCR3CL:
	.dw PFA_DOVARIABLE
PFA_OCR3CL:
	.dw $9C
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 Control Register A
VE_TCCR3A:
	.dw $ff06
	.db "TCCR3A"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCCR3A
XT_TCCR3A:
	.dw PFA_DOVARIABLE
PFA_TCCR3A:
	.dw $90
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 Control Register B
VE_TCCR3B:
	.dw $ff06
	.db "TCCR3B"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCCR3B
XT_TCCR3B:
	.dw PFA_DOVARIABLE
PFA_TCCR3B:
	.dw $91
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter 3 Control Register C
VE_TCCR3C:
	.dw $ff06
	.db "TCCR3C"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCCR3C
XT_TCCR3C:
	.dw PFA_DOVARIABLE
PFA_TCCR3C:
	.dw $92
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 High Byte
VE_TCNT3H:
	.dw $ff06
	.db "TCNT3H"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCNT3H
XT_TCNT3H:
	.dw PFA_DOVARIABLE
PFA_TCNT3H:
	.dw $95
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 Low Byte
VE_TCNT3L:
	.dw $ff06
	.db "TCNT3L"
	.dw VE_HEAD
	.set VE_HEAD=VE_TCNT3L
XT_TCNT3L:
	.dw PFA_DOVARIABLE
PFA_TCNT3L:
	.dw $94
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 Interrupt Flag register
VE_TIFR3:
	.dw $ff05
	.db "TIFR3",0
	.dw VE_HEAD
	.set VE_HEAD=VE_TIFR3
XT_TIFR3:
	.dw PFA_DOVARIABLE
PFA_TIFR3:
	.dw $38
; ( -- addr ) System Constant
; R( -- )
; Timer/Counter3 Interrupt Mask Register
VE_TIMSK3:
	.dw $ff06
	.db "TIMSK3"
	.dw VE_HEAD
	.set VE_HEAD=VE_TIMSK3
XT_TIMSK3:
	.dw PFA_DOVARIABLE
PFA_TIMSK3:
	.dw $71

.endif

; ********
.if WANT_TWI == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; TWI (Slave) Address Mask Register
VE_TWAMR:
	.dw $ff05
	.db "TWAMR",0
	.dw VE_HEAD
	.set VE_HEAD=VE_TWAMR
XT_TWAMR:
	.dw PFA_DOVARIABLE
PFA_TWAMR:
	.dw $BD
; ( -- addr ) System Constant
; R( -- )
; TWI (Slave) Address register
VE_TWAR:
	.dw $ff04
	.db "TWAR"
	.dw VE_HEAD
	.set VE_HEAD=VE_TWAR
XT_TWAR:
	.dw PFA_DOVARIABLE
PFA_TWAR:
	.dw $BA
; ( -- addr ) System Constant
; R( -- )
; TWI Bit Rate register
VE_TWBR:
	.dw $ff04
	.db "TWBR"
	.dw VE_HEAD
	.set VE_HEAD=VE_TWBR
XT_TWBR:
	.dw PFA_DOVARIABLE
PFA_TWBR:
	.dw $B8
; ( -- addr ) System Constant
; R( -- )
; TWI Control Register
VE_TWCR:
	.dw $ff04
	.db "TWCR"
	.dw VE_HEAD
	.set VE_HEAD=VE_TWCR
XT_TWCR:
	.dw PFA_DOVARIABLE
PFA_TWCR:
	.dw $BC
; ( -- addr ) System Constant
; R( -- )
; TWI Data register
VE_TWDR:
	.dw $ff04
	.db "TWDR"
	.dw VE_HEAD
	.set VE_HEAD=VE_TWDR
XT_TWDR:
	.dw PFA_DOVARIABLE
PFA_TWDR:
	.dw $BB
; ( -- addr ) System Constant
; R( -- )
; TWI Status Register
VE_TWSR:
	.dw $ff04
	.db "TWSR"
	.dw VE_HEAD
	.set VE_HEAD=VE_TWSR
XT_TWSR:
	.dw PFA_DOVARIABLE
PFA_TWSR:
	.dw $B9

.endif

; ********
.if WANT_USART1 == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; USART Baud Rate Register High Byte
VE_UBRR1H:
	.dw $ff06
	.db "UBRR1H"
	.dw VE_HEAD
	.set VE_HEAD=VE_UBRR1H
XT_UBRR1H:
	.dw PFA_DOVARIABLE
PFA_UBRR1H:
	.dw $CD
; ( -- addr ) System Constant
; R( -- )
; USART Baud Rate Register Low Byte
VE_UBRR1L:
	.dw $ff06
	.db "UBRR1L"
	.dw VE_HEAD
	.set VE_HEAD=VE_UBRR1L
XT_UBRR1L:
	.dw PFA_DOVARIABLE
PFA_UBRR1L:
	.dw $CC
; ( -- addr ) System Constant
; R( -- )
; USART Control and Status Register A
VE_UCSR1A:
	.dw $ff06
	.db "UCSR1A"
	.dw VE_HEAD
	.set VE_HEAD=VE_UCSR1A
XT_UCSR1A:
	.dw PFA_DOVARIABLE
PFA_UCSR1A:
	.dw $C8
; ( -- addr ) System Constant
; R( -- )
; USART Control and Status Register B
VE_UCSR1B:
	.dw $ff06
	.db "UCSR1B"
	.dw VE_HEAD
	.set VE_HEAD=VE_UCSR1B
XT_UCSR1B:
	.dw PFA_DOVARIABLE
PFA_UCSR1B:
	.dw $C9
; ( -- addr ) System Constant
; R( -- )
; USART Control and Status Register C
VE_UCSR1C:
	.dw $ff06
	.db "UCSR1C"
	.dw VE_HEAD
	.set VE_HEAD=VE_UCSR1C
XT_UCSR1C:
	.dw PFA_DOVARIABLE
PFA_UCSR1C:
	.dw $CA
; ( -- addr ) System Constant
; R( -- )
; USART I/O Data Register
VE_UDR1:
	.dw $ff04
	.db "UDR1"
	.dw VE_HEAD
	.set VE_HEAD=VE_UDR1
XT_UDR1:
	.dw PFA_DOVARIABLE
PFA_UDR1:
	.dw $CE

.endif

; ********
.if WANT_USB_DEVICE == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; 
VE_UDADDR:
	.dw $ff06
	.db "UDADDR"
	.dw VE_HEAD
	.set VE_HEAD=VE_UDADDR
XT_UDADDR:
	.dw PFA_DOVARIABLE
PFA_UDADDR:
	.dw $E3
; ( -- addr ) System Constant
; R( -- )
; 
VE_UDCON:
	.dw $ff05
	.db "UDCON",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UDCON
XT_UDCON:
	.dw PFA_DOVARIABLE
PFA_UDCON:
	.dw $E0
; ( -- addr ) System Constant
; R( -- )
; 
VE_UDFNUMH:
	.dw $ff07
	.db "UDFNUMH",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UDFNUMH
XT_UDFNUMH:
	.dw PFA_DOVARIABLE
PFA_UDFNUMH:
	.dw $E5
; ( -- addr ) System Constant
; R( -- )
; 
VE_UDFNUML:
	.dw $ff07
	.db "UDFNUML",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UDFNUML
XT_UDFNUML:
	.dw PFA_DOVARIABLE
PFA_UDFNUML:
	.dw $E4
; ( -- addr ) System Constant
; R( -- )
; 
VE_UDIEN:
	.dw $ff05
	.db "UDIEN",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UDIEN
XT_UDIEN:
	.dw PFA_DOVARIABLE
PFA_UDIEN:
	.dw $E2
; ( -- addr ) System Constant
; R( -- )
; 
VE_UDINT:
	.dw $ff05
	.db "UDINT",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UDINT
XT_UDINT:
	.dw PFA_DOVARIABLE
PFA_UDINT:
	.dw $E1
; ( -- addr ) System Constant
; R( -- )
; 
VE_UDMFN:
	.dw $ff05
	.db "UDMFN",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UDMFN
XT_UDMFN:
	.dw PFA_DOVARIABLE
PFA_UDMFN:
	.dw $E6
; ( -- addr ) System Constant
; R( -- )
; 
VE_UEBCHX:
	.dw $ff06
	.db "UEBCHX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UEBCHX
XT_UEBCHX:
	.dw PFA_DOVARIABLE
PFA_UEBCHX:
	.dw $F3
; ( -- addr ) System Constant
; R( -- )
; 
VE_UEBCLX:
	.dw $ff06
	.db "UEBCLX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UEBCLX
XT_UEBCLX:
	.dw PFA_DOVARIABLE
PFA_UEBCLX:
	.dw $F2
; ( -- addr ) System Constant
; R( -- )
; 
VE_UECFG0X:
	.dw $ff07
	.db "UECFG0X",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UECFG0X
XT_UECFG0X:
	.dw PFA_DOVARIABLE
PFA_UECFG0X:
	.dw $EC
; ( -- addr ) System Constant
; R( -- )
; 
VE_UECFG1X:
	.dw $ff07
	.db "UECFG1X",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UECFG1X
XT_UECFG1X:
	.dw PFA_DOVARIABLE
PFA_UECFG1X:
	.dw $ED
; ( -- addr ) System Constant
; R( -- )
; 
VE_UECONX:
	.dw $ff06
	.db "UECONX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UECONX
XT_UECONX:
	.dw PFA_DOVARIABLE
PFA_UECONX:
	.dw $EB
; ( -- addr ) System Constant
; R( -- )
; 
VE_UEDATX:
	.dw $ff06
	.db "UEDATX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UEDATX
XT_UEDATX:
	.dw PFA_DOVARIABLE
PFA_UEDATX:
	.dw $F1
; ( -- addr ) System Constant
; R( -- )
; 
VE_UEIENX:
	.dw $ff06
	.db "UEIENX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UEIENX
XT_UEIENX:
	.dw PFA_DOVARIABLE
PFA_UEIENX:
	.dw $F0
; ( -- addr ) System Constant
; R( -- )
; 
VE_UEINT:
	.dw $ff05
	.db "UEINT",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UEINT
XT_UEINT:
	.dw PFA_DOVARIABLE
PFA_UEINT:
	.dw $F4
; ( -- addr ) System Constant
; R( -- )
; 
VE_UEINTX:
	.dw $ff06
	.db "UEINTX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UEINTX
XT_UEINTX:
	.dw PFA_DOVARIABLE
PFA_UEINTX:
	.dw $E8
; ( -- addr ) System Constant
; R( -- )
; 
VE_UENUM:
	.dw $ff05
	.db "UENUM",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UENUM
XT_UENUM:
	.dw PFA_DOVARIABLE
PFA_UENUM:
	.dw $E9
; ( -- addr ) System Constant
; R( -- )
; 
VE_UERST:
	.dw $ff05
	.db "UERST",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UERST
XT_UERST:
	.dw PFA_DOVARIABLE
PFA_UERST:
	.dw $EA
; ( -- addr ) System Constant
; R( -- )
; 
VE_UESTA0X:
	.dw $ff07
	.db "UESTA0X",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UESTA0X
XT_UESTA0X:
	.dw PFA_DOVARIABLE
PFA_UESTA0X:
	.dw $EE
; ( -- addr ) System Constant
; R( -- )
; 
VE_UESTA1X:
	.dw $ff07
	.db "UESTA1X",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UESTA1X
XT_UESTA1X:
	.dw PFA_DOVARIABLE
PFA_UESTA1X:
	.dw $EF

.endif

; ********
.if WANT_USB_GLOBAL == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; 
VE_OTGCON:
	.dw $ff06
	.db "OTGCON"
	.dw VE_HEAD
	.set VE_HEAD=VE_OTGCON
XT_OTGCON:
	.dw PFA_DOVARIABLE
PFA_OTGCON:
	.dw $DD
; ( -- addr ) System Constant
; R( -- )
; 
VE_OTGIEN:
	.dw $ff06
	.db "OTGIEN"
	.dw VE_HEAD
	.set VE_HEAD=VE_OTGIEN
XT_OTGIEN:
	.dw PFA_DOVARIABLE
PFA_OTGIEN:
	.dw $DE
; ( -- addr ) System Constant
; R( -- )
; 
VE_OTGINT:
	.dw $ff06
	.db "OTGINT"
	.dw VE_HEAD
	.set VE_HEAD=VE_OTGINT
XT_OTGINT:
	.dw PFA_DOVARIABLE
PFA_OTGINT:
	.dw $DF
; ( -- addr ) System Constant
; R( -- )
; 
VE_OTGTCON:
	.dw $ff07
	.db "OTGTCON",0
	.dw VE_HEAD
	.set VE_HEAD=VE_OTGTCON
XT_OTGTCON:
	.dw PFA_DOVARIABLE
PFA_OTGTCON:
	.dw $F9
; ( -- addr ) System Constant
; R( -- )
; USB Hardware Configuration Register
VE_UHWCON:
	.dw $ff06
	.db "UHWCON"
	.dw VE_HEAD
	.set VE_HEAD=VE_UHWCON
XT_UHWCON:
	.dw PFA_DOVARIABLE
PFA_UHWCON:
	.dw $D7
; ( -- addr ) System Constant
; R( -- )
; USB General Control Register
VE_USBCON:
	.dw $ff06
	.db "USBCON"
	.dw VE_HEAD
	.set VE_HEAD=VE_USBCON
XT_USBCON:
	.dw PFA_DOVARIABLE
PFA_USBCON:
	.dw $D8
; ( -- addr ) System Constant
; R( -- )
; 
VE_USBINT:
	.dw $ff06
	.db "USBINT"
	.dw VE_HEAD
	.set VE_HEAD=VE_USBINT
XT_USBINT:
	.dw PFA_DOVARIABLE
PFA_USBINT:
	.dw $DA
; ( -- addr ) System Constant
; R( -- )
; 
VE_USBSTA:
	.dw $ff06
	.db "USBSTA"
	.dw VE_HEAD
	.set VE_HEAD=VE_USBSTA
XT_USBSTA:
	.dw PFA_DOVARIABLE
PFA_USBSTA:
	.dw $D9

.endif

; ********
.if WANT_USB_HOST == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; 
VE_UHADDR:
	.dw $ff06
	.db "UHADDR"
	.dw VE_HEAD
	.set VE_HEAD=VE_UHADDR
XT_UHADDR:
	.dw PFA_DOVARIABLE
PFA_UHADDR:
	.dw $A1
; ( -- addr ) System Constant
; R( -- )
; 
VE_UHCON:
	.dw $ff05
	.db "UHCON",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UHCON
XT_UHCON:
	.dw PFA_DOVARIABLE
PFA_UHCON:
	.dw $9E
; ( -- addr ) System Constant
; R( -- )
; 
VE_UHFLEN:
	.dw $ff06
	.db "UHFLEN"
	.dw VE_HEAD
	.set VE_HEAD=VE_UHFLEN
XT_UHFLEN:
	.dw PFA_DOVARIABLE
PFA_UHFLEN:
	.dw $A4
; ( -- addr ) System Constant
; R( -- )
; 
VE_UHFNUMH:
	.dw $ff07
	.db "UHFNUMH",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UHFNUMH
XT_UHFNUMH:
	.dw PFA_DOVARIABLE
PFA_UHFNUMH:
	.dw $A3
; ( -- addr ) System Constant
; R( -- )
; 
VE_UHFNUML:
	.dw $ff07
	.db "UHFNUML",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UHFNUML
XT_UHFNUML:
	.dw PFA_DOVARIABLE
PFA_UHFNUML:
	.dw $A2
; ( -- addr ) System Constant
; R( -- )
; 
VE_UHIEN:
	.dw $ff05
	.db "UHIEN",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UHIEN
XT_UHIEN:
	.dw PFA_DOVARIABLE
PFA_UHIEN:
	.dw $A0
; ( -- addr ) System Constant
; R( -- )
; 
VE_UHINT:
	.dw $ff05
	.db "UHINT",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UHINT
XT_UHINT:
	.dw PFA_DOVARIABLE
PFA_UHINT:
	.dw $9F
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPBCHX:
	.dw $ff06
	.db "UPBCHX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UPBCHX
XT_UPBCHX:
	.dw PFA_DOVARIABLE
PFA_UPBCHX:
	.dw $F7
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPBCLX:
	.dw $ff06
	.db "UPBCLX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UPBCLX
XT_UPBCLX:
	.dw PFA_DOVARIABLE
PFA_UPBCLX:
	.dw $F6
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPCFG0X:
	.dw $ff07
	.db "UPCFG0X",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UPCFG0X
XT_UPCFG0X:
	.dw PFA_DOVARIABLE
PFA_UPCFG0X:
	.dw $AA
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPCFG1X:
	.dw $ff07
	.db "UPCFG1X",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UPCFG1X
XT_UPCFG1X:
	.dw PFA_DOVARIABLE
PFA_UPCFG1X:
	.dw $AB
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPCFG2X:
	.dw $ff07
	.db "UPCFG2X",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UPCFG2X
XT_UPCFG2X:
	.dw PFA_DOVARIABLE
PFA_UPCFG2X:
	.dw $AD
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPCONX:
	.dw $ff06
	.db "UPCONX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UPCONX
XT_UPCONX:
	.dw PFA_DOVARIABLE
PFA_UPCONX:
	.dw $A9
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPDATX:
	.dw $ff06
	.db "UPDATX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UPDATX
XT_UPDATX:
	.dw PFA_DOVARIABLE
PFA_UPDATX:
	.dw $AF
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPERRX:
	.dw $ff06
	.db "UPERRX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UPERRX
XT_UPERRX:
	.dw PFA_DOVARIABLE
PFA_UPERRX:
	.dw $F5
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPIENX:
	.dw $ff06
	.db "UPIENX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UPIENX
XT_UPIENX:
	.dw PFA_DOVARIABLE
PFA_UPIENX:
	.dw $AE
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPINRQX:
	.dw $ff07
	.db "UPINRQX",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UPINRQX
XT_UPINRQX:
	.dw PFA_DOVARIABLE
PFA_UPINRQX:
	.dw $A5
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPINT:
	.dw $ff05
	.db "UPINT",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UPINT
XT_UPINT:
	.dw PFA_DOVARIABLE
PFA_UPINT:
	.dw $F8
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPINTX:
	.dw $ff06
	.db "UPINTX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UPINTX
XT_UPINTX:
	.dw PFA_DOVARIABLE
PFA_UPINTX:
	.dw $A6
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPNUM:
	.dw $ff05
	.db "UPNUM",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UPNUM
XT_UPNUM:
	.dw PFA_DOVARIABLE
PFA_UPNUM:
	.dw $A7
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPRST:
	.dw $ff05
	.db "UPRST",0
	.dw VE_HEAD
	.set VE_HEAD=VE_UPRST
XT_UPRST:
	.dw PFA_DOVARIABLE
PFA_UPRST:
	.dw $A8
; ( -- addr ) System Constant
; R( -- )
; 
VE_UPSTAX:
	.dw $ff06
	.db "UPSTAX"
	.dw VE_HEAD
	.set VE_HEAD=VE_UPSTAX
XT_UPSTAX:
	.dw PFA_DOVARIABLE
PFA_UPSTAX:
	.dw $AC

.endif

; ********
.if WANT_WATCHDOG == 1
; ********
; ( -- addr ) System Constant
; R( -- )
; Watchdog Timer Control Register
VE_WDTCSR:
	.dw $ff06
	.db "WDTCSR"
	.dw VE_HEAD
	.set VE_HEAD=VE_WDTCSR
XT_WDTCSR:
	.dw PFA_DOVARIABLE
PFA_WDTCSR:
	.dw $60

.endif