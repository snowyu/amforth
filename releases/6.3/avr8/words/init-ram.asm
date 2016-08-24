; ( e-addr r-addr len -- ) 
; Tools
; copy len cells from eeprom to ram
VE_EE2RAM:
  .dw $ff06
  .db "ee>ram"
  .dw VE_HEAD
  .set VE_HEAD = VE_EE2RAM
XT_EE2RAM:
  .dw DO_COLON
PFA_EE2RAM:          ; ( -- )
    .dw XT_ZERO
    .dw XT_DODO
PFA_EE2RAM_1:
    ; ( -- e-addr r-addr )
    .dw XT_OVER
    .dw XT_FETCHE
    .dw XT_OVER
    .dw XT_STORE
    .dw XT_CELLPLUS
    .dw XT_SWAP
    .dw XT_CELLPLUS
    .dw XT_SWAP
    .dw XT_DOLOOP
    .dw PFA_EE2RAM_1
PFA_EE2RAM_2:
    .dw XT_2DROP
    .dw XT_EXIT

; ( -- )
; Tools
; setup the default user area from eeprom
VE_INIT_RAM:
  .dw $ff08
  .db "init-ram"
  .dw VE_HEAD
  .set VE_HEAD = VE_INIT_RAM
XT_INIT_RAM:
  .dw DO_COLON
PFA_INI_RAM:          ; ( -- )
    .dw XT_DOLITERAL
    .dw EE_INITUSER
    .dw XT_UP_FETCH
    .dw XT_DOLITERAL
    .dw SYSUSERSIZE
    .dw XT_2SLASH
    .dw XT_EE2RAM
    .dw XT_EXIT
