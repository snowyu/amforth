# -----------------------------------------------------------------------------
  CODEWORD Flag_visible|Flag_variable, "base", BASE # ( -- addr )
  CoreVariable base
# -----------------------------------------------------------------------------
  savetos
  li x3, base
  NEXT
  .word 10

# -----------------------------------------------------------------------------
  CODEWORD Flag_visible, "binary", BINARY # ( -- )
# -----------------------------------------------------------------------------
  li x5, 2
  li x6, base  
  sw x5, 0(x6)
  NEXT

# -----------------------------------------------------------------------------
  CODEWORD Flag_visible, "decimal", DECIMAL # ( -- )
# -----------------------------------------------------------------------------
  li x5, 10
  li x6, base  
  sw x5, 0(x6)
  NEXT
  
# -----------------------------------------------------------------------------
  CODEWORD Flag_visible, "hex", HEX # ( -- )
# -----------------------------------------------------------------------------
  li x5, 16
  li x6, base  
  sw x5, 0(x6)
  NEXT

