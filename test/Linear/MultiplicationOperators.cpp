#include <iostream>

#include "Cashew/Linear.h"

int testVectorMultiplication() {
    
    return 0;
}





int testMatrixMultiplication() {
    
    return 0;
}





int main() {
    int success = 0;
    
    success = testVectorMultiplication();
    if (success != 0) return success;
    
    success = testMatrixMultiplication();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
