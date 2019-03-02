;PRZERWANIA
;
	mov TH0, #254		;to mi daje 1800 przerwan / sekunde w trybie 1
	mov TH0, #256-16	;to mi daje 1800 przerwan / sekunde w trybie 0

	mov TMOD, #01110000b;blokada TIMER1 i tryb 0 dla TIMER0

	setb TR0			;zgoda na zliczanie przez TIMER0
	setb ET0			;zgoda na obsluge przerwania od TIMER0
	setb EA				;globalna zgoda na obsluge przerwan
	

	org 0Bh	;obsluga przerwania od TIMER0

	mov TH0,#254  		;to mi daje 1800 przerwan / sekunde w trybie 1
    mov TH0, #256-16	;to mi daje 1800 przerwan / sekunde w trybie 0
	setb WPZ            ;sygnalizuje petli glownej wystapienie przerwania
	reti 				;powrot z przerwania
	
;7-SEG
	CSDS16	equ 0FF30h		; bufor wyboru wskaznika 7-segmentowego
	CSDB16	equ 0FF38h		; bufor danych wskaznika 7-segmentowego
	
	mov R7, #00000001b
    mov R0, #0
loop:

    mov DPTR, #wzory
    mov A, @R0
    inc R0
    movc A, @A + DPTR 

    setb WYSW
    mov DPTR, #CSDB
    movx @DPTR, A

    mov DPTR, #CSDS
    mov A, R7
    movx @DPTR, A
    rl A
    mov R7, A
    clr WYSW

    jnb ACC.6, loop
    mov R7, #00000001b
    mov R0, #CZAS