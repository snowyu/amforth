; (n1 -- u1)
VE_MAX:
    .db $03, "max"
    .dw VE_HEAD
    .set VE_HEAD = VE_MAX
XT_MAX:
    .dw DO_COLON
PFA_MAX:
    .dw XT_OVER
    .dw XT_OVER
    .dw XT_LESS
    .dw XT_DOCONDBRANCH
    .dw PFA_MAX1
    .dw XT_SWAP
PFA_MAX1:
    .dw XT_DROP
    .dw XT_EXIT
