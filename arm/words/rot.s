
@ -----------------------------------------------------------------------------
  CODEWORD Flag_visible, "rot", ROT @ ( x w y -- w y x )
@ -----------------------------------------------------------------------------
  ldm psp!, {r0, r1}
  subs psp, #8
  str r0, [psp, #4]
  str tos, [psp]
  movs tos, r1
NEXT
