
COLON Flag_visible,"type0", TYPE0

PFA_TYPE0_LOOP:
    .word XT_DUP,XT_CFETCH,XT_DUP, XT_NOTZEROEQUAL,XT_DOCONDBRANCH,PFA_TYPE0_LEAVE
    .word XT_DUP,XT_DOLITERAL,10,XT_EQUAL,XT_DOCONDBRANCH,PFA_TYPE0_1,XT_DOLITERAL,13,XT_EMIT
PFA_TYPE0_1:
    .word XT_EMIT, XT_1PLUS, XT_DOBRANCH,PFA_TYPE0_LOOP
PFA_TYPE0_LEAVE:
    .word XT_2DROP,XT_EXIT