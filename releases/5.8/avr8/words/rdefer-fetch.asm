; ( xt1 -- xt2 ) 
; System
; The defer@ for ram defers
VE_RDEFERFETCH:
    .dw $ff07
    .db "Rdefer@",0
    .dw VE_HEAD
    .set VE_HEAD = VE_RDEFERFETCH
XT_RDEFERFETCH:
    .dw DO_COLON
PFA_RDEFERFETCH:
    .dw XT_FETCHI
    .dw XT_FETCH
    .dw XT_EXIT