# -----------------------------------------------------------------------------
  CODEWORD Flag_foldable_1|Flag_inline, "1+", 1PLUS # ( u -- u+1 )
                       # Adds one to the cell on top of the stack.
# -----------------------------------------------------------------------------
  addi x3, x3, 1
  NEXT