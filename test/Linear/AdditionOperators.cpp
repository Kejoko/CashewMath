#include <iostream>

#include "Cashew/Linear.h"

int testVectorAddition() {
    
    return 0;
}





int testMatrixAddition() {
    
    return 0;
}





int main() {
    int success = 0;
    
    success = testVectorAddition();
    if (success != 0) return success;
    
    success = testMatrixAddition();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
