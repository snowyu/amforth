
COLON "type0", TYPE0

PFA_TYPE0_LOOP:
    .word XT_DUP,XT_CFETCH,XT_DUP, XT_NOTZEROEQUAL,XT_DOCONDBRANCH,PFA_TYPE0_LEAVE
    .word XT_DUP,XT_DOLITERAL,10,XT_EQUAL,XT_DOCONDBRANCH,PFA_TYPE0_1,XT_DOLITERAL,13,XT_EMIT
PFA_TYPE0_1:
    .word XT_EMIT, XT_1PLUS, XT_DOBRANCH,PFA_TYPE0_LOOP
PFA_TYPE0_LEAVE:
    .word XT_2DROP,XT_EXIT

COLON "count0", COUNT0
  .word XT_DUP, XT_ZERO
PFA_COUNT0_LOOP:
    .word XT_2DUP, XT_PLUS,XT_CFETCH,XT_NOTZEROEQUAL,XT_DOCONDBRANCH,PFA_COUNT0_LEAVE
      .word XT_1PLUS,XT_DOBRANCH,PFA_COUNT0_LOOP
PFA_COUNT0_LEAVE:
    .word XT_NIP,XT_EXIT
