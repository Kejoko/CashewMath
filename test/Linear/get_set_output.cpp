#include <iostream>

#include "Cashew/Math.h"

int testBracketOperator(Cashew::Vector<double>& vec) {
    std::cout << "First    : " << vec[0] << '\n'
              << "Last     : " << vec[vec.size() - 1] << '\n';
    
    try {
        std::cout << "Last +1  : " << vec[vec.size()] << '\n';
        std::cerr << "ERROR - Able to access out of bounds element (size)\n";
        return 1;
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    
    try {
        std::cout << "First -1 : " << vec[-1] << '\n';
        std::cerr << "ERROR - Able to access out of bounds element (-1)\n";
        return 2;
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    
    return 0;
}

int main() {
    Cashew::Vector<double> vec(10);
    
    return testBracketOperator(vec);
}
