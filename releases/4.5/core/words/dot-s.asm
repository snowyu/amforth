; ( -- ) 
; Tools
; stack dump
VE_DOTS:
    .dw $ff02
    .db ".s"
    .dw VE_HEAD
    .set VE_HEAD = VE_DOTS
XT_DOTS:
    .dw DO_COLON
PFA_DOTS:
    .dw XT_SP_FETCH
    .dw XT_DEPTH
    .dw XT_1MINUS
    .dw XT_ZERO
    .dw XT_DOQDO
    .dw PFA_DOTS2
PFA_DOTS1:
    .dw XT_DUP
    .dw XT_I
    .dw XT_DUP
    .dw XT_UDOT
    .dw XT_2STAR
    .dw XT_PLUS
    .dw XT_DUP
    .dw XT_UDOT
    .dw XT_FETCH 
    .dw XT_UDOT
    .dw XT_CR
    .dw XT_DOLOOP
    .dw PFA_DOTS1
PFA_DOTS2:
    .dw XT_DROP
    .dw XT_EXIT
