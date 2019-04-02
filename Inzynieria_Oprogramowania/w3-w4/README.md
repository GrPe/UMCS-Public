
Inżynieria oprogramowania
===

## Wykład 3/4 - UML (Diagramy czynności, obiektów, stanów i sekwencji)

### Diagramy czynności

- Służą do sterowania przepływem czynności między wykonywanymi czynnościami
- To te przypominające schematy blokowe
- Wyróżniamy pole startowe oznaczone czarną kropką oraz pole końcowe (białe kółko z czarną kropką)

![czynnosc](1.png)

- Odbieranie i wysyłanie sygnału

![sygnal](2.png)

- Obsługa wyjątków

![exception](3.png)

- Wykonywanie ścieżki współbieżne

![thread](4.png)

- Zakres odpowiedzialności

![responsibility](5.png)

### Diagramy obiektów

#### Rodzaje obiektów

![objects](6.png)

- obiekt nazwany
- obiekt anonimowy
- obiekt zawierający ścieżkę dostępu do pakietu z def. klasy
- obiekt osierocony
- obiekt aktywny

#### Wiązanie obiektów

![connect](7.png)

#### Stereotypy wiązań

- `<<association>>` - jest widoczny dzięki temu wiązaniu
- `<<global>>` - jest w otaczającym zasięgu
- `<<local>>` - jest w lokalnym zasięgu
- `<<parameter>>` - obiekt jest widoczny ponieważ jest parametrem
- `<<self>>` - jest widoczny bo odebrał zlecenie wykonania danej operacji

### Diagramy stanów

![state](8.png)

- Czarne kółko oznacza wejście do stanu
- Białe kółko z czarną kropką oznacza wyjście ze stanu
- Przechowuje stan obiektu

- Przykład:

![example](9.png)

- Przejścia alternatywne:

![alt](10.png)

### Diagramy sekwencji

- Inaczej diagramy przebiegu pozwalają modelować wzajemną interakcję obiektów w czasie.
- Obiekty mogą na siebie wzajemnie oddziaływać modyfikując stan (wartości) swoich atrybutów
- Żądanie wykonania operacji nazywane jest komunikatem
- Przetworzenie otrzymanego komunikatu powoduje zmianę stanu obiektu, a do obiektu źródłowego może przesłana być odpowiedź.
- Komunikaty mogą być blokujące (synchroniczne) albo nieblokujące (asynchroniczne)

- Komunikat synchroniczny:

![sync](11.png)

- Komunikat zwrotny:

![ret](12.png)

- Komunikat asynchroniczny:

![async](13.png)

- Przykładowy diagram sekwekcji:

![exa](14.png)

- Rekurencja:

![rec](15.png)

- Pętle:

![loop](16.png)

### Diagramy komunikacji (kooperacji)

- Pozwalają na pokazanie kolejności wysyłania komunikatów

![coop](17.png)

- Diagramy te pozwalają wymodelować interakcję zachodzącą między obiektami lub/i pomiędzy użytkownikiem systemy i obiektami.

### Komponenty

- wymienna część systemu implementująca jedną lub większą liczbę klas
- Wszystkie fizyczne pliki określane są mianem __artefaktów__
