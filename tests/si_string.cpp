#include "si_units.h"
#include "derived_si_units.h"
#include <cassert>
#include <iostream>

int main() {
    assert(Force::symbolStr() == "s^-2 * m * kg");
    std::cout << "Newtons passed\n";
}
