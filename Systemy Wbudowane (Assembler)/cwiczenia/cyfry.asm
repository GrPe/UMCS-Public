;
;	zamierzam wyswirtlic rozne cyfry na roznych wyswietlaczach 7-seg
;
CSDS16	equ 0FF30h		; bufor wyboru wskaünika 7-segmentowego
CSDB16	equ 0FF38h		; bufor danych wskaünika 7-segmentowego
WYSW	equ P1.6		; wyswietlacze
CZAS	equ 7Ah			;tablica 6 cyfr zegarka

org 0
	ljmp start
org 100h

start:	;przygotowanie srodowiska pracy programu

	mov CZAS+0, #0      ;przygotowanie taablicy czas
	mov CZAS+1, #1
	mov CZAS+2, #6
	mov CZAS+3, #1
	mov CZAS+4, #5
	mov CZAS+5, #1

	clr WYSW			;wlaczam wyswietlacze
	mov R7, #00000001b  ;najmlodszy wyswietlacz
	mov R0, #0fh

main_loop: ;petla glowna programu

	djnz R3, main_loop  ; prymitywna petla opozniajaca
	djnz R2, main_loop

	mov DPTR, #wzory     ;wzorek odpowiadajacy cyfrze zegarka
	mov A, @R0           ;z tablicy czas
	inc R0               ;nastepna cyfra
	movc A, @A + DPTR    ;wzorek do akulumatora

	mov DPTR, #CSDB16 	; segmenty
	movx @DPTR, A       ; wlasciwe wlaczenie segmentow

    mov DPTR, #CSDS16 	;wskazniki
	mov A, R7           ;aktualny wyswietlacz do akumulatora
	movx @DPTR, A       ;wybierz wyswietlacz
	rl A                ;przeskakujemy na nastepny wyswietlacz
	mov R7, A           ;zapamietujemy nastepny wyswietlacz w R7

	jnb ACC.7, main_loop;sprawdzamy czy nie minelismy diody F1..ERR
	mov R7, #00000001b  ;jezeli tak to wracamy na najmlodszy wyswietlacz
	mov R0, #CZAS


	sjmp main_loop
	
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