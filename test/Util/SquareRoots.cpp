#include <iostream>

#include <cmath>

#include <vector>

#include "Cashew/Util.h"


int sqrtTester(double testFuncDbl(double), double testFuncInt(int), double ansFunc(double), double desiredErr) {
    int square;
    int startVal = 1;
    int iterations = 100;
    double desiredError = desiredErr;
    double compound = 1.35;
    double fastIntAns, realIntAns;
    double fastDoubleAns, realDoubleAns;
    double intDifference, intError;
    double doubleDifference, doubleError;
    std::vector<double> intErrors(iterations);
    std::vector<double> doubleErrors(iterations);
    
    for (int i = startVal; i < startVal + iterations; i++) {
        square = i*i;
        if (testFuncInt != nullptr) {
            fastIntAns = testFuncInt(square);
        } else {
            fastIntAns = testFuncDbl(square);
        }
        realIntAns = 1 / sqrt(square);
        intDifference = abs(fastIntAns - realIntAns);
        intError = (intDifference / realIntAns) * 100;
        
        intErrors[i - startVal] = intError;
        
        if (intError > desiredError) {
            std::cerr << "ERROR - " << i
                      << " fastInvSqrt of " << square
                      << " is not correct.\n"
                      << "% error : " << intError << '\n'
                      << fastIntAns << '\n'
                      << realIntAns << "\n\n";
            return 1;
        }
        
        compound *= 30;
        fastDoubleAns = testFuncDbl(compound);
        realDoubleAns = ansFunc(compound);
        doubleDifference = abs(fastDoubleAns - realDoubleAns);
        doubleError = (doubleDifference / realDoubleAns) * 100;
        
        doubleErrors[i - startVal] = doubleError;
        
        if (doubleError > desiredError) {
            std::cerr << "ERROR - " << i
                      << " fastInvSqrt of " << compound
                      << " is not correct.\n"
                      << "% error : " << doubleError << '\n'
                      << fastDoubleAns << '\n'
                      << realDoubleAns << "\n\n";
            return 2;
        }
    }
    
    double intErrorSum = 0;
    double doubleErrorSum = 0;
    for (int i = 0; i < iterations; i++) {
        intErrorSum = intErrorSum + intErrors[i];
        doubleErrorSum = doubleErrorSum + doubleErrors[i];
    }
    
    double avgIntError = intErrorSum / iterations;
    double avgDoubleError = doubleErrorSum / iterations;
    std::cout << "Integer average error % : "
              << avgIntError << '\n';
    std::cout << "Double  average error % : "
              << avgDoubleError << '\n';
    
    return 0;
}





int testFastSqrt() {
    std::cout << "----- Fast Square Root -----\n";
    
    //    return sqrtTester(0.0005);
        return 0;
}





int testfastInvSqrt64() {
    std::cout << "----- Fast Inverse Square Root -----\n";
    
    auto ansFunc = [](double val) { return (1 / sqrt(val)); };
    
    return sqrtTester(Cashew::fastInvSqrt,
                      nullptr,
                      ansFunc,
                      0.005);
}





int main() {
    int success = 0;
    
    success = testfastInvSqrt64();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
