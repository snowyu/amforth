; ( n <name> -- ) Compiler
; R( -- )
; allocate space for 1 cell in EEPROM. used in conjunction with TO
VE_EDEFER:
    .db $06, "Edefer",0
    .dw VE_HEAD
    .set VE_HEAD = VE_EDEFER
XT_EDEFER:
    .dw DO_COLON
PFA_EDEFER:
    .dw XT_DOCREATE
    .dw XT_COMPILE
    .dw PFA_DODEFER

    .dw XT_EDP
    .dw XT_EFETCH
    .dw XT_DUP
    .dw XT_COMMA
    .dw XT_COMPILE
    .dw XT_EDEFERFETCH
    .dw XT_COMPILE
    .dw XT_EDEFERSTORE
    .dw XT_1PLUS
    .dw XT_1PLUS
    .dw XT_EDP
    .dw XT_ESTORE
    .dw XT_EXIT
