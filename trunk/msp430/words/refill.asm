; ( -- f )
    HEADER(XT_REFILL,6,"refill",DOCOLON)
        DW TIB,XT_DUP,TIBSIZE,XT_ACCEPT
	DW TICKSOURCE,TWOSTORE
	DW XT_ZERO,XT_TO_IN,XT_STORE
	DW XT_MINUSONE,XT_EXIT
