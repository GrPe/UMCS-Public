;
;	zamierzam wyswirtlic rozne cyfry na roznych wyswietlaczach 7-seg
;
CSDS16	equ 0FF30h		; bufor wyboru wskaünika 7-segmentowego
CSDB16	equ 0FF38h		; bufor danych wskaünika 7-segmentowego
WYSW	equ P1.6		; wyswietlacze
CZAS	equ 7Ah			;tablica 6 cyfr zegarka

org 0
	ljmp start  ;przeskakujemy obszar zarezerwowany na przerwania

org 0Bh	;obsluga przerwania od TIMER0
	cpl p1.7
	reti ;powrot z przerwania

org 100h

start:	;przygotowanie srodowiska pracy programu #########################

	mov CZAS+0, #0      ;przygotowanie taablicy czas
	mov CZAS+1, #1
	mov CZAS+2, #6
	mov CZAS+3, #1
	mov CZAS+4, #5
	mov CZAS+5, #1

	mov R7, #00000001b  ;najmlodszy wyswietlacz
	mov R6, #CZAS       ;wartosc startowa licznika petli
	mov R0, #CZAS       ;najmlodsza cyfra zegarka
	
	mov IE, #0			;blokada ubslugi przerwan
	mov TMOD, #01110001b;blokada TIMER1 i tryb 0 dla TIMER0

	setb TR0			;zgoda na zliczanie przez TIMER0
	setb ET0			;zgoda na obsluge przerwania od TIMER0
	setb EA				;globalna zgoda na obsluge przerwan

main_loop: ;petla glowna programu    #####################################

	;acall displayService

	sjmp main_loop

displayService: 			;obsluga wyswietlacza ########################

	djnz R3, displayService  ; prymitywna petla opozniajaca
	djnz R2, displayService
	mov R2, #1

	mov DPTR, #wzory     ;wzorek odpowiadajacy cyfrze zegarka
	mov A, @R0           ;z tablicy czas
	inc R0               ;nastepna cyfra
	movc A, @A + DPTR    ;wzorek do akulumatora

	setb WYSW           ; wylaczam wyswietlacze
	mov DPTR, #CSDB16 	; segmenty
	movx @DPTR, A       ; wlasciwe wlaczenie segmentow

    mov DPTR, #CSDS16 	;wskazniki
	mov A, R7           ;aktualny wyswietlacz do akumulatora
	movx @DPTR, A       ;wybierz wyswietlacz
	rl A                ;przeskakujemy na nastepny wyswietlacz
    mov R7, A           ;zapamietujemy nastepny wyswietlacz w R7

	mov A, R6
	cjne A, 0, $+3
	jnc nie_wlaczaj
	clr WYSW			; wlacza wyswietlacze
nie_wlaczaj:

	mov A, R7
	jnb ACC.7, displayServiceRet;sprawdzamy czy nie minelismy diody F1..ERR
	mov R7, #00000001b  ;jezeli tak to wracamy na najmlodszy wyswietlacz
	mov R0, #CZAS       ;i cyfre jednostek sekund
	
	inc R6				;zwiekszamy licznik petli
	cjne R6, #CZAS+6, displayServiceRet ;warunek koncowy licznika petli
	mov R6, #CZAS		;wartosc startowa licznika petli

displayServiceRet:
	ret                 ; powrot do petli glownej
	;koniec obslugi wyswietlacza ###################################
	
wzory:
	db	00111111b, 00000110b
	db	01011011b, 01001111b
	db	01100110b, 01101101b
	db	01111101b, 00000111b
	db	01111111b, 01101111b
	db	01110111b, 01111100b
	db	01011000b, 01011110b
	db	01111001b, 01110001b

end