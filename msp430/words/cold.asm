;Z COLD     --      cold start Forth system
    HEADER(XT_COLD,4,"cold",DOCOLON)
	DW XT_BASE,XT_ADDR_TO_INFO,XT_FETCH,XT_1MINUS,XT_ZEROLESS
	DW XT_DOCONDBRANCH
	DEST(COLD1)
	; there is no valid data in INFO flash
        DW UINIT,XT_DOBRANCH
	DEST(COLD2)
COLD1:
	; there is valid content in INFO, restore it
        DW XT_DOLITERAL, INFOSTART
COLD2:
	DW U0,XT_DOLITERAL,INFO_SIZE,ITOD
        DW XT_APPLTURNKEY
        DW XT_QUIT

