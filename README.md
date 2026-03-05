# RPN Calculator (Reverse Polish Notation)

A low-level mathematical expression parser and evaluator utilizing Reverse Polish Notation (RPN). The project was developed in C++ with a strong focus on manual data structure implementation and algorithmic efficiency.

## Key Features
* **Infix-to-Postfix Conversion**: Implementation of the Shunting-yard algorithm to handle operator precedence and nested parentheses.
* **Variable Arity Function Support**: Support for nested functions such as `IF`, `MIN`, and `MAX`. The program dynamically determines the number of function parameters during infix parsing.
* **Custom Data Structures (No STL)**: Core data structures, including **Stack and Queue**, were implemented from scratch using pointers and linked lists. The project avoids the C++ Standard Template Library (STL) and the `std::string` type to demonstrate low-level memory management.
* **Error Handling**: Robust detection of mathematical exceptions (e.g., division by zero) and identification of invalid tokens within expressions.
* **Manual Memory Management**: Explicit allocation and deallocation of resources to ensure performance and prevent memory leaks.

## Technologies & Concepts
* **Language**: C++
* **Core Topics**: Algorithms, Data Structures, Pointers, Manual Memory Management.

## Sample Input & Output
**Input:**
* **The first line specifies the number of formulas, followed by expressions, each ending with a period.**

```text
1
N ( ( MAX ( 0 , 1 ) + N ( 1 ) ) ) .
```

**Output:**
* **The program first prints the postfix (RPN) form, followed by the calculation steps (operator and current stack state), and finally the result.**
```text
0 1 MAX2 1 N + N      # Postfix notation (MAX2 denotes function with 2 arguments)
MAX2 1 0              # Before MAX: stack contains 1 and 0
N 1 1                 # Before N (negation): stack contains 1, beneath is MAX result

-1 1                # Before addition: stack contains -1 and 1
N 0                   # Before final negation: stack contains addition result (0)
0                     # Final result
```

## How to Run
1. **Clone the repository:**
	```bash
	git clone https://github.com/szachusia/RPN-Calculator
	cd RPN-Calculator/Calculator
	```

2. **Compile the files using a C++ compiler (e.g., g++):**
	```bash
	g++ Calculator.cpp -o rpn_calculator
	```

3. **Run the program:**
	```bash
  # Dla Linux, macOS i Windows PowerShell:
	./rpn_calculator

	# Dla Windows CMD:
	rpn_calculator
  ```