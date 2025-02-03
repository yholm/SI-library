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

#endif
