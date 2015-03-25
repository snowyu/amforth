# Partname:  ATmega32U2
# generated automatically, do not edit
MCUREGS = {
	'PORTB': '&37',
	'DDRB': '&36',
	'PINB': '&35',
	'PORTD': '&43',
	'DDRD': '&42',
	'PIND': '&41',
	'SPCR': '&76',
	  'SPCR_SPIE': '$80',
	  'SPCR_SPE': '$40',
	  'SPCR_DORD': '$20',
	  'SPCR_MSTR': '$10',
	  'SPCR_CPOL': '$08',
	  'SPCR_CPHA': '$04',
	  'SPCR_SPR': '$03',
	'SPSR': '&77',
	  'SPSR_SPIF': '$80',
	  'SPSR_WCOL': '$40',
	  'SPSR_SPI2X': '$01',
	'SPDR': '&78',
	'SPMCSR': '&87',
	  'SPMCSR_SPMIE': '$80',
	  'SPMCSR_RWWSB': '$40',
	  'SPMCSR_SIGRD': '$20',
	  'SPMCSR_RWWSRE': '$10',
	  'SPMCSR_BLBSET': '$08',
	  'SPMCSR_PGWRT': '$04',
	  'SPMCSR_PGERS': '$02',
	  'SPMCSR_SPMEN': '$01',
	'EEAR': '&65',
	'EEDR': '&64',
	'EECR': '&63',
	  'EECR_EEPM': '$30',
	  'EECR_EERIE': '$08',
	  'EECR_EEMPE': '$04',
	  'EECR_EEPE': '$02',
	  'EECR_EERE': '$01',
	'OCR0B': '&72',
	'OCR0A': '&71',
	'TCNT0': '&70',
	'TCCR0B': '&69',
	  'TCCR0B_FOC0A': '$80',
	  'TCCR0B_FOC0B': '$40',
	  'TCCR0B_WGM02': '$08',
	  'TCCR0B_CS0': '$07',
	'TCCR0A': '&68',
	  'TCCR0A_COM0A': '$C0',
	  'TCCR0A_COM0B': '$30',
	  'TCCR0A_WGM0': '$03',
	'TIMSK0': '&110',
	  'TIMSK0_OCIE0B': '$04',
	  'TIMSK0_OCIE0A': '$02',
	  'TIMSK0_TOIE0': '$01',
	'TIFR0': '&53',
	  'TIFR0_OCF0B': '$04',
	  'TIFR0_OCF0A': '$02',
	  'TIFR0_TOV0': '$01',
	'GTCCR': '&67',
	  'GTCCR_TSM': '$80',
	  'GTCCR_PSRSYNC': '$01',
	'TCCR1A': '&128',
	  'TCCR1A_COM1A': '$C0',
	  'TCCR1A_COM1B': '$30',
	  'TCCR1A_COM1C': '$0C',
	  'TCCR1A_WGM1': '$03',
	'TCCR1B': '&129',
	  'TCCR1B_ICNC1': '$80',
	  'TCCR1B_ICES1': '$40',
	  'TCCR1B_WGM1': '$18',
	  'TCCR1B_CS1': '$07',
	'TCCR1C': '&130',
	  'TCCR1C_FOC1A': '$80',
	  'TCCR1C_FOC1B': '$40',
	  'TCCR1C_FOC1C': '$20',
	'TCNT1': '&132',
	'OCR1A': '&136',
	'OCR1B': '&138',
	'OCR1C': '&140',
	'ICR1': '&134',
	'TIMSK1': '&111',
	  'TIMSK1_ICIE1': '$20',
	  'TIMSK1_OCIE1C': '$08',
	  'TIMSK1_OCIE1B': '$04',
	  'TIMSK1_OCIE1A': '$02',
	  'TIMSK1_TOIE1': '$01',
	'TIFR1': '&54',
	  'TIFR1_ICF1': '$20',
	  'TIFR1_OCF1C': '$08',
	  'TIFR1_OCF1B': '$04',
	  'TIFR1_OCF1A': '$02',
	  'TIFR1_TOV1': '$01',
	'PLLCSR': '&73',
	  'PLLCSR_PLLP': '$1C',
	  'PLLCSR_PLLE': '$02',
	  'PLLCSR_PLOCK': '$01',
	'UEINT': '&244',
	'UEBCLX': '&242',
	'UEDATX': '&241',
	'UEIENX': '&240',
	  'UEIENX_FLERRE': '$80',
	  'UEIENX_NAKINE': '$40',
	  'UEIENX_NAKOUTE': '$10',
	  'UEIENX_RXSTPE': '$08',
	  'UEIENX_RXOUTE': '$04',
	  'UEIENX_STALLEDE': '$02',
	  'UEIENX_TXINE': '$01',
	'UESTA1X': '&239',
	  'UESTA1X_CTRLDIR': '$04',
	  'UESTA1X_CURRBK': '$03',
	'UESTA0X': '&238',
	  'UESTA0X_CFGOK': '$80',
	  'UESTA0X_OVERFI': '$40',
	  'UESTA0X_UNDERFI': '$20',
	  'UESTA0X_DTSEQ': '$0C',
	  'UESTA0X_NBUSYBK': '$03',
	'UECFG1X': '&237',
	  'UECFG1X_EPSIZE': '$70',
	  'UECFG1X_EPBK': '$0C',
	  'UECFG1X_ALLOC': '$02',
	'UECFG0X': '&236',
	  'UECFG0X_EPTYPE': '$C0',
	  'UECFG0X_EPDIR': '$01',
	'UECONX': '&235',
	  'UECONX_STALLRQ': '$20',
	  'UECONX_STALLRQC': '$10',
	  'UECONX_RSTDT': '$08',
	  'UECONX_EPEN': '$01',
	'UERST': '&234',
	  'UERST_EPRST': '$1F',
	'UENUM': '&233',
	'UEINTX': '&232',
	  'UEINTX_FIFOCON': '$80',
	  'UEINTX_NAKINI': '$40',
	  'UEINTX_RWAL': '$20',
	  'UEINTX_NAKOUTI': '$10',
	  'UEINTX_RXSTPI': '$08',
	  'UEINTX_RXOUTI': '$04',
	  'UEINTX_STALLEDI': '$02',
	  'UEINTX_TXINI': '$01',
	'UDMFN': '&230',
	  'UDMFN_FNCERR': '$10',
	'UDFNUM': '&228',
	'UDADDR': '&227',
	  'UDADDR_ADDEN': '$80',
	  'UDADDR_UADD': '$7F',
	'UDIEN': '&226',
	  'UDIEN_UPRSME': '$40',
	  'UDIEN_EORSME': '$20',
	  'UDIEN_WAKEUPE': '$10',
	  'UDIEN_EORSTE': '$08',
	  'UDIEN_SOFE': '$04',
	  'UDIEN_SUSPE': '$01',
	'UDINT': '&225',
	  'UDINT_UPRSMI': '$40',
	  'UDINT_EORSMI': '$20',
	  'UDINT_WAKEUPI': '$10',
	  'UDINT_EORSTI': '$08',
	  'UDINT_SOFI': '$04',
	  'UDINT_SUSPI': '$01',
	'UDCON': '&224',
	  'UDCON_RSTCPU': '$04',
	  'UDCON_RMWKUP': '$02',
	  'UDCON_DETACH': '$01',
	'USBCON': '&216',
	  'USBCON_USBE': '$80',
	  'USBCON_FRZCLK': '$20',
	'REGCR': '&99',
	  'REGCR_REGDIS': '$01',
	'UPOE': '&251',
	  'UPOE_UPWE': '$C0',
	  'UPOE_UPDRV': '$30',
	  'UPOE_SCKI': '$08',
	  'UPOE_DATAI': '$04',
	  'UPOE_DPI': '$02',
	  'UPOE_DMI': '$01',
	'PS2CON': '&250',
	  'PS2CON_PS2EN': '$01',
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
	  'MCUCR_PUD': '$10',
	  'MCUCR_IVSEL': '$02',
	  'MCUCR_IVCE': '$01',
	'MCUSR': '&84',
	  'MCUSR_USBRF': '$20',
	  'MCUSR_WDRF': '$08',
	  'MCUSR_BORF': '$04',
	  'MCUSR_EXTRF': '$02',
	  'MCUSR_PORF': '$01',
	'OSCCAL': '&102',
	'CLKPR': '&97',
	  'CLKPR_CLKPCE': '$80',
	  'CLKPR_CLKPS': '$0F',
	'SMCR': '&83',
	  'SMCR_SM': '$0E',
	  'SMCR_SE': '$01',
	'EIND': '&92',
	'GPIOR2': '&75',
	  'GPIOR2_GPIOR': '$FF',
	'GPIOR1': '&74',
	  'GPIOR1_GPIOR': '$FF',
	'GPIOR0': '&62',
	  'GPIOR0_GPIOR07': '$80',
	  'GPIOR0_GPIOR06': '$40',
	  'GPIOR0_GPIOR05': '$20',
	  'GPIOR0_GPIOR04': '$10',
	  'GPIOR0_GPIOR03': '$08',
	  'GPIOR0_GPIOR02': '$04',
	  'GPIOR0_GPIOR01': '$02',
	  'GPIOR0_GPIOR00': '$01',
	'PRR1': '&101',
	  'PRR1_PRUSB': '$80',
	  'PRR1_PRUSART1': '$01',
	'PRR0': '&100',
	  'PRR0_PRTIM0': '$20',
	  'PRR0_PRTIM1': '$08',
	  'PRR0_PRSPI': '$04',
	'CLKSTA': '&210',
	  'CLKSTA_RCON': '$02',
	  'CLKSTA_EXTON': '$01',
	'CLKSEL1': '&209',
	  'CLKSEL1_RCCKSEL': '$F0',
	  'CLKSEL1_EXCKSEL': '$0F',
	'CLKSEL0': '&208',
	  'CLKSEL0_RCSUT': '$C0',
	  'CLKSEL0_EXSUT': '$30',
	  'CLKSEL0_RCE': '$08',
	  'CLKSEL0_EXTE': '$04',
	  'CLKSEL0_CLKS': '$01',
	'DWDR': '&81',
	'EICRA': '&105',
	  'EICRA_ISC3': '$C0',
	  'EICRA_ISC2': '$30',
	  'EICRA_ISC1': '$0C',
	  'EICRA_ISC0': '$03',
	'EICRB': '&106',
	  'EICRB_ISC7': '$C0',
	  'EICRB_ISC6': '$30',
	  'EICRB_ISC5': '$0C',
	  'EICRB_ISC4': '$03',
	'EIMSK': '&61',
	  'EIMSK_INT': '$FF',
	'EIFR': '&60',
	  'EIFR_INTF': '$FF',
	'PCMSK0': '&107',
	  'PCMSK0_PCINT': '$FF',
	'PCMSK1': '&108',
	  'PCMSK1_PCINT': '$1F',
	'PCIFR': '&59',
	  'PCIFR_PCIF': '$03',
	'PCICR': '&104',
	  'PCICR_PCIE': '$03',
	'UDR1': '&206',
	'UCSR1A': '&200',
	  'UCSR1A_RXC1': '$80',
	  'UCSR1A_TXC1': '$40',
	  'UCSR1A_UDRE1': '$20',
	  'UCSR1A_FE1': '$10',
	  'UCSR1A_DOR1': '$08',
	  'UCSR1A_UPE1': '$04',
	  'UCSR1A_U2X1': '$02',
	  'UCSR1A_MPCM1': '$01',
	'UCSR1B': '&201',
	  'UCSR1B_RXCIE1': '$80',
	  'UCSR1B_TXCIE1': '$40',
	  'UCSR1B_UDRIE1': '$20',
	  'UCSR1B_RXEN1': '$10',
	  'UCSR1B_TXEN1': '$08',
	  'UCSR1B_UCSZ12': '$04',
	  'UCSR1B_RXB81': '$02',
	  'UCSR1B_TXB81': '$01',
	'UCSR1C': '&202',
	  'UCSR1C_UMSEL1': '$C0',
	  'UCSR1C_UPM1': '$30',
	  'UCSR1C_USBS1': '$08',
	  'UCSR1C_UCSZ1': '$06',
	  'UCSR1C_UCPOL1': '$01',
	'UCSR1D': '&203',
	  'UCSR1D_CTSEN': '$02',
	  'UCSR1D_RTSEN': '$01',
	'UBRR1': '&204',
	'WDTCSR': '&96',
	  'WDTCSR_WDIF': '$80',
	  'WDTCSR_WDIE': '$40',
	  'WDTCSR_WDP': '$27',
	  'WDTCSR_WDCE': '$10',
	  'WDTCSR_WDE': '$08',
	'WDTCKD': '&98',
	  'WDTCKD_WDEWIF': '$08',
	  'WDTCKD_WDEWIE': '$04',
	  'WDTCKD_WCLKD': '$03',
	'ACSR': '&80',
	  'ACSR_ACD': '$80',
	  'ACSR_ACBG': '$40',
	  'ACSR_ACO': '$20',
	  'ACSR_ACI': '$10',
	  'ACSR_ACIE': '$08',
	  'ACSR_ACIC': '$04',
	  'ACSR_ACIS': '$03',
	'DIDR1': '&127',
	  'DIDR1_AIN1D': '$02',
	  'DIDR1_AIN0D': '$01',
	'PORTC': '&40',
	  'PORTC_PORTC': '$F0',
	  'PORTC_PORTC': '$07',
	'DDRC': '&39',
	  'DDRC_DDC': '$F0',
	  'DDRC_DDC': '$07',
	'PINC': '&38',
	  'PINC_PINC': '$F0',
	  'PINC_PINC': '$07',
	'INT0Addr': '2',
	'INT1Addr': '4',
	'INT2Addr': '6',
	'INT3Addr': '8',
	'INT4Addr': '10',
	'INT5Addr': '12',
	'INT6Addr': '14',
	'INT7Addr': '16',
	'PCINT0Addr': '18',
	'PCINT1Addr': '20',
	'USB_GENAddr': '22',
	'USB_COMAddr': '24',
	'WDTAddr': '26',
	'TIMER1_CAPTAddr': '28',
	'TIMER1_COMPAAddr': '30',
	'TIMER1_COMPBAddr': '32',
	'TIMER1_COMPCAddr': '34',
	'TIMER1_OVFAddr': '36',
	'TIMER0_COMPAAddr': '38',
	'TIMER0_COMPBAddr': '40',
	'TIMER0_OVFAddr': '42',
	'SPI__STCAddr': '44',
	'USART1__RXAddr': '46',
	'USART1__UDREAddr': '48',
	'USART1__TXAddr': '50',
	'ANALOG_COMPAddr': '52',
	'EE_READYAddr': '54',
	'SPM_READYAddr': '56'
}