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
* **W pierwszej linii podajemy liczbę formuł, a następnie wyrażenia każde zakończone kropką.**

```text
1
N ( ( MAX ( 0 , 1 ) + N ( 1 ) ) ) .
```

**Wynik działania programu:**
* **Program najpierw wypisuje postać postfiksową (ONP), a następnie kroki obliczeń (operator oraz aktualną zawartość stosu), na końcu wypisuje ostateczną wartość wyrażenia.**
```text
0 1 MAX2 1 N + N     # Notacja postfiksowa (MAX2 oznacza funkcję z 2 argumentami)
MAX2 1 0             # Przed wykonaniem MAX: na stosie są 1 i 0
N 1 1                # Przed wykonaniem N (negacji): na stosie jest 1, pod nią wynik z MAX
+ -1 1               # Przed dodawaniem: na stosie są -1 oraz 1
N 0                  # Przed końcową negacją: na stosie jest wynik dodawania (0)
0                    # Wynik końcowy
```

## Jak uruchomić projekt
1. **Pobierz repozytorium:**
   ```bash
   git clone https://github.com/szachusia/RPN-Calculator
   cd RPN-Calculator/Calculator
   ```
2. Skompiluj pliki przy użyciu dowolnego kompilatora C++ (np. g++):
   ```bash
   g++ Calculator.cpp -o rpn_calculator
   ```
   
3. Uruchom program:
   ```bash
   # Dla Linux, macOS i Windows PowerShell:
	./rpn_calculator

	# Dla Windows CMD:
	rpn_calculator
   ```
   