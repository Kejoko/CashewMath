#include <iostream>

#include "Cashew/Linear.h"

int testVectorNorm() {
    std::cout << "----- Vector norm -----\n";
    
    std::cout << '\n';
    return 0;
}





int testVectorNormalization() {
    std::cout << "----- Vector normalization -----\n";
    
    std::cout << '\n';
    return 0;
}





int main() {
    int success = 0;
    
    success = testVectorNorm();
    if (success != 0) return success;
    
    success = testVectorNormalization();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
