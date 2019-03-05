
Inżynieria oprogramowania
===

## Wykład 1 - UML

- Program komputerowy - model fragmentu rzeczywistości
- Język programowania - model modelu -  *metamodel*

### Perspektywy:

- Perspektywa przypadków użycia
  - opisuje zachowanie systemu z punktu widzenia użytkownika, analityka, testera.
  - Najbardziej abstrakcyjna perspektywa.
  - Nie można uzyskać kodu
- Perspektywa projektowa
  - Na bazie pers. przypadków użycia.
  - Opis klas, interfejsów, sekwencji i kooperacji.
  - Opis problemu i jego rozwiązanie
  - Można uzyskać kod
- Perspektywa procesowa
  - Tworzenie wątków i procesów w systemie
- Perspektywa implementacyjna
  - Opisuje komponenty i artefakty potrzebne do scalenia i fizycznego udostępnienia systemu.
  - Konfiguracja poszczególnych wersji systemu.
- Perspektywa wdrożeniowa
  - Związek między softwarem a hardwarem

###  Przypadki użycia:

- Wymagania stawiane systemowi przez użytkownika
- Przypadek użycia jest dobrze określoną interakcją między użytkownikiem a systemem
- Dziedziczenie przypadku użycia:

![graf](https://github.com/GrPe/UMCS-Public/tree/master/Inzynieria_Oprogramowania/img/w1/1.png)

Zwrot skierowany w stronę bytu niezależnie logicznego

- Przebieg podstawowy

![graf](https://github.com/GrPe/UMCS-Public/tree/master/Inzynieria_Oprogramowania/img/w1/2.png)

Po A **zawsze** występuje B

- Przebieg opcjonalny

![graf](https://github.com/GrPe/UMCS-Public/tree/master/Inzynieria_Oprogramowania/img/w1/3.png)

B **czasami** rozszerza A

