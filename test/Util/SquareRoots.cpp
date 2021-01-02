#include <iostream>

#include <cmath>

#include <vector>

#include "Cashew/Util.h"

int testFastInvSqrt() {
    std::cout << "----- Fast Inverse Square Root -----\n";
    
    int square;
    int startVal = 1;
    int iterations = 1000;
    double compound = 1.35;
    double tolerance = 0.175;
    double fastIntAns, realIntAns;
    double fastDoubleAns, realDoubleAns;
    double intDifference, intError;
    double doubleDifference, doubleError;
    std::vector<double> intErrors(iterations);
    std::vector<double> doubleErrors(iterations);
    
    for (int i = startVal; i < startVal + iterations; i++) {
        square = i*i;
        fastIntAns = Cashew::fastInvSqrt(square);
        realIntAns = sqrt(square);
        intDifference = abs(fastIntAns - realIntAns);
        intError = intDifference / realIntAns;
        
        intErrors.push_back(intError);
        
        if (intError > tolerance) {
            std::cout << "ERROR - " << i
                      << " fastInvSqrt of " << square
                      << " is not correct.\n"
                      << "% error : " << intError << '\n'
                      << fastIntAns << '\n'
                      << realIntAns << '\n';
            return 1;
        }
        
        
        
        
        
        compound *= compound;
        fastDoubleAns = Cashew::fastInvSqrt(compound);
        realDoubleAns = sqrt(compound);
        doubleDifference = abs(fastDoubleAns - realDoubleAns);
        doubleError = doubleDifference / realDoubleAns;
        
        doubleErrors.push_back(doubleError);
        
        if (doubleError > tolerance) {
            std::cout << "ERROR - " << i
                      << " fastInvSqrt of " << compound
                      << " is not correct.\n"
                      << "% error : " << doubleError << '\n'
                      << fastDoubleAns << '\n'
                      << realDoubleAns << '\n';
            return 2;
        }
    }
    
    return 0;
}





int main() {
    int success = 0;
    
    success = testFastInvSqrt();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
