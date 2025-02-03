#include "si_units.h"
#include <cassert>
#include <iostream>

int main() {
    assert(10.0_s == Second(10.0));
    std::cout << "Seconds passed\n";
    assert(10.0_m == Meter(10.0));
    std::cout << "Meters passed\n";
    assert(10.0_kg == Kilogram(10.0));
    std::cout << "Kilograms passed\n";
    assert(10.0_A == Ampere(10.0));
    std::cout << "Amperes passed\n";
    assert(10.0_K == Kelvin(10.0));
    std::cout << "Kelvin passed\n";
    assert(10.0_mol == Mole(10.0));
    std::cout << "Moles passed\n";
    assert(10.0_cd == Candela(10.0));
    std::cout << "Candela passed\n";
    std::cout << "\n";
}
