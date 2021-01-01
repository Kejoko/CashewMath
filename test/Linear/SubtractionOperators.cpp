#include <iostream>

#include "Cashew/Linear.h"

int testVectorSubtraction() {
    
    return 0;
}





int testMatrixSubtraction() {
    
    return 0;
}





int main() {
    int success = 0;
    
    success = testVectorSubtraction();
    if (success != 0) return success;
    
    success = testMatrixSubtraction();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
