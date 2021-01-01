#include <iostream>

#include "Cashew/Linear.h"

int testMatrixVectorMultiplication() {
    std::cout << "----- Matrix * Vector multiplication -----\n";
    
    std::cout << '\n';
    return 0;
}





int testMatrixMatrixMultiplication() {
    std::cout << "----- Matrix * Matrix multiplication -----\n";
    
    std::cout << '\n';
    return 0;
}





int main() {
    int success = 0;
    
    success = testMatrixVectorMultiplication();
    if (success != 0) return success;
    
    success = testMatrixMatrixMultiplication();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
