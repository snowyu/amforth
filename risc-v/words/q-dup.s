# -----------------------------------------------------------------------------
  CODEWORD "?dup", QDUP # ( x -- 0 | x x )
# -----------------------------------------------------------------------------
  beq x3, zero, 1f
    savetos
1:NEXT