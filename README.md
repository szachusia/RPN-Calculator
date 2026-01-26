# Kalkulator RPN (ONP)

Projekt implementuje niskopoziomowy parser i ewaluator wyrażeń matematycznych wykorzystujący Odwróconą Notację Polską (RPN). Program został napisany w języku C++ z naciskiem na samodzielną implementację struktur danych oraz algorytmikę.

## Główne funkcjonalności
* **Konwersja Infix-to-Postfix**: Implementacja algorytmu stacyjnego (Shunting-yard) do obsługi priorytetów operatorów oraz nawiasów.
* **Obsługa funkcji o zmiennej arytności**: Wsparcie dla funkcji zagnieżdżonych, takich jak `IF`, `MIN` oraz `MAX`. Program dynamicznie wyznacza liczbę parametrów funkcji w trakcie parsowania zapisu infiksowego.
* **Samodzielna implementacja struktur danych**: Wszystkie kluczowe struktury danych, w tym **Stos (Stack) oraz Kolejka (Queue)**, zostały zaimplementowane od zera przy użyciu wskaźników i list wiązanych. Projekt nie wykorzystuje biblioteki standardowej STL ani typu `std::string`.
* **Obsługa błędów**: System wykrywania wyjątków matematycznych, w tym dzielenia przez zero, oraz identyfikacji nieprawidłowych tokenów w wyrażeniu.
* **Zarządzanie pamięcią**: Ręczna alokacja i zwalnianie zasobów w celu zapewnienia wydajności i zapobiegania wyciekom pamięci.

## Technologie i koncepcje
* **Język**: C++
* **Kluczowe zagadnienia**: Algorytmy, struktury danych, wskaźniki, ręczne zarządzanie pamięcią.

## Przykładowy input i output
**Dane wejściowe:**
```text
N ( ( MAX ( 0 , 1 ) + N ( 1 ) ) ) .
```

**Wynik działania programu:**
```text
0 1 MAX2 1 N + N
MAX2 1 0
N 1 1
+ -1 1
N 0
0
```

## Jak uruchomić projekt
1. **Pobierz repozytorium:**
   ```bash
   git clone https://github.com/szachusia/RPN-Calculator
   cd Calculator
   ```
2. Skompiluj pliki przy użyciu dowolnego kompilatora C++ (np. g++):
   ```bash
   g++ Calculator.cpp -o rpn_calculator
   ```
   
3. Uruchom program:
   ```bash
   ./rpn_calculator
   ```
   