#include <iostream>

#include "Cashew/Linear.h"

int testVectorMultiplication() {
    std::cout << "----- Vector multiplication with scalars via * and *= -----\n";
    
    Cashew::Vector<int, 3> vec1;
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 3;
    Cashew::Vector<int, 3> vec2;
    Cashew::Vector<int, 3> result;
    result[0] = 3;
    result[1] = 6;
    result[2] = 9;
    
    vec2 = vec1 * 3;
    if (vec2 != result) {
        std::cerr << "ERROR - Cashew::Vector * failed on Vec1 * 3.\n";
        return 1;
    }
    
    vec2 *= 29;
    if (vec2 != (29 * result)) {
        std::cerr << "ERROR - Cashew::Vector *= failed on Vec2 *= 29.\n";
        return 2;
    }
    
    std::cout << '\n';
    return 0;
}





int testMatrixMultiplication() {
    std::cout << "----- Matrix Multiplication with scalars via * and *= -----\n";
    
    Cashew::Matrix<int, 2, 2> mat1;
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;
    Cashew::Matrix<int, 2, 2> mat2;
    Cashew::Matrix<int, 2, 2> result;
    result[0][0] = 2;
    result[0][1] = 4;
    result[1][0] = 6;
    result[1][1] = 8;
    
    mat2 = 2 * mat1;
    if (mat2  != result) {
        std::cerr << "ERROR - Cashew::Matrix * failed on Mat1 * 2.\n";
        return 3;
    }
    
    mat2 *= -7;
    if (mat2 != (result * -7)) {
        std::cerr << "ERROR - Cashew::Matrix *= failed on Mat2 *= -7.\n";
        return 4;
    }
    
    std::cout << '\n';
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
