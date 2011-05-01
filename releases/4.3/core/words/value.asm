; ( n <name> -- ) 
; Compiler
; create a dictionary entry for a value and allocate 1 cell in EEPROM.
VE_VALUE:
    .dw $ff05
    .db "value",0
    .dw VE_HEAD
    .set VE_HEAD = VE_VALUE
XT_VALUE:
    .dw DO_COLON
PFA_VALUE:
    .dw XT_DOCREATE
    .dw XT_GET_CURRENT
    .dw XT_STOREE

    .dw XT_COMPILE
    .dw PFA_DOVALUE
    .dw XT_EDP
    .dw XT_DUP
    .dw XT_COMMA
    .dw XT_DUP
    .dw XT_1PLUS
    .dw XT_1PLUS
    .dw XT_DOTO
    .dw PFA_EDP
    .dw XT_STOREE
    .dw XT_EXIT

PFA_DOVALUE:
    call_ DO_DODOES
    .dw XT_FETCHI
    .dw XT_FETCHE
    .dw XT_EXIT

; : value ( n -- )
;	create edp e@ dup , dup 1+ 1+ edp e! e! does> i@ e@ ;

