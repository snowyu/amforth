# Partname:  ATmega128
# generated automatically, do not edit
MCUREGS = {
	'SFIOR': '&64',
	  'SFIOR_ACME': '$08',
	'ACSR': '&40',
	  'ACSR_ACD': '$80',
	  'ACSR_ACBG': '$40',
	  'ACSR_ACO': '$20',
	  'ACSR_ACI': '$10',
	  'ACSR_ACIE': '$08',
	  'ACSR_ACIC': '$04',
	  'ACSR_ACIS': '$03',
	'SPDR': '&47',
	'SPSR': '&46',
	  'SPSR_SPIF': '$80',
	  'SPSR_WCOL': '$40',
	  'SPSR_SPI2X': '$01',
	'SPCR': '&45',
	  'SPCR_SPIE': '$80',
	  'SPCR_SPE': '$40',
	  'SPCR_DORD': '$20',
	  'SPCR_MSTR': '$10',
	  'SPCR_CPOL': '$08',
	  'SPCR_CPHA': '$04',
	  'SPCR_SPR': '$03',
	'TWBR': '&112',
	'TWCR': '&116',
	  'TWCR_TWINT': '$80',
	  'TWCR_TWEA': '$40',
	  'TWCR_TWSTA': '$20',
	  'TWCR_TWSTO': '$10',
	  'TWCR_TWWC': '$08',
	  'TWCR_TWEN': '$04',
	  'TWCR_TWIE': '$01',
	'TWSR': '&113',
	  'TWSR_TWS': '$F8',
	  'TWSR_TWPS': '$03',
	'TWDR': '&115',
	'TWAR': '&114',
	  'TWAR_TWA': '$FE',
	  'TWAR_TWGCE': '$01',
	'UDR0': '&44',
	'UCSR0A': '&43',
	  'UCSR0A_RXC0': '$80',
	  'UCSR0A_TXC0': '$40',
	  'UCSR0A_UDRE0': '$20',
	  'UCSR0A_FE0': '$10',
	  'UCSR0A_DOR0': '$08',
	  'UCSR0A_UPE0': '$04',
	  'UCSR0A_U2X0': '$02',
	  'UCSR0A_MPCM0': '$01',
	'UCSR0B': '&42',
	  'UCSR0B_RXCIE0': '$80',
	  'UCSR0B_TXCIE0': '$40',
	  'UCSR0B_UDRIE0': '$20',
	  'UCSR0B_RXEN0': '$10',
	  'UCSR0B_TXEN0': '$08',
	  'UCSR0B_UCSZ02': '$04',
	  'UCSR0B_RXB80': '$02',
	  'UCSR0B_TXB80': '$01',
	'UCSR0C': '&149',
	  'UCSR0C_UMSEL0': '$40',
	  'UCSR0C_UPM0': '$30',
	  'UCSR0C_USBS0': '$08',
	  'UCSR0C_UCSZ0': '$06',
	  'UCSR0C_UCPOL0': '$01',
	'UBRR0H': '&144',
	'UBRR0L': '&41',
	'UDR1': '&156',
	'UCSR1A': '&155',
	  'UCSR1A_RXC1': '$80',
	  'UCSR1A_TXC1': '$40',
	  'UCSR1A_UDRE1': '$20',
	  'UCSR1A_FE1': '$10',
	  'UCSR1A_DOR1': '$08',
	  'UCSR1A_UPE1': '$04',
	  'UCSR1A_U2X1': '$02',
	  'UCSR1A_MPCM1': '$01',
	'UCSR1B': '&154',
	  'UCSR1B_RXCIE1': '$80',
	  'UCSR1B_TXCIE1': '$40',
	  'UCSR1B_UDRIE1': '$20',
	  'UCSR1B_RXEN1': '$10',
	  'UCSR1B_TXEN1': '$08',
	  'UCSR1B_UCSZ12': '$04',
	  'UCSR1B_RXB81': '$02',
	  'UCSR1B_TXB81': '$01',
	'UCSR1C': '&157',
	  'UCSR1C_UMSEL1': '$40',
	  'UCSR1C_UPM1': '$30',
	  'UCSR1C_USBS1': '$08',
	  'UCSR1C_UCSZ1': '$06',
	  'UCSR1C_UCPOL1': '$01',
	'UBRR1H': '&152',
	'UBRR1L': '&153',
	'SREG': '&95',
	  'SREG_I': '$80',
	  'SREG_T': '$40',
	  'SREG_H': '$20',
	  'SREG_S': '$10',
	  'SREG_V': '$08',
	  'SREG_N': '$04',
	  'SREG_Z': '$02',
	  'SREG_C': '$01',
	'SP': '&93',
	'MCUCR': '&85',
	  'MCUCR_SRE': '$80',
	  'MCUCR_SRW10': '$40',
	  'MCUCR_SE': '$20',
	  'MCUCR_SM': '$18',
	  'MCUCR_SM2': '$04',
	  'MCUCR_IVSEL': '$02',
	  'MCUCR_IVCE': '$01',
	'MCUCSR': '&84',
	  'MCUCSR_JTD': '$80',
	  'MCUCSR_JTRF': '$10',
	  'MCUCSR_WDRF': '$08',
	  'MCUCSR_BORF': '$04',
	  'MCUCSR_EXTRF': '$02',
	  'MCUCSR_PORF': '$01',
	'XMCRA': '&109',
	  'XMCRA_SRL': '$70',
	  'XMCRA_SRW0': '$0C',
	  'XMCRA_SRW11': '$02',
	'XMCRB': '&108',
	  'XMCRB_XMBK': '$80',
	  'XMCRB_XMM': '$07',
	'OSCCAL': '&111',
	'XDIV': '&92',
	'RAMPZ': '&91',
	  'RAMPZ_RAMPZ0': '$01',
	'SPMCSR': '&104',
	  'SPMCSR_SPMIE': '$80',
	  'SPMCSR_RWWSB': '$40',
	  'SPMCSR_RWWSRE': '$10',
	  'SPMCSR_BLBSET': '$08',
	  'SPMCSR_PGWRT': '$04',
	  'SPMCSR_PGERS': '$02',
	  'SPMCSR_SPMEN': '$01',
	'OCDR': '&66',
	  'OCDR_OCDR': '$FF',
	'EICRA': '&106',
	  'EICRA_ISC3': '$C0',
	  'EICRA_ISC2': '$30',
	  'EICRA_ISC1': '$0C',
	  'EICRA_ISC0': '$03',
	'EICRB': '&90',
	  'EICRB_ISC7': '$C0',
	  'EICRB_ISC6': '$30',
	  'EICRB_ISC5': '$0C',
	  'EICRB_ISC4': '$03',
	'EIMSK': '&89',
	  'EIMSK_INT': '$FF',
	'EIFR': '&88',
	  'EIFR_INTF': '$FF',
	'EEAR': '&62',
	'EEDR': '&61',
	'EECR': '&60',
	  'EECR_EERIE': '$08',
	  'EECR_EEMWE': '$04',
	  'EECR_EEWE': '$02',
	  'EECR_EERE': '$01',
	'PORTA': '&59',
	'DDRA': '&58',
	'PINA': '&57',
	'PORTB': '&56',
	'DDRB': '&55',
	'PINB': '&54',
	'PORTC': '&53',
	'DDRC': '&52',
	'PINC': '&51',
	'PORTD': '&50',
	'DDRD': '&49',
	'PIND': '&48',
	'PORTE': '&35',
	'DDRE': '&34',
	'PINE': '&33',
	'PORTF': '&98',
	'DDRF': '&97',
	'PINF': '&32',
	'PORTG': '&101',
	'DDRG': '&100',
	'PING': '&99',
	'TCCR0': '&83',
	  'TCCR0_FOC0': '$80',
	  'TCCR0_WGM00': '$40',
	  'TCCR0_COM0': '$30',
	  'TCCR0_WGM01': '$08',
	  'TCCR0_CS0': '$07',
	'TCNT0': '&82',
	'OCR0': '&81',
	'ASSR': '&80',
	  'ASSR_AS0': '$08',
	  'ASSR_TCN0UB': '$04',
	  'ASSR_OCR0UB': '$02',
	  'ASSR_TCR0UB': '$01',
	'TIMSK': '&87',
	  'TIMSK_OCIE0': '$02',
	  'TIMSK_TOIE0': '$01',
	'TIFR': '&86',
	  'TIFR_OCF0': '$02',
	  'TIFR_TOV0': '$01',
	'ETIMSK': '&125',
	  'ETIMSK_OCIE1C': '$01',
	'ETIFR': '&124',
	  'ETIFR_OCF1C': '$01',
	'TCCR1A': '&79',
	  'TCCR1A_COM1A': '$C0',
	  'TCCR1A_COM1B': '$30',
	  'TCCR1A_COM1C': '$0C',
	  'TCCR1A_WGM1': '$03',
	'TCCR1B': '&78',
	  'TCCR1B_ICNC1': '$80',
	  'TCCR1B_ICES1': '$40',
	  'TCCR1B_WGM1': '$18',
	  'TCCR1B_CS1': '$07',
	'TCCR1C': '&122',
	  'TCCR1C_FOC1A': '$80',
	  'TCCR1C_FOC1B': '$40',
	  'TCCR1C_FOC1C': '$20',
	'TCNT1': '&76',
	'OCR1A': '&74',
	'OCR1B': '&72',
	'OCR1C': '&120',
	'ICR1': '&70',
	'TCCR2': '&69',
	  'TCCR2_FOC2': '$80',
	  'TCCR2_WGM20': '$40',
	  'TCCR2_COM2': '$30',
	  'TCCR2_WGM21': '$08',
	  'TCCR2_CS2': '$07',
	'TCNT2': '&68',
	'OCR2': '&67',
	'TCCR3A': '&139',
	  'TCCR3A_COM3A': '$C0',
	  'TCCR3A_COM3B': '$30',
	  'TCCR3A_COM3C': '$0C',
	  'TCCR3A_WGM3': '$03',
	'TCCR3B': '&138',
	  'TCCR3B_ICNC3': '$80',
	  'TCCR3B_ICES3': '$40',
	  'TCCR3B_WGM3': '$18',
	  'TCCR3B_CS3': '$07',
	'TCCR3C': '&140',
	  'TCCR3C_FOC3A': '$80',
	  'TCCR3C_FOC3B': '$40',
	  'TCCR3C_FOC3C': '$20',
	'TCNT3': '&136',
	'OCR3A': '&134',
	'OCR3B': '&132',
	'OCR3C': '&130',
	'ICR3': '&128',
	'WDTCR': '&65',
	  'WDTCR_WDCE': '$10',
	  'WDTCR_WDE': '$08',
	  'WDTCR_WDP': '$07',
	'ADMUX': '&39',
	  'ADMUX_REFS': '$C0',
	  'ADMUX_ADLAR': '$20',
	  'ADMUX_MUX': '$1F',
	'ADCSRA': '&38',
	  'ADCSRA_ADEN': '$80',
	  'ADCSRA_ADSC': '$40',
	  'ADCSRA_ADFR': '$20',
	  'ADCSRA_ADIF': '$10',
	  'ADCSRA_ADIE': '$08',
	  'ADCSRA_ADPS': '$07',
	'ADC': '&36',
	'INT0Addr': '2',
	'INT1Addr': '4',
	'INT2Addr': '6',
	'INT3Addr': '8',
	'INT4Addr': '10',
	'INT5Addr': '12',
	'INT6Addr': '14',
	'INT7Addr': '16',
	'TIMER2_COMPAddr': '18',
	'TIMER2_OVFAddr': '20',
	'TIMER1_CAPTAddr': '22',
	'TIMER1_COMPAAddr': '24',
	'TIMER1_COMPBAddr': '26',
	'TIMER1_OVFAddr': '28',
	'TIMER0_COMPAddr': '30',
	'TIMER0_OVFAddr': '32',
	'SPI__STCAddr': '34',
	'USART0__RXAddr': '36',
	'USART0__UDREAddr': '38',
	'USART0__TXAddr': '40',
	'ADCAddr': '42',
	'EE_READYAddr': '44',
	'ANALOG_COMPAddr': '46',
	'TIMER1_COMPCAddr': '48',
	'TIMER3_CAPTAddr': '50',
	'TIMER3_COMPAAddr': '52',
	'TIMER3_COMPBAddr': '54',
	'TIMER3_COMPCAddr': '56',
	'TIMER3_OVFAddr': '58',
	'USART1__RXAddr': '60',
	'USART1__UDREAddr': '62',
	'USART1__TXAddr': '64',
	'TWIAddr': '66',
	'SPM_READYAddr': '68'
}