
COLON Flag_visible, ",", COMMA

    .word XT_HERE
    .word XT_STORE
    .word XT_DOLITERAL,4
    .word XT_ALLOT
    .word XT_EXIT

COLON Flag_visible, "c,", CCOMMA
   .word XT_HERE, XT_CSTORE, XT_ONE, XT_ALLOT
   .word XT_EXIT