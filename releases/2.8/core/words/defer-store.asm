; ( xt1 xt2 -- ) System
; R( -- )
; stores xt1 as the xt to be executed when xt2 is called
VE_DEFERSTORE:
    .db $06, "defer!",0
    .dw VE_HEAD
    .set VE_HEAD = VE_DEFERSTORE
XT_DEFERSTORE:
    .dw DO_COLON
PFA_DEFERSTORE:
    .dw XT_DUP
    .dw XT_DOLITERAL
    .dw 3
    .dw XT_PLUS   ; >body 2 +
    .dw XT_IFETCH
    .dw XT_EXECUTE
    .dw XT_EXIT

