;obsluga klawiatury sekwencyjnej

CSDS16 equ 0ff30h ;bufor wyboru wyswietlacza
CSDB16 equ 0ff38h ;bufor wyboru segmentu
WYSW0	bit	P1.6  ; wyswietlacze on/off
SKEY	bit	P3.5  ;test klawiatury sekwencyjnej
TEST	bit P1.7  ;dioda test
STAK	equ 07fh  ;stan klawiatury

org 0
	ljmp start

org 100h
start:

	mov R7, #1          ;wybieram najmlodszy wyswieltacz
	mov STAK, #0        ;zeruje stan poczatkowy klawiatury

loop: 

	mov A, #1011011b    ;wzorek :>
	mov DPTR, #CSDB16
	setb WYSW0          ;wylaczam wyswietlacze zeby nie bylo duchow
	movx @DPTR, A       ;wysylam do zatrzasku wybierajacego segmenty

    mov A, R7           ;wybrany wyswietlacz do akumulatora
	mov DPTR, #CSDS16
	movx @DPTR, A       ;wysylam do zatrzasku wybierajacego wyswietlacze
	clr WYSW0

	mov c, SKEY         ;sprawdzam czy nacisnieto klawisz powiazany z wyswietlaczem
	jnc cplC            ;jezeli nie nacisnietopomijam zapamietywanie
	orl STAK, A         ;zapamietuje bit odpowiadajacy nacisnietemu klawiszowi

cplC:
	cpl c               ;jasnosc diody TEST bedzie proporcjonalna
	mov TEST, C         ;do liczby nacisnietych klawiszy
	
	rl A                ;zmieniam aktywny wyswietlacz o 1 w lewo
	mov R7, A           ;i zapamietuje w R7
	djnz R6, $          ;prymitywna opozniaczka

	jnb ACC.6, loop     ;jezeli jestem na wyswietlaczach wracam na poczatek petli

    mov A, STAK         ;a jezeli wszedlem na diody to wyswietlam stan klawiatury
	mov DPTR, #CSDB16   ;stan klawiatury do zatrzasku segmentow
	setb WYSW0          ;wylaczam diody
	movx @DPTR, A       ;wyslij

    mov A, R7
	mov DPTR, #CSDS16   ;wybieram diody F1..ER
	movx @DPTR, A
	clr WYSW0           ;wlaczam diody
	
	mov R7, #1          ;wracam na najmlodszy wyswietlacz
	mov STAK, #0        ;i zeruje stan klawiatury

	djnz R6, $

	sjmp loop

end