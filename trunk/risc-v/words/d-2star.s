#------------------------------------------------------------------------------
  CODEWORD Flag_foldable_2, "d2*", D2STAR
#------------------------------------------------------------------------------
  lw x5, 0(x4) # Low

  srli x6, x5, 31
  add x5, x5, x5

  add x3, x3, x3
  or x3, x3, x6

  sw x5, 0(x4)
  NEXT
