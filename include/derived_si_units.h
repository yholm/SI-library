#ifndef DERIVED_SI_UNITS_H
#define DERIVED_SI_UNITS_H

#include "si_units.h"

using Frequency             = Time::inverse;
using Force                 = Length::multiply<Mass>::multiply<Frequency>::multiply<Frequency>;
using Pressure              = Force::divide<Length>::divide<Length>;
using Energy                = Force::multiply<Length>;
using Power                 = Energy::divide<Time>;
using ElectricCharge        = Time::multiply<ElectricCurrent>;
using ElectricPotential     = Power::divide<ElectricCurrent>;
using ElectricResistance    = ElectricPotential::divide<ElectricCurrent>;

using Hertz     = SIUnit<Frequency>;
using Newton    = SIUnit<Force>;
using Pascal    = SIUnit<Pressure>;
using Joule     = SIUnit<Energy>;
using Watt      = SIUnit<Power>;
using Coulomb   = SIUnit<ElectricCharge>;
using Volt      = SIUnit<ElectricPotential>;
using Ohm       = SIUnit<ElectricResistance>;

constexpr Hertz operator"" _Hz(long double val) {
    return Hertz(static_cast<double>(val));
}

constexpr Newton operator"" _N(long double val) {
    return Newton(static_cast<double>(val));
}

constexpr Pascal operator"" _Pa(long double val) {
    return Pascal(static_cast<double>(val));
}

constexpr Joule operator"" _J(long double val) {
    return Joule(static_cast<double>(val));
}

constexpr Watt operator"" _W(long double val) {
    return Watt(static_cast<double>(val));
}

constexpr Coulomb operator"" _C(long double val) {
    return Coulomb(static_cast<double>(val));
}

constexpr Volt operator"" _V(long double val) {
    return Volt(static_cast<double>(val));
}

#endif
