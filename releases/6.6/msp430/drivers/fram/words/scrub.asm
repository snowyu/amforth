; SCRUB erases the application area of the Program Flash,
; and then does COLD to reset the User Variables.
        HEADER(SCRUB,5,"SCRUB",DOCOLON)
        DW  XT_DOLITERAL,INFOSTART,XT_DOLITERAL,INFO_SIZE,FLERASE
        DW  XT_DOLITERAL,FLASHSTART,XT_DOLITERAL,(FLASHEND-FLASHSTART),FLERASE
        DW  XT_COLD,XT_EXIT
