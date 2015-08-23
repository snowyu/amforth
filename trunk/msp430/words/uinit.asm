;Z uinit    -- addr  initial values for user area
; MSP430: we also use this to initialize the RAM interrupt
; vectors, which immediately follow the user area.
; Per init430f1611.s43, allocate 16 cells for user
; variables, followed by 30 cells for interrupt vectors.
    HEADER(UINIT,5,"uinit",DOROM)
; CFG Area
	DW 2,XT_REC_WORD,XT_REC_NUM,0,0
	DW 1,RAM_LATEST,0,0,0,0,0,0,0
	DW XT_APPLTURNKEY ; TURNKEY vector
	DW RAMDICT        ; HERE / DP
	DW ROMDICT        ; IHERE / IDP
	DW lastword       ; latest
        DW lastenv        ; environment
; USER Area
	DW 0,0          ; STATE/FOLLOWER
	DW 0,0,0        ; RP,SP0, SP
        DW 0            ; HANDLER
	DW 10		; BASE
	DW XT_EMIT
	DW XT_TRUE
	DW XT_KEY
	DW XT_KEYQ
	DW XT_TIB_SOURCE
	DW 0
	DW XT_TIB_REFILL
	DW 0,0,0        ; user variables TBD
