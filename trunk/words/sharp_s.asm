; ( n1 -- 0)
VE_SHARP_S:
    .db $02, "#s",0
    .dw VE_LATEST
    .set VE_LATEST = VE_SHARP_S
XT_SHARP_S:
    .dw DO_COLON
PFA_SHARP_S:
    .dw XT_SHARP
    .dw XT_DUP
    .dw XT_DOLITERAL
    .dw 0
    .dw XT_EQUAL
    .dw XT_DOCONDBRANCH
    .dw PFA_SHARP_S
    .dw XT_EXIT
