; ( -- recn .. rec0 n) 
; Interpreter
; Get the current recognizer list
VE_GET_RECOGNIZER:
    .dw $ff0f
    .db "get-recognizers",0
    .dw VE_HEAD
    .set VE_HEAD = VE_GET_RECOGNIZER
XT_GET_RECOGNIZER:
    .dw DO_COLON
PFA_GET_RECOGNIZER:
    .dw XT_DOLITERAL
    .dw EE_RECOGNIZERLISTLEN
    .dw XT_GET_STACK
    .dw XT_EXIT
