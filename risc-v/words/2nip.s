# -----------------------------------------------------------------------------
  CODEWORD Flag_visible, "2nip", 2NIP # ( 4 3 2 1 -- 2 1 )
# -----------------------------------------------------------------------------
  lw x5, 0(x4)
  addi x4, x4, 8
  sw x5, 0(x4)
  NEXT