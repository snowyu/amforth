#------------------------------------------------------------------------------
  DEFER "key",KEY # ( -- c )
#------------------------------------------------------------------------------

.word XT_KEY_PAUSE

NONAME KEY_PAUSE
    .word XT_PAUSE,XT_SERIAL_KEYQ, XT_DOCONDBRANCH, PFA_KEY_PAUSE
    .word XT_SERIAL_KEY,XT_GREEN
    .word XT_EXIT
