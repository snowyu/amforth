;Z !DEST   dest adrs --    change a branch dest'n
;   TUCK - XT_SWAP I! ;
; Changes the destination address found at 'adrs' to the given 'dest'.  
; The MSP430 uses relative addressing from the location of the offset cell,
; i.e., to branch to FOO the offset cell at $ contains FOO-$.
        HEADER(XT_STOREDEST,5,"!dest",DOCOLON)
        DW  XT_TUCK,XT_MINUS,XT_SWAP,ISTORE,XT_EXIT

