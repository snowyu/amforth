# -----------------------------------------------------------------------------
  CODEWORD "-rot", MROT # ( x w y -- y x w )
# -----------------------------------------------------------------------------
  lw x5, 0(x4)
  lw x6, 4(x4)
  sw x6, 0(x4)
  sw x3, 4(x4)
  mv x3, x5
  NEXT
