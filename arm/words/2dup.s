CODEWORD Flag_visible, "2dup", 2DUP @ ( 2 1 -- 2 1 2 1 )
  ldr r0, [psp]
  savetos
  subs psp, #4
  str r0, [psp]
NEXT
