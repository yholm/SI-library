#include "si_units.h"
#include <cassert>
#include <iostream>

void add() {
    auto x = Meter(10.0);
    auto y = Meter(5.0);
    auto result = x + y;

    assert(result == Meter(15.0));
    std::cout << "Addition passed\n";
}

void sub() {
    auto x = Meter(10.0);
    auto y = Meter(5.0);
    auto result = x - y;

    assert(result == Meter(5.0));
    std::cout << "Subtraction passed\n";
}

void mul() {
    auto x = Second(5.0);
    auto y = Ampere(10.0);
    auto result = x * y;

    using ElectricCharge = Dimensions<1, 0, 0, 1, 0, 0, 0>;
    assert(result == SIUnit<ElectricCharge>(50.0));

    auto a = Second(5.0);
    auto result2 = a * 5.0;

    assert(result2 == Second(25.0));
    std::cout << "Multiplication passed\n";
}

void div() {
    auto x = Meter(20.0);
    auto y = Second(2.0);
    auto result = x / y;

    using Acceleration = Dimensions<-1, 1, 0, 0, 0, 0, 0>;
    assert(result == SIUnit<Acceleration>(10.0));

    auto a = Second(5.0);
    auto result2 = a / 5.0;

    assert(result2 == Second(1.0));
    std::cout << "Division passed\n";
}

int main() {
    add();
    sub();
    mul();
    div();
    std::cout << "\n";
}
