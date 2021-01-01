#include <iostream>

#include "Cashew/Linear.h"

int testVectorAddition() {
    std::cout << "----- Vector addition via + and += -----\n";
    
    Cashew::Vector<int, 3> vec1;
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 3;
    Cashew::Vector<int, 3> vec2;
    vec2[0] = 4;
    vec2[1] = 5;
    vec2[2] = 6;
    Cashew::Vector<int, 3> vec3;
    Cashew::Vector<int, 3> result;
    result[0] = 5;
    result[1] = 7;
    result[2] = 9;
    Cashew::Vector<int, 4> vec4;
    
    vec3 = vec1 + vec2;
    if (vec3 != result) {
        std::cerr << "ERROR - Cashew::Vector + failed on Vec1 + Vec2.\n";
        return 1;
    }
    
    vec3 += vec1;
    if (vec3 != (result + vec1)) {
        std::cerr << "ERROR - Cashew::Vector += failed on Vec3 += Vec1.\n";
        return 2;
    }
    
    std::cout << '\n';
    return 0;
}





int testMatrixAddition() {
    std::cout << "----- Matrix addition via + and += -----\n";
    
    Cashew::Matrix<int, 2, 2> mat1;
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;
    Cashew::Matrix<int, 2, 2> mat2;
    mat2[0][0] = 5;
    mat2[0][1] = 6;
    mat2[1][0] = 7;
    mat2[1][1] = 8;
    Cashew::Matrix<int, 2, 2> mat3;
    Cashew::Matrix<int, 2, 2> result;
    result[0][0] = 6;
    result[0][1] = 8;
    result[1][0] = 10;
    result[1][1] = 12;
    Cashew::Matrix<int, 3, 3> mat4;
    
    mat3 = mat1 + mat2;
    if (mat3  != result) {
        std::cerr << "ERROR - Cashew::Matrix + failed on Mat1 + Mat2.\n";
        return 4;
    }
    
    mat3 += mat1;
    if (mat3 != (result + mat1)) {
        std::cerr << "ERROR - Cashew::Matrix += failed on Mat3 += Mat1.\n";
        return 5;
    }
    
    std::cout << '\n';
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
