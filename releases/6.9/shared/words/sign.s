
COLON "sign", SIGN
    .word XT_ZEROLESS
    .word XT_DOCONDBRANCH
    .word PFA_SIGN1
    .word XT_DOLITERAL
    .word 45 
    .word XT_HOLD
PFA_SIGN1:
    .word XT_EXIT
