
COLON Flag_visible, ">number", TO_NUMBER


TONUM1: .word XT_DUP,XT_DOCONDBRANCH,TONUM3
        .word XT_OVER,XT_CFETCH,XT_DIGITQ
        .word XT_ZEROEQUAL,XT_DOCONDBRANCH,TONUM2
        .word XT_DROP,XT_EXIT
TONUM2: .word XT_TO_R,XT_2SWAP,XT_BASE,XT_FETCH,XT_UDSTAR
        .word XT_R_FROM,XT_MPLUS,XT_2SWAP
        .word XT_DOLITERAL,1,XT_SLASHSTRING,XT_DOBRANCH,TONUM1
TONUM3: .word XT_EXIT
