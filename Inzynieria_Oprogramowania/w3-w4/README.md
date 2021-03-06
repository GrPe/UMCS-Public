
Inżynieria oprogramowania
===

# Wykład 3/4 - UML (Diagramy czynności, obiektów, stanów i sekwencji)

## Diagramy czynności

- Służą do modelowania przepływu sterowania między wykonywanymi czynnościami
- Czynności są wieloetapowymi działaniami, których wynikiem jest pewna akcja, składająca się z niepodzielnych kroków
    - np: Obliczenie wyrażenia arytmetycznego
    - Wywołanie operacji
    - Wysłanie sygnału
    - Utworzenie lub zniszczenie obiektu
- To te przypominające schematy blokowe
- Wyróżniamy pole startowe oznaczone czarnym kółkiem oraz pole końcowe (białe kółko z czarną kropką)

![czynnosc](1.png)

- Odbieranie i wysyłanie sygnału

![sygnal](2.png)

- Obsługa wyjątków

![exception](3.png)

- Wykonywanie ścieżki współbieżne

![thread](4.png)

- Zakres odpowiedzialności

![responsibility](5.png)

## Diagramy obiektów

### Rodzaje obiektów

![objects](6.png)

- obiekt nazwany
- obiekt anonimowy (wskaźnik, referencja)
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

### Diagramy sekwencji (przebiegu)

- Inaczej diagramy przebiegu pozwalają modelować wzajemną interakcję obiektów w czasie.
- Obiekty mogą na siebie wzajemnie oddziaływać modyfikując stan (wartości) swoich atrybutów
- Żądanie wykonania operacji nazywane jest komunikatem
- Komunikat składa się zwykle z:
    - wskazania docelowane obiektu (poprzez odwołanie się do nazwy obiektu)
    - wskazania udostępnianej przez obiekt docelowy operacji, której wykowania żąda obiekt źródłowy
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

#### Bloki

![loop](16.png)

- **alt** - (alternative) określający warunek wykonania bloku (*if-else*), warunek umieszcza się wewnątrz bloku w nawiasach kwadratowych
- **opt** - (optional) reprezetuje instrukcję *if* (bez *else*)
- **par** - (parallel) nakazuje wykonanie operacji równolegle
- **critical** - blok atomowy, obszar krytyczny
- **loop** - pętle *for* lub *while*
- **break** - wykonanie fragmentu i zakończenie istrukcji
- **neg** - funkcjonalności nieprawidłowe - wskazują na wyjątki, które muszą zostać obsłużone
- **strict** - ścisłe uporządkowanie komunikatów
- **seq** - słabe uporządkowanie dotyczy komunikatów z kilku linii mogących wystąpić w dowolnym porządku
- **ignore** - komunikaty nie mają istotnego wpływu na całość komunikacji
- **consider** - istotność - komunikaty muszą zostać wykonane

#### Techniki tworzenia diagramów sekwencji

- ustalenie otoczenia (operacje, przypadki użycia)
- zidentyfikowanie obiektów biorących udział w operacji (od lewej najważniejsze)
- narysowanie linii życia obiektów
- dodanie komunikatu inicjującego kolejne komunikaty pod nim
- dodanie aktywacji (ośrodka sterowania)

### Diagramy komunikacji (kooperacji)

- Pozwalają na pokazanie kolejności wysyłania komunikatów

![coop](17.png)

- Diagramy te pozwalają wymodelować interakcję zachodzącą między obiektami lub/i pomiędzy użytkownikiem systemy i obiektami.

### Komponenty

- Wszelkiego rodzaju fizyczne pliki określane są ogólnie mianem artefaktów `<<artifact>>`
- W przeciwieństwie do klas, które są pojęciem logicznym, komponenty realnie rezydują w komputerze
- W odróźnieniu od artefaktów, komponenty definiują funkcjonalność systemu
- Komponent jest implementacją jednej lub większej liczby klas
- Artefakt może być implementacją komponentu.

![komponent](18.png)

- Komponent to grupa klas pozostających ze sobą w dobrze zdefiniowanych relacjach (dziedziczenie, powiązania, zależności) i służą jednemu konkretnemu celowi
- Klasy wewnątrz komponentu mają silne związki między sobą i słabe poza nim
- Dzięki temu komponenty mogą być rozwijane niezależnie i zamiennie wykorzystywane zależnie od kontekstu, bez konieczności modyfikowania innych komponentów
