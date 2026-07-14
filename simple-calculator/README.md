# Simple Calculator

A terminal-based interactive calculator written in C.

## Compilation

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

## Run

./calculator

## Supported Operations

- Addition
- Subtraction
- Multiplication
- Division

## Numeric Behavior

The calculator uses decimal numbers with the double data type.

Whole-number results are displayed without unnecessary decimal zeros.
Decimal results are displayed when needed.

## Known Limitations

The mandatory version does not handle non-numeric input safely.
Division by zero is rejected.
