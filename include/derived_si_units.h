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
using Couloumb  = SIUnit<ElectricCharge>;
using Volt      = SIUnit<ElectricPotential>;
using Ohm       = SIUnit<ElectricResistance>;

#endif
