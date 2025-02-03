#ifndef SI_UNITS_H
#define SI_UNITS_H

#include "dimensions.h"
#include <stdexcept>

template <typename T>
class SIUnit {
    public:
        double value;

        constexpr SIUnit(double val) : value(val) {}

        template <typename OtherT>
        constexpr SIUnit<T> operator+(const SIUnit<OtherT>& other) {
            static_assert(std::is_same_v<T, OtherT>, "Cannot add SIUnits with different dimensions");
    
            return SIUnit<T>{value + other.value};   
        }

        template <typename OtherT>
        constexpr SIUnit<T> operator-(const SIUnit<OtherT>& other) {
            static_assert(std::is_same_v<T, OtherT>, "Cannot add SIUnits with different dimensions");
    
            return SIUnit<T>{value - other.value}; 
        }

        template <typename OtherT>
            constexpr SIUnit<typename T::template multiply<OtherT>> operator*(const SIUnit<OtherT>& other) const {
            return SIUnit<typename T::template multiply<OtherT>>{value * other.value};
        }   

        template <typename OtherT>
        constexpr SIUnit<typename T::template divide<OtherT>> operator/(const SIUnit<OtherT>& other) const {
            return SIUnit<typename T::template divide<OtherT>>{value / other.value};
        }

        constexpr SIUnit<T> operator*(double scalar) const {
            return SIUnit<T>{value * scalar};
        }

        constexpr SIUnit<T> operator/(double scalar) const {
            return SIUnit<T>{value / scalar};
        }

        template <typename OtherT>
        constexpr bool operator==(const SIUnit<OtherT>& other) const {
            return (std::is_same_v<T, OtherT> && (value == other.value));
        }
};

using Second    = SIUnit<Time>;
using Meter     = SIUnit<Length>;
using Kilogram  = SIUnit<Mass>;
using Ampere    = SIUnit<ElectricCurrent>;
using Kelvin    = SIUnit<Temperature>;
using Mole      = SIUnit<Amount>;
using Candela   = SIUnit<LuminousIntensity>;

static Second operator"" _s(long double val) {
	return Second(static_cast<float>(val));
}

static Meter operator"" _m(long double val) {
	return Meter(static_cast<double>(val));
}

static Kilogram operator"" _kg(long double val) {
	return Kilogram(static_cast<double>(val));
}

static Ampere operator"" _A(long double val) {
	return Ampere(static_cast<double>(val));
}

static Kelvin operator"" _K(long double val) {
	return Kelvin(static_cast<double>(val));
}

static Mole operator"" _mol(long double val) {
	return Mole(static_cast<double>(val));
}

static Candela operator"" _cd(long double val) {
	return Candela(static_cast<double>(val));
}

#endif
