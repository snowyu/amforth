; ( -- n ) System Value
; R( -- )
; terminal input buffer size
VE_TIBSIZE:
    .db $07, "tibsize"
    .dw VE_HEAD
    .set VE_HEAD = VE_TIBSIZE
XT_TIBSIZE:
    .dw PFA_DOVALUE
PFA_TIBSIZE:
    .dw $0E
    .dw XT_EDEFERFETCH
    .dw XT_EDEFERSTORE
