#include <iostream>

#include "Cashew/Linear.h"

int testVectorDivision() {
    
    return 0;
}





int testMatrixDivision() {
    
    return 0;
}





int main() {
    int success = 0;
    
    success = testVectorDivision();
    if (success != 0) return success;
    
    success = testMatrixDivision();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
