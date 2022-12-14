    print WDT "; ( -- ) 
; MCU
; disable watch dog timer at runtime
VE_NOWDT:
    .dw \$ff04
    .db \"-wdt\"
    .dw VE_HEAD
    .set VE_HEAD = VE_NOWDT
XT_NOWDT:
    .dw PFA_NOWDT
PFA_NOWDT:
";
  if($has_wdtcsr) {
      print WDT "
     in temp1,SREG
     push temp1
     ; Turn always off global interrupt.
     cli
     ; Reset Watchdog Timer
     wdr
     ; Clear WDRF in MCUSR
     in temp1, MCUSR
     andi temp1, (0xff & (0<<WDRF))
     out MCUSR, temp1
     ; Write logical one to WDCE and WDE
     ; Keep old prescaler setting to prevent unintentional time-out
     in_ temp1, WDTCSR
     ori temp1, (1<<WDCE) | (1<<WDE)
     out_ WDTCSR, temp1
     ; Turn off WDT
     ldi temp1, (0<<WDE)
     out_ WDTCSR, temp1
     ; restore status register
     pop temp1
     out SREG,temp1
     jmp_ DO_NEXT
";
    } else {
      print WDT "
; Reset WDT
  wdr
; Write logical one to WDTOE and WDE
  in_ temp1, WDTCR
  ori temp1, (1<<WDTOE)|(1<<WDE)
  out WDTCR, temp1
; Turn off WDT
  ldi temp1, (0<<WDE)
  out_ WDTCR, temp1
  jmp_ DO_NEXT
";
    }
    close(WDT);
