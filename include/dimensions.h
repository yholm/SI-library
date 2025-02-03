#ifndef DIMENSIONS_H
#define DIMENSIONS_H

#include <type_traits>

template <int t, int l, int m, int ec, int tt, int aos, int li>
struct Dimensions {
    public:
        static constexpr int T = t;  
        static constexpr int L = l;  
        static constexpr int M = m;  
        static constexpr int EC = ec; 
        static constexpr int TT = tt; 
        static constexpr int AOS = aos; 
        static constexpr int LI = li; 

        using type = Dimensions<t, l, m, ec, tt, aos, li>;

        template <typename Other>
        using multiply = Dimensions<T + Other::T, L + Other::L, M + Other::M, EC + Other::EC, TT + Other::TT, AOS + Other::AOS, LI + Other::LI>;

        template <typename Other>
        using divide = Dimensions<T - Other::T, L - Other::L, M - Other::M, EC - Other::EC, TT - Other::TT, AOS - Other::AOS, LI - Other::LI>;
};

using Time              = Dimensions<1,  0,  0,  0,  0,  0,  0>; 
using Length            = Dimensions<0,  1,  0,  0,  0,  0,  0>; 
using Mass              = Dimensions<0,  0,  1,  0,  0,  0,  0>;
using ElectricCurrent   = Dimensions<0,  0,  0,  1,  0,  0,  0>;
using Temperature       = Dimensions<0,  0,  0,  0,  1,  0,  0>;
using Amount            = Dimensions<0,  0,  0,  0,  0,  1,  0>;
using LuminousIntensity = Dimensions<0,  0,  0,  0,  0,  0,  1>;

#endif
