# SI unit library
A header only library written with CMake for the international standard of units

![language](https://img.shields.io/badge/language-c++-blue.svg) ![c++](https://img.shields.io/badge/std-c++17-blue.svg)

## Features
- **Compile-time type safety**: Prevents invalid unit operations at compile-time.
- **Literals for base units**: Example: `10.0_s == Second(10.0)`.
- **Basic arithmetic operations**: Supports addition, subtraction, multiplication, and division.
- **Derived SI units**: Available in `derived_si_units.h`, including Newtons (N), Joules (J), Watts (W), etc.

## To be added
- Prefixes

## Installation
Simply include the headers in your project:
```cpp
#include "si_units.h"           // For base implementation
#include "derived_si_units.h"   // For derived unit definitions
