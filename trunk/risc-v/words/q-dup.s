# -----------------------------------------------------------------------------
  CODEWORD Flag_foldable_1, "?dup", QDUP # ( x -- 0 | x x )
# -----------------------------------------------------------------------------
  beq x3, zero, 1f
    pushdatos
1:NEXT
