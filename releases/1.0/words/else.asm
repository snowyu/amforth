VE_ELSE:
    .db $84, "else",0
    .dw VE_HEAD
    .set VE_HEAD = VE_ELSE
XT_ELSE:
    .dw DO_COLON
PFA_ELSE:
    .dw XT_DOLITERAL
    .dw XT_DOBRANCH
    .dw XT_COMMA
    .dw XT_GMARK
    .dw XT_SWAP
    .dw XT_GRESOLVE
    .dw XT_EXIT
