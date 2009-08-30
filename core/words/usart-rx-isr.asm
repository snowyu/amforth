; ( -- c)  Hardware Access
; R( --)
; get 1 character from input queue, wait if needed
VE_RX:
    .dw $ff02
    .db "rx"
    .dw VE_HEAD
    .set VE_HEAD = VE_RX
XT_RX:
    .dw DO_COLON
PFA_RX:
  .dw XT_RXQ
  .dw XT_DOCONDBRANCH
  .dw PFA_RX
  .dw XT_DOLITERAL
  .dw usart_rx_out
  .dw XT_CFETCH
  .dw XT_1PLUS
  .dw XT_DOLITERAL
  .dw usart_rx_mask
  .dw XT_AND
  .dw XT_DUP
  .dw XT_DOLITERAL
  .dw usart_rx_out
  .dw XT_CSTORE
  .dw XT_DOLITERAL
  .dw usart_rx_data
  .dw XT_PLUS
  .dw XT_CFETCH
  .dw XT_EXIT

; ( -- f)  Hardware Access
; R( --)
; check if unread characters are in the input queue.
VE_RXQ:
    .dw $ff03
    .db "rx?",0
    .dw VE_HEAD
    .set VE_HEAD = VE_RXQ
XT_RXQ:
    .dw DO_COLON
PFA_RXQ:
  .dw XT_PAUSE
  .dw XT_DOLITERAL
  .dw usart_rx_out
  .dw XT_CFETCH
  .dw XT_DOLITERAL
  .dw usart_rx_in
  .dw XT_CFETCH
  .dw XT_NOTEQUAL
  .dw XT_EXIT
