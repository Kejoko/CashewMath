#include <iostream>

#include "Cashew/Linear.h"

int testVectorDotProduct() {
    std::cout << "----- Vector dot product -----\n";
    
    return 0;
}





int testVectorCrossProduct() {
    std::cout << "----- Vector cross product -----\n";
    
    return 0;
}





int main() {
    int success = 0;
    
    success = testVectorDotProduct();
    if (success != 0) return success;
    
    success = testVectorCrossProduct();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
