; the inner interpreter.

DO_COLON:
    push XH
    push XL          ; PUSH IP
    movw XL, wl
    adiw xl, 1
DO_NEXT:
    cp isrflag, zerol
    brne DO_INTERRUPT
    movw zl, XL        ; READ IP
    readflashcell wl, wh
    adiw XL, 1        ; INC IP

DO_EXECUTE:
    movw zl, wl
    readflashcell temp0,temp1
    movw zl, temp0
    ijmp

DO_INTERRUPT:
    ; here we deal with interrupts the forth way
    savetos
    mov tosl, isrflag
    clr tosh
    mov isrflag, zerol
    ldi wl, LOW(XT_ISREXEC)
    ldi wh, HIGH(XT_ISREXEC)
    rjmp DO_EXECUTE
