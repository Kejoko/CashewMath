#include <iostream>

#include "Cashew/Linear.h"

int testMatrixInvertible() {
    std::cout << "----- Matrix invertible -----\n";
    
    std::cout << '\n';
    return 0;
}





int testMatrixInverse() {
    std::cout << "----- Matrix inverse -----\n";
    
    std::cout << '\n';
    return 0;
}





int main() {
    int success = 0;
    
    success = testMatrixInvertible();
    if (success != 0) return success;
    
    success = testMatrixInverse();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
