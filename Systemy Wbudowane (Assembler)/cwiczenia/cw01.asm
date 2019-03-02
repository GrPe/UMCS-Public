org 0 ;dyrektywa kompilatora
	ljmp start
	
org 100h
start:
   djnz r4, start
   djnz r3, start
   cpl p1.7 ; uruchomienie diody - test
   sjmp start
end