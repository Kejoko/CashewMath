#include <iostream>

#include "Cashew/Linear.h"

int testVectorDivision() {
    std::cout << "----- Vector division with scalars via / and /= -----\n";
    
    Cashew::Vector<int, 3> vec1;
    vec1[0] = 150;
    vec1[1] = 100;
    vec1[2] = 50;
    Cashew::Vector<int, 3> vec2;
    Cashew::Vector<int, 3> result;
    result[0] = 30;
    result[1] = 20;
    result[2] = 10;
    
    vec2 = vec1 / 5;
    if (vec2 != result) {
        std::cerr << "ERROR - Cashew::Vector / failed on Vec1 / 5.\n";
        return 1;
    }
    
    vec2 /= 10;
    if (vec2 != (result / 10)) {
        std::cerr << "ERROR - Cashew::Vector /= failed on Vec2 /= 10.\n";
        return 2;
    }
    
    std::cout << '\n';
    return 0;
}





int testMatrixDivision() {
    std::cout << "----- Matrix division with scalars via / and /= -----\n";
    
    Cashew::Matrix<int, 2, 2> mat1;
    mat1[0][0] = 10;
    mat1[0][1] = 20;
    mat1[1][0] = 30;
    mat1[1][1] = 40;
    Cashew::Matrix<int, 2, 2> mat2;
    Cashew::Matrix<int, 2, 2> result;
    result[0][0] = 5;
    result[0][1] = 10;
    result[1][0] = 15;
    result[1][1] = 20;
    
    mat2 = mat1 / 2;
    if (mat2  != result) {
        std::cerr << "ERROR - Cashew::Matrix / failed on Mat1 / 2.\n";
        return 3;
    }
    
    mat2 /= 5;
    if (mat2 != (result / 5)) {
        std::cerr << "ERROR - Cashew::Matrix /= failed on Mat2 /= 5.\n";
        return 4;
    }
    
    std::cout << '\n';
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
