#include <iostream>

#include "Cashew/Linear.h"

int testVectorComparison() {
    std::cout << "----- Vector comparison -----\n";
    
    Cashew::Vector<double, 3> vec1;
    vec1[0] = 30.0;
    vec1[1] = 798;
    vec1[2] = -89.99;
    std::cout << "Vec1 : " << vec1.size() << ' ' << vec1 << '\n';
    
    Cashew::Vector<double, 3> vec2;
    vec2[0] = 30.0;
    vec2[1] = 798;
    vec2[2] = -89.99;
    std::cout << "Vec2 : " << vec2.size() << ' ' << vec2 << '\n';
    
    Cashew::Vector<double, 3> vec3;
    std::cout << "Vec3 : " << vec3.size() << ' ' << vec3 << '\n';
    
    Cashew::Vector<double, 4> vec4;
    std::cout << "Vec4 : " << vec4.size() << ' ' << vec4 << '\n';
    
    if (vec1 == vec2) {
        std::cout << "Success: Vec1 == Vec2\n";
    } else if (vec1 != vec2) {
        std::cerr << "ERROR - Vec1(" << vec1 << ") should equal Vec2(" << vec2 << ")\n";
        return 1;
    }
    
    if (vec1 == vec3) {
        std::cerr << "ERROR - Vec1(" << vec1 << ") should not equal Vec2(" << vec2 << ")\n";
        return 2;
    } else if (vec1 != vec3) {
        std::cout << "Success: Vec1 != Vec3\n";
    }
    
    std::cout << '\n';
    return 0;
}





int testMatrixComparison() {
    std::cout << "----- Matrix comparison -----\n";
    
    Cashew::Matrix<double, 2, 2> mat1;
    mat1[0][0] = 1234.5678;
    mat1[0][1] = -0.1;
    mat1[1][0] = 0.9999999;
    mat1[1][1] = 367;
    std::cout << "Mat1 : " << mat1.rows() << 'x' << mat1.cols() << '\n' << mat1 << '\n';
    
    Cashew::Matrix<double, 2, 2> mat2;
    mat2[0][0] = 1234.5678;
    mat2[0][1] = -0.1;
    mat2[1][0] = 0.9999999;
    mat2[1][1] = 367;
    std::cout << "Mat2 : " << mat2.rows() << 'x' << mat2.cols() << '\n' << mat2 << '\n';
    
    Cashew::Matrix<double, 2, 2> mat3;
    std::cout << "Mat3 : " << mat3.rows() << 'x' << mat3.cols() << '\n' << mat3 << '\n';
    
    Cashew::Matrix<double, 3, 3> mat4;
    std::cout << "Mat4 : " << mat4.rows() << 'x' << mat4.cols() << '\n' << mat4 << '\n';
    
    if (mat1 == mat2) {
        std::cout << "Success: Mat1 == Mat2\n";
    } else if (mat1 != mat2) {
        std::cerr << "ERROR - Mat1 should equal Mat2\n";
        return 3;
    }
    
    if (mat1 == mat3) {
        std::cerr << "ERROR - Mat1 should not equal Mat3\n";
        return 4;
    } else if (mat1 != mat3) {
        std::cout << "Success: Mat1 != Mat3\n";
    }
    
    std::cout << '\n';
    return 0;
}





int main() {
    int success = 0;
    
    success = testVectorComparison();
    if (success != 0) return success;
    
    success = testMatrixComparison();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
