@ -----------------------------------------------------------------------------
  CODEWORD "-", MINUS @ ( x1 x2 -- x1-x2 )
                      @ Subtracts x2 from x1.
@ -----------------------------------------------------------------------------
  ldm psp!, {r0}
  subs tos, r0, tos
NEXT