// Keegan Kochis
// 2021 January 1st

#ifndef CASHEW_SQRT_H_INCLUDE
#define CASHEW_SQRT_H_INCLUDE

#include <cmath>
#include <cstdint>

namespace Cashew {

    // This fucking manic algorithm was taken from Quake
    // The ouble precision version from internet
    // This shit is absolute magic, my man.
    // https://en.wikipedia.org/wiki/Fast_inverse_square_root#Algorithm
    // https://cs.uwaterloo.ca/~m32rober/rsqrt.pdf
    double fastInvSqrt(double y) {
        double x2 = 0.5 * y;
        
        // Hack to bitwise copy value to an int for bit manipulation later
        uint64_t i = *(uint64_t*) &y;
        
        // Magic number taken from page 33 of Waterloo paper
        i = 0x5fe6eb50c7b537a9 - (i >> 1);
        
        // Reverse bit copy hack
        y = *(double*) &i;
        
        // 2 Newton's method iterations. 2nd iteration is not necessary
        y = y * (1.5 - (x2 * y * y));
        y = y * (1.5 - (x2 * y * y));
        
        return y;
    }

    double fastSqrt(double value) {
        
        return sqrt(value);
    }

}

#endif // CASHEW_SQRT_H_INCLUDE
