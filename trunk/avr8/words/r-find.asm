; ( addr len -- f )
; Interpreter
; recognizer searching the dictionary
VE_REC_WORD:
    .dw $ff08
    .db "rec:word"
    .dw VE_HEAD
    .set VE_HEAD = VE_REC_WORD
XT_REC_WORD:
    .dw DO_COLON
PFA_REC_WORD:
    .dw XT_FINDNAME ; -- xt +/-1 | 0
    .dw XT_DUP
    .dw XT_ZEROEQUAL
    .dw XT_DOCONDBRANCH
    .dw PFA_REC_WORD_FOUND
        .dw XT_DROP
	.dw XT_R_FAIL
	.dw XT_EXIT
PFA_REC_WORD_FOUND:
    .dw XT_R_WORD
    .dw XT_EXIT

; ( addr len -- f )
; Interpreter
; Methode table for find recognizer
VE_R_WORD:
    .dw $ff06
    .db "r:word"
    .dw VE_HEAD
    .set VE_HEAD = VE_R_WORD
XT_R_WORD:
    .dw PFA_DOCONSTANT
PFA_R_WORD:
    .dw XT_R_WORD_INTERPRET
    .dw XT_R_WORD_COMPILE
    .dw XT_R_WORD_POSTPONE

; ( XT flags -- )
; Interpreter
; interpret method for find recognizer
;VE_R_WORD_INTERPRET:
;    .dw $ff06
;    .db "r:word"
;    .dw VE_HEAD
;    .set VE_HEAD = VE_R_WORD_INTERPRET
XT_R_WORD_INTERPRET:
    .dw DO_COLON
PFA_R_WORD_INTERPRET:
    .dw XT_DROP ; the flags are in the way
    .dw XT_EXECUTE
    .dw XT_EXIT

; ( XT flags -- )
; Interpreter
; Compile method for find recognizer
XT_R_WORD_COMPILE:
    .dw DO_COLON
PFA_R_WORD_COMPILE:
    .dw XT_ZEROLESS
    .dw XT_DOCONDBRANCH
    .dw PFA_R_WORD_COMPILE1
	.dw XT_COMMA
        .dw XT_EXIT
PFA_R_WORD_COMPILE1:
        .dw XT_EXECUTE
    .dw XT_EXIT

; ( XT flags -- )
; Interpreter
; Postpone method for find recognizer
XT_R_WORD_POSTPONE:
    .dw DO_COLON
PFA_R_WORD_POSTPONE:
    .dw XT_ZEROLESS
    .dw XT_DOCONDBRANCH
    .dw PFA_R_WORD_POSTPONE1
      .dw XT_COMPILE
      .dw XT_COMPILE
PFA_R_WORD_POSTPONE1:
    .dw XT_COMMA
    .dw XT_EXIT
