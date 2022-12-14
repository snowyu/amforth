    .dw -1           ; EEPROM Address 0 should not be used
; some configs
CFG_DP:      .dw DPSTART         ; Dictionary Pointer
EE_HERE:     .dw HERESTART       ; Memory Allocation
EE_EHERE:    .dw EHERESTART      ; EEProm Memory Allocation
CFG_WLSCOPE: .dw XT_GET_CURRENT  ; default wordlist scope
CFG_FORTHRECOGNIZER: .dw CFG_RECOGNIZERLISTLEN ; Recognizer word set
; LEAVE stack is between data stack and return stack.
CFG_LP0:     .dw stackstart+1
CFG_TURNKEY: .dw XT_APPLTURNKEY    ; TURNKEY
CFG_ENVIRONMENT:.dw VE_ENVHEAD     ; environmental queries
CFG_CURRENT: .dw CFG_FORTHWORDLIST ; forth-wordlist
CFG_FORTHWORDLIST:.dw VE_HEAD      ; pre-defined (compiled in) wordlist
CFG_ORDERLISTLEN:
    .dw 1
CFG_ORDERLIST: ; list of wordlist id, exactly numwordlist entries
    .dw CFG_FORTHWORDLIST      ; get/set-order
    .byte  (NUMWORDLISTS-1)*CELLSIZE ; one slot is already used
CFG_RECOGNIZERLISTLEN:
    .dw 2
CFG_RECOGNIZERLIST:
    .dw XT_REC_FIND
    .dw XT_REC_NUM
    .byte  (NUMRECOGNIZERS-2)*CELLSIZE ; two slots are already used

EE_STOREI:
    .dw XT_DO_STOREI  ; Store a cell into flash

; MARKER saves everything up to here. Nothing beyond gets saved
EE_MARKER:
    .dw EE_MARKER

; default user area
EE_INITUSER:
    .dw 0  ; USER_STATE
    .dw 0  ; USER_FOLLOWER
    .dw rstackstart  ; USER_RP
    .dw stackstart   ; USER_SP0
    .dw stackstart   ; USER_SP
    
    .dw 0  ; USER_HANDLER
    .dw 10 ; USER_BASE
    
    .dw XT_TX  ; USER_EMIT
    .dw XT_TXQ ; USER_EMITQ
    .dw XT_RX  ; USER_KEY
    .dw XT_RXQ ; USER_KEYQ
    .dw XT_SOURCETIB ; USER_SOURCE
    .dw 0            ; USER_G_IN
    .dw XT_REFILLTIB ; USER_REFILL  
    .dw XT_DEFAULT_PROMPTOK
    .dw XT_DEFAULT_PROMPTERROR
    .dw XT_DEFAULT_PROMPTREADY
    .dw XT_DEFAULT_PROMPTINPUT

; calculate baud rate error
.equ UBRR_VAL   = ((F_CPU+BAUD*8)/(BAUD*16)-1)  ; smart round
.equ BAUD_REAL  = (F_CPU/(16*(UBRR_VAL+1)))     ; effective baud rate
.equ BAUD_ERROR = ((BAUD_REAL*1000)/BAUD-1000)  ; error in pro mille

.if ((BAUD_ERROR>BAUD_MAXERROR) || (BAUD_ERROR<-BAUD_MAXERROR))       
  .error "Serial line cannot be set up properly (systematic baud error too high)"
.endif
EE_UBRRVAL:
    .dw UBRR_VAL     ; BAUDRATE
