
Inżynieria oprogramowania
===

## Wykład 7/8 Analiza, projektowanie i testowanie oprogramowania

- Celem projektanta jest przygotowanie nowego lub ulepszonego produktu.
- _Jakość produktu zależy od jakości procesu, jaki został zastosowany dla jego stworzenia i utrzymania_
- Proces __weryfikacji__ odpowiada na pytanie: "Czy produkt tworzony jest prawidłowo?"
- Proces __walidacji__ odpowiada na pytanie: "Czy tworzony produkt jest prawidłowy?"

![e](e.png)

### Model dojrzałości

- __CMM/CMMI__ jest to model opisujący kluczowe elementy efektywnego procesu konstruowania oprogramowania.
- Jest to też model dojrzałości organizacji w obszarze IT lub zbiór dobrych praktyk dotyczących procesów wytwarzania oprogramowania.

#### Diagram fazowy

1. (Początkowy)
    - Organizacja funkcjonuje dzięki indywidualnym umiejętnościom poszczególnych pracowników.
    - Proces jest nieprzewidywalny i słabo kontrolowany.
2. (Zarządzany)
     - Organizacja działa w sposób powtarzalny i dokumentuje swoje działania.
     - Organizacja reaguje dopiero, gdy wystąpią problemy (zarządzanie wymaganiami, planowanie i śledzenie projektów tworzenia oprogramowania.)
3. (Zdefiniowany)
    - Organizacja definiuje procesy oraz planuje i zarządza zadaniami przed ich realizacją.
    - Organizacja jest proaktywna (organizacja zorientowana procesowo, definicja procesów, program treningów)
4. (Zarządany ilościowo)
    - Organizacja ściśle kontroluje i koryguje swoje działania.
    - Proces jest mierzalny i kontrolowany (pomiary i analiza procesów, zarządzanie jakością)
5. (Doskonalony)
    - Organizacja ciągle doskonali swoje procesy i efekty działań.
    - Wysiłki organizacji są ukierunkowane na ciągłe doskonalenie (innowacje technologiczne, zarządzanie zmianami procesów.)

- CMM/CMMI funcjonuje w 4 obszarach:
    - inżynieria systemów
    - inżynieria oprogramowania
    - integracja procesów i produktów
    - współpraca z dostawcami

- Korzyści:
    - usprawnienie przewidywalności harmonogramów i budżetu
    - usprawnienie tworzenia oprogramowania
    - zwiększenie produktywności
    - poprawienie jakości
    - zwiększenie zadowolenia klientów
    - zwiększenie morale pracowników
    - zwiększenie zwrotów inwestycji
    - obniżenie kosztów jakości

- CMM/CMMI usprawnia organizacje oparte na SDLC
    - wymusza ustalanie wymagań przed projektowaniem
    - koncentryje się na możliwości śledzenia w projekcie
    - zapewnia udokumentowanie i utrzymanie projektu
    - wymusza ocenę jakości przez niezależne zespoły
    - zapewnia wczesne planowanie z dużą dokładnością

#### Metodyka

- jest ustandaryzowanym dla wybranego obszaru wiedzy/nauki podejściem do rozwiązywania właściwych problemów.
- Metodyki abstahują od merytorycznego kontekstu danego obszaru, a skupiają się na metodach realizacji zadań

- Składniki metodyki
    - formalizmy, modele opisu rzeczywiścości
    - strukturalizacja procesu
    - szczegółowe metody i techniki dokumentowania
    - narzędzia
    - wymagania merytoryczne wobec poszczególnych twórców
    - kryteria oceny jakości projektu i systemu
    - zasady planowania i kierowania rozwojem systemu

### SDLC

![e](e2.png)

### Proces biznesowy (metoda biznesowa)

- Seria powiązanuch ze sobą działań lub zadań, które rozwiązują określony problem lub prowadzą do osiągnięcia konkretnego efektu.

- __Definiowalność__ - proces powinien mieć jasno zdefiniowane granice,  wejście i wyjście
- __Porządek__ - proces powinien składać się z działań uporządkowanych według ich usytuowania w czasie i przestrzeni
- __Klient__ - Musi być odbiorca rezultatów procesu
- __Zwiększenie wartości__ - Transformacja w trakcie procesu powinna dawać odbiorcy dodatkową wartość
- __Osadzenie__ - Proces nie może egzystować samodzielnie
- __Wielofunkcyjność__ - proces może obejmować wiele funkcji

### Proces (model) kaskadowy

![e](e3.png)

#### Zalety modelu kaskadowego

- łatwość zarządzania przedsiwzięciem
- łatwość harmonogramowania poszczególnych etapów
- łatwość określenia sumarycznych kosztów przedsięwzięcia
- łatwość tworzenia dokumentacji

#### Wady modelu kaskadowego

- wysoki koszt błędów popełnionych we wstępnych fazach projektu
- długa przerwa w kontaktach z klientem

### Proces (model) iteracyjny

![e](e4.png)

#### Koncepcja początkowa

- specyzowanie abstakcyjnego pojęcia, które ma stać się produktem
- uchwycenie wizji w formie zwięzłego opisu

#### Planowanie i analiza wymagań

- zrozumienie jak program będzie używany i jak będzie działać
- wynikiem tej fazy jest stworzenie dokumentu z opracowanymi wymaganiami
    - pierwszą częścią dokumentu jest analiza przypadków użycia
    - Identyfikacja aktorów
    - wyznaczenie pierwszych przypadków użycia
    - szczegółowy model dziedziny problemu
        - model obejmuje wszystko co wiemy o danej dziedzinie
        - jako części modelu tworzone są obiekty dziedziny opisujące wszystkie obiekty uwzględnione w przypadkach użycia.
    - tworzenie scenariuszy
        - scenariusz jest opisem określonego zestawu okoliczności w konkretnej sytuacji związanej z przypadkiem użycia.
    - Sceniarusz:
        - __Warunki wstępne__ - co musi być spełnione, aby scenariusz się rozpoczął
        - __Niezmienniki__ - warunki, które muszą być zapewnione w trakcie trwania scenariusza
        - Akcje, jakie podejmuje aktor
        - Wyniki lub zamiany powodowane przez system
        - Informacje zwrotne otrzymywane przez aktora
        - Informacje o występnowaniu cyklicznych operacji i o tym co je powoduje
        - Schematyczne opisy przebiegu scenariusza
        - __Warunki końcowe__ - co musi być spełnione w momencie zakończenia scenariusza
        - ![e](e5.png)
    - Analiza aplikacji
        - często występuje konieczność współpracy z istniejącymi systemami
        - W _idealnym świecie_ zespół analizuje problem, projektuje rozwiązanie i decyduje, która platforma programistyczna i jaki system operacyjny najlepiej odpowiada potrzebom klienta.
        - Częściej jednak plany firmy opierają się na współpracy z istniejącymi systemami
    - Analiza systemowów
        - proces zbierania informacji dotyczących systemów, z którymi będzie współpracował nowotworzony projekt.
    - Dokumentacja produktu
        - po zakończeniu analizy tworzona jest lista dokumentów produktu
        - ![e](e6.png)

#### Projektowanie

- skupia się na tworzeniu optymalnego rozwiązania
- jest procesem przekształcenia zrozumienia wymagań w model, który może być zaimplementowany w postaci oprogramowania
- wynikiem jest stworzenie dokumentu projektowego
- Powiniem być podzielony na 2 części:
    - Projekt klas
        - Projekt statyczny (diagram klas)
        - Projekt dynamiczny (diagramy opisujące jak poszczególne elementy ze sobą współpracyją)
    - Mechanizmy architektury
        - szczegóły dotyczące implementacji artefaktów systemu
- Definiowanie klas i obiektów

#### Reguła Podstawowa (Liskova)

> Funkcje które używają wskaźników lub referencji do klas bazowych, muszą być w stanie używać również obiektów klas dziedziczących po klasach bazowych, bez dokładnej znajomości tych obiektów.

> Typ C jest podtypem typu B, a B jest podtypem typu A, jeżeli program może używać obiektów typu C zamiast obiektów typu A i B nie zdając sobie z tego sprawy.

