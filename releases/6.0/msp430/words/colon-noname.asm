;C :        --      begin a colon definition  
    HEADER(XT_COLONNONAME,7,":noname",DOCOLON)
        DW XT_IHERE,XT_DUP,XT_LATEST,XT_STORE
	DW XT_COMPILE,DOCOLON
	DW XT_RBRACKET
        DW XT_EXIT
