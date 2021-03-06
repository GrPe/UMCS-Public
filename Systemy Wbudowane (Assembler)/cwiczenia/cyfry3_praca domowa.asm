;
;	zamierzam wyswirtlic rozne cyfry na roznych wyswietlaczach 7-seg
;
CSDS16	equ 0FF30h		; bufor wyboru wska�nika 7-segmentowego
CSDB16	equ 0FF38h		; bufor danych wska�nika 7-segmentowego
WYSW	equ P1.6		; wyswietlacze
CZAS	equ 7Ah			;tablica 6 cyfr zegarka
WPZ		bit 7Fh			;wystapilo przerwanie zegarowe
GG		equ 79h			;godziny
MM		equ 78h			;minuty
SS		equ 77h			;sekundy

org 0
	ljmp start  ;przeskakujemy obszar zarezerwowany na przerwania

org 0Bh	;obsluga przerwania od TIMER0

	;mov TH0,#254  		;to mi daje 1800 przerwan / sekunde w trybie 1
    mov TH0, #256-16	;to mi daje 1800 przerwan / sekunde w trybie 0
	setb WPZ            ;sygnalizuje petli glownej wystapienie przerwania
	reti 				;powrot z przerwania

org 100h

start:	;przygotowanie srodowiska pracy programu #########################

 	mov GG, #23
	mov MM, #59
	mov SS, #45

    mov A, SS
	mov B, #10
	div AB
	mov CZAS+0, B      ;przygotowanie taablicy czas
	mov CZAS+1, A

    mov A, MM
	mov B, #10
	div AB
	mov CZAS+2, B
	mov CZAS+3, A

	mov A, GG
	mov B, #10
	div AB
	mov CZAS+4, B
	mov CZAS+5, A

	mov R7, #00000001b  ;najmlodszy wyswietlacz
	mov R6, #CZAS       ;wartosc startowa licznika petli
	mov R0, #CZAS       ;najmlodsza cyfra zegarka

	mov IE, #0			;blokada ubslugi przerwan

	mov TH0, #254		;to mi daje 1800 przerwan / sekunde w trybie 1
	mov TH0, #256-16	;to mi daje 1800 przerwan / sekunde w trybie 0

	mov TMOD, #01110000b;blokada TIMER1 i tryb 0 dla TIMER0

	setb TR0			;zgoda na zliczanie przez TIMER0
	setb ET0			;zgoda na obsluge przerwania od TIMER0
	setb EA				;globalna zgoda na obsluge przerwan
	
	mov R3, #8
	mov R4, #8

main_loop: ;petla glowna programu    #####################################
	jnb WPZ, main_loop  ;czekam na przerwanie zegarowe
	clr WPZ             ;zapominam o przerwaniu zegarowym

	acall displayService  ;odswiezam wyswietlacz 1800 razy na sekunde
						  ;tutaj jestem 1800 razy/sekunde
						  
	; odliczanie czasu  ####################################################
	djnz r3, main_loop		;odliczanie od 1800 do zera
	djnz r4, main_loop
	mov R3, #8				;czyszczenie licznika
	mov R4, #8

	inc SS					;zwieksz sekundy

	mov A, SS				; jesli sekundy > 60
	cjne A, #60, update
	mov SS, #0
	inc MM					;zwieksz minuty

	mov A, MM				; jesli minuty > 60
	cjne A, #60, update
	mov MM, #0
	inc GG					;zwieksz godziny

	mov A, GG				;jesli godziny > 24
	cjne A, #24, update
	mov GG, #0

update:
	
	mov A, SS				;ustaw sekundy na wyswietlaczu
	mov B, #10
	div AB
	mov CZAS + 0, B
	mov CZAS + 1, A

	mov A, MM				;ustaw minuty na wyswietlaczu
	mov B, #10
	div AB
	mov CZAS + 2, B
	mov CZAS + 3, A

	mov A, GG				;ustaw godzine na wyswietlaczu
	mov B, #10
	div AB
	mov CZAS + 4, B
	mov CZAS + 5, A

next:

	sjmp main_loop

displayService: 			;obsluga wyswietlacza ########################

	;djnz R3, displayService  ; prymitywna petla opozniajaca
	;djnz R2, displayService
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

	;mov A, R6
	;cjne A, 0, $+3
	;jnc nie_wlaczaj
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