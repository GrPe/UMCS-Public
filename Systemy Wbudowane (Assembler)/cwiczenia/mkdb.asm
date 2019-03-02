;obsluga klawiatury matrycowej
CSKB0 equ 0ff21h ;klawiatura matrycowa 0..7
CSKB1 equ 0ff22h ;klawiatura matrycowa 8...


CSDS16 equ 0ff30h ;bufor wyboru wyswietlacza
CSDB16 equ 0ff38h ;bufor wyboru segmentu
WYSW0	bit	P1.6

org 0
	ljmp start

org 100h

start:

	clr WYSW0
	
loop:
	mov DPTR, #CSKB0
	movx A, @DPTR
	cpl A
	mov DPTR, #CSDB16
	movx @DPTR, A

    mov A, #100b
	mov DPTR, #CSDS16
	movx @DPTR, A
	
	djnz r7, $
	
	mov DPTR, #CSKB1
	movx A, @DPTR
	cpl A
	mov DPTR, #CSDB16
	movx @DPTR, A

    mov A, #1000b
	mov DPTR, #CSDS16
	movx @DPTR, A
	
	djnz r7, $
	sjmp loop

end