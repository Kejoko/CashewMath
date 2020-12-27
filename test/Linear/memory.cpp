// Keegan Kochis
// 2020 December 26th

#include <iostream>

#include "Cashew/Linear.h"

int main() {
    
    Cashew::Vector<double> vecd(8);
    std::cout << vecd;
    vecd.fill(8);
    std::cout << vecd;
    
    Cashew::Vector<double> vecd2(20, 39.1);
    std::cout << vecd2;
    
    Cashew::Matrix<double> matd(4,8);
    std::cout << matd;
    
    return 0;
}
