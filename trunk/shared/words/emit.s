  DEFER "emit", EMIT, XT_EMIT_PAUSE

NONAME EMIT_PAUSE
    .word XT_PAUSE,XT_SERIAL_EMITQ, XT_DOCONDBRANCH, PFA_EMIT_PAUSE
    .word XT_SERIAL_EMIT
    .word XT_EXIT
