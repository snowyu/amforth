
COLON Flag_visible, "init-ram", INIT_RAM

    .word XT_DOLITERAL, HERESTART, XT_DOTO, XT_HERE
    .word XT_DP, XT_DOTO, XT_CURRENT
    .word XT_CFG_RECOGNIZER, XT_DOTO, XT_FORTHRECOGNIZER
    .word XT_DOLITERAL, RAM_lower_userarea, XT_UP_STORE

# wip

    .word XT_DOLITERAL
    .word XT_DOINIT_DEFER
    .word XT_DP
    .word XT_TRAVERSEWORDLIST
    .word XT_EXIT

NONAME DOINIT_DEFER
    .word XT_DUP
    .word XT_NAME2FLAGS, XT_FETCH,XT_DOLITERAL, Flag_defer, XT_DUP,XT_ROT,XT_AND,XT_EQUAL
    .word XT_DOCONDBRANCH,PFA_DOINIT_1
	.word XT_NFA2CFA # XT
	.word XT_CELLPLUS,XT_DUP,XT_FETCH,XT_SWAP,XT_CELLPLUS,XT_FETCH,XT_SWAP
	.word XT_STORE
	.word XT_TRUE
	.word XT_EXIT
PFA_DOINIT_1:
    .word XT_DROP
    .word XT_TRUE
    .word XT_EXIT
