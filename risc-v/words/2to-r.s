# -----------------------------------------------------------------------------
  CODEWORD Flag_inline, "2>r", 2TO_R # ( 2 1 -- R: -- 2 1 )
# -----------------------------------------------------------------------------
  mv x5,x3
  loadtos
  push x3
  loadtos
  push x5
  NEXT
