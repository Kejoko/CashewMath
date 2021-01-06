#include <iostream>

#include "Cashew/Linear.h"

int testMatrixInverseFunctions() {
    std::cout << "----- Matrix determinant and inverse functions -----\n";
    
    Cashew::Matrix<double, 5, 4> matBad;
    
    try {
        double d = matBad.determinant();
        std::cerr << "ERROR - Can not take the determinant of a non-square matrix.\n";
        return 1;
    } catch (const std::exception& e) {
        std::cout << "Successfully caught error taking determinant of non-square matrix.\n";
    }
    
    Cashew::Matrix<double, 2, 2> mat1;
    mat1[0][0] = 3;
    mat1[0][1] = 8;
    mat1[1][0] = 4;
    mat1[1][1] = 6;
    
    Cashew::Matrix<double, 2, 2> mat1i;
    mat1i[0][0] = -3/7;
    mat1i[0][1] = 4/7;
    mat1i[1][0] = 2/7;
    mat1i[1][1] = -3/14;
    
    if (mat1.determinant() != -14) {
        std::cerr << "ERROR - Mat1 did not return determinant of -14.\n";
        return 2;
    } else if (!mat1.invertible()) {
        std::cerr << "ERROR - Mat1 with nonzero determinant should be invertible.\n";
    }
    
    mat1.invert();
    
    if (mat1 != mat1i) {
        std::cerr << "Inverted Mat1 does not match the Mat1"
                  << " inverse answer.\n"
                  << mat1 << '\n'
                  << mat1i << '\n';
        return 3;
    }
    
    Cashew::Matrix<double, 3, 3> mat2;
    mat2[0][0] = 6;
    mat2[0][1] = 1;
    mat2[0][2] = 1;
    mat2[1][0] = 4;
    mat2[1][1] = -2;
    mat2[1][2] = 5;
    mat2[2][0] = 2;
    mat2[2][1] = 8;
    mat2[2][2] = 7;
    
    Cashew::Matrix<double, 3, 3> mat2i;
    mat2[0][0] = 3/17;
    mat2[0][1] = -1/306;
    mat2[0][2] = -7/306;
    mat2[1][0] = 1/17;
    mat2[1][1] = -20/153;
    mat2[1][2] = 13/153;
    mat2[2][0] = -2/17;
    mat2[2][1] = 23/153;
    mat2[2][2] = 8/153;
    
    if (mat2.determinant() != -306) {
        std::cerr << "ERROR - Mat2 did not return determinant of -306.\n";
        return 4;
    } else if (!mat2.invertible()) {
        std::cerr << "ERROR - Mat2 with nonzero determinant should be invertible.\n";
    }
    
    mat2.invert();
    
    if (mat2 != mat2i) {
        std::cerr << "Inverted Mat2 does not match the Mat2"
                  << " inverse answer.\n"
                  << mat2 << '\n'
                  << mat2i << '\n';
        return 5;
    }
    
    Cashew::Matrix<double, 2, 2> mat3;
    
    if (mat3.determinant() != 0) {
        std::cerr << "ERROR - Zero matrix did not return determinant of 0.\n";
        return 6;
    } else if (mat3.invertible()) {
        std::cerr << "ERROR - Matrix with determinant of 0 should not be invertible.\n";
        return 7;
    }
    
    try {
        mat3.invert();
        std::cerr << "ERROR - Matrix with determinant of 0 should not be invertible.\n";
        return 8;
    } catch (const std::exception& e) {
        std::cout << "Successfully caught error from inverting non invertible matrix.\n";
    }
    
    return 0;
}





int main() {
    int success = 0;
    
    success = testMatrixInverseFunctions();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
