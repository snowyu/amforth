; ( n1 n2 -- n3)
VE_DIV:
    .db $01, "/"
    .dw VE_LATEST
    .set VE_LATEST = VE_DIV
XT_DIV:
    .dw DO_COLON
PFA_DIV:
    .dw XT_SLASHMOD
    .dw XT_SWAP
    .dw XT_DROP
    .dw XT_EXIT

