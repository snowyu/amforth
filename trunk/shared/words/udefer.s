
COLON Flag_visible, "Udefer@", UDEFER_FETCH
  .word XT_UP_FETCH, XT_PLUS, XT_FETCH
.word XT_EXIT

COLON Flag_visible, "Udefer!", UDEFER_STORE
  .word XT_UP_FETCH, XT_PLUS, XT_STORE
.word XT_EXIT
