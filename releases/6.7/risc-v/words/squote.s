
COLON Flag_visible, "s\"", SQUOTE # "
    .word XT_DOLITERAL
    .word 34   # 0x22 
    .word XT_PARSE       
    .word XT_STATE
    .word XT_FETCH
    .word XT_DOCONDBRANCH, PFA_SQUOTE1
      .word XT_SLITERAL
PFA_SQUOTE1:
    .word XT_EXIT
