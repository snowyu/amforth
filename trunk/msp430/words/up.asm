
CODEHEADER(XT_UP_FETCH,3,"up@")
	SUB #2,PSP
	MOV TOS, 0(PSP)
        MOV UP,TOS
	NEXT

CODEHEADER(XT_UP_STORE,3,"up!")
        MOV TOS,UP
        MOV @PSP+,TOS
	NEXT
