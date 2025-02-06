#ifndef DIMENSIONS_H
#define DIMENSIONS_H

#include <type_traits>
#include <string>

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

        using inverse = Dimensions<-t, -l, -m, -ec, -tt, -aos, -li>;

        static std::string symbolStr() {
            std::string symbols = "";
            if (T != 0) {
                if (!symbols.empty()) symbols.append(" * ");
                if (T != 1) {
                    symbols.append("s^");
                    symbols.append(std::to_string(T));
                } else symbols.append("s");
            }
            if (L != 0) {
                if (!symbols.empty()) symbols.append(" * ");
                if (L != 1) {
                    symbols.append("m^");
                    symbols.append(std::to_string(L));
                } else symbols.append("m");
            }
            if (M != 0) {
                if (!symbols.empty()) symbols.append(" * ");
                if (M != 1) {
                    symbols.append("kg^");
                    symbols.append(std::to_string(M));
                } else symbols.append("kg");
            }
            if (EC != 0) {
                if (!symbols.empty()) symbols.append(" * ");
                if (EC != 1) {
                    symbols.append("A^");
                    symbols.append(std::to_string(EC));
                } else symbols.append("A");
            }
            if (TT != 0) {
                if (!symbols.empty()) symbols.append(" * ");
                if (TT != 0) {
                    symbols.append("K^");
                    symbols.append(std::to_string(TT));
                } else symbols.append("K");
            }
            if (AOS != 0) {
                if (!symbols.empty()) symbols.append(" * ");
                if (AOS != 1) {    
                    symbols.append("mol^");
                    symbols.append(std::to_string(AOS));
                } else symbols.append("mol");
            }
            if (LI != 0) {
                if (!symbols.empty()) symbols.append(" * ");
                if (LI != 1) {
                    symbols.append("cd^");
                    symbols.append(std::to_string(LI));
                } else symbols.append("cd");
            }
            return symbols;
        }
};

using Time              = Dimensions<1,  0,  0,  0,  0,  0,  0>; 
using Length            = Dimensions<0,  1,  0,  0,  0,  0,  0>; 
using Mass              = Dimensions<0,  0,  1,  0,  0,  0,  0>;
using ElectricCurrent   = Dimensions<0,  0,  0,  1,  0,  0,  0>;
using Temperature       = Dimensions<0,  0,  0,  0,  1,  0,  0>;
using Amount            = Dimensions<0,  0,  0,  0,  0,  1,  0>;
using LuminousIntensity = Dimensions<0,  0,  0,  0,  0,  0,  1>;

#endif
