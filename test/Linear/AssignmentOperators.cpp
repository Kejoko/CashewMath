#include <iostream>

#include "Cashew/Linear.h"

int testVectorAssignment() {
    std::cout << "----- Vector assignment via = -----\n";
    
    Cashew::Vector<double> vec1(4);
    vec1[0] = .0001;
    vec1[1] = 82;
    vec1[2] = 2.1039;
    vec1[3] = -308.009;
    std::cout << "Vec1 : " << vec1.size() << ' ' << vec1 << '\n';
    
    Cashew::Vector<double> vec2(4);
    std::cout << "Vec2 : " << vec2.size() << ' ' << vec2 << '\n';
    
    Cashew::Vector<double> vec3(5);
    std::cout << "Vec3 : " << vec3.size() << ' ' << vec3 << '\n';
    
    vec2 = vec1;
    if (vec2 != vec1) {
        std::cerr << "ERROR - Unable to assign Vec1 to Vec2.\n";
        return 1;
    } else {
        std::cout << "Successfully assigned Vec1 to Vec2 : " << vec2 << '\n';
    }
    
    try {
        vec2 = vec3;
        std::cerr << "ERROR - Cannot assign Vectors of different lengths.\n";
        return 2;
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    
    std::cout << '\n';
    return 0;
}





int testMatrixAssignment() {
    std::cout << "----- Matrix assignment via = -----\n";
    
    Cashew::Matrix<double> mat1(2,2);
    mat1[0][0] = .0001;
    mat1[0][1] = 82;
    mat1[1][0] = 2.1039;
    mat1[1][1] = -308.009;
    std::cout << "Mat1 : " << mat1.rows() << 'x' << mat1.cols() << '\n';
    std::cout << mat1 << '\n';
    
    Cashew::Matrix<double> mat2(2,2);
    std::cout << "Mat2 : " << mat2.rows() << 'x' << mat2.cols() << '\n';
    std::cout << mat2 << '\n';
    
    Cashew::Matrix<double> mat3(3,3);
    std::cout << "Mat3 : " << mat3.rows() << 'x' << mat3.cols() << '\n';
    std::cout << mat3 << '\n';
    
    mat2 = mat1;
    if (mat2 != mat1) {
        std::cerr << "ERROR - Unable to assign Mat1 to Mat2.\n";
        return 3;
    } else {
        std::cout << "Successfully assigned Mat1 to Mat2 :\n" << mat2 << '\n';
    }
    
    try {
        mat2 = mat3;
        std::cerr << "ERROR - Cannot assign Matrices of different sizes to eachother.\n";
        return 4;
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}





int main() {
    int success = 0;
    
    success = testVectorAssignment();
    if (success != 0) return success;
    
    success = testMatrixAssignment();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
