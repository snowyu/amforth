; ( -- )
; R(limit counter -- limit counter+1|)
; runtime of loop
;VE_DOLOOP:
;    .dw $ff06
;    .db "(loop)"
;    .dw VE_HEAD
;    .set VE_HEAD = VE_DOLOOP
XT_DOLOOP:
    .dw PFA_DOLOOP
PFA_DOLOOP:
    pop zl
    pop zh
    adiw zl,1
    clr temp1
    jmp_ PFA_DOPLUSLOOP4