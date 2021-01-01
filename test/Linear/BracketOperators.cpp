#include <iostream>

#include "Cashew/Math.h"

template<size_t S>
int testVecAccess(Cashew::Vector<double, S>& vec) {
    std::cout << "----- Vector access via [] -----\n";
    
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
    
    std::cout << '\n';
    return 0;
}





template<size_t S>
int testVecMutate(Cashew::Vector<double, S>& vec) {
    std::cout << "----- Vector mutate via [] -----\n";
    
    std::cout << "Modifying element 0\n";
    vec[0] = 42;
    
    std::cout << "Modifying element " << vec.size() - 1 << '\n';
    vec[vec.size()-1] = -6.9;
    
    try {
        std::cout << "Modifying element " << vec.size() << '\n';
        vec[vec.size()] = vec.size();
        std::cerr << "ERROR - Able to mutate out of bounds element (size)\n";
        return 3;
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    
    try {
        std::cout << "Modifying element -1\n";
        vec[-1] = -1.1;
        std::cerr << "ERROR - Able to mutate out of bounds element (-1)\n";
        return 4;
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    
    std::cout << '\n';
    return 0;
}





template<size_t R, size_t C>
int testMatAccess(Cashew::Matrix<double, R, C>& mat) {
    std::cout << "----- Matrix access via [][] -----\n";
    
    std::cout << "First    : " << mat[0][0] << '\n'
              << "Last     : " << mat[mat.rows()-1][mat.cols()-1] << '\n';
    
    try {
        std::cout << "Last +1  : " << mat[mat.rows()][mat.cols()] << '\n';
        std::cerr << "ERROR - Able to access out of bounds element (size)\n";
        return 5;
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    
    try {
        std::cout << "First -1 : " << mat[-1][-1] << '\n';
        std::cerr << "ERROR - Able to access out of bounds element (-1)\n";
        return 6;
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    
    std::cout << '\n';
    return 0;
}





template<size_t R, size_t C>
int testMatMutate(Cashew::Matrix<double, R, C>& mat) {
    std::cout << "----- Matrix mutate via [][] -----\n";
    
    std::cout << "Modifying element 0,0\n";
    mat[0][0] = 42;
    
    std::cout << "Modifying element " << mat.rows()-1 << ',' << mat.cols()-1 << '\n';
    mat[mat.rows()-1][mat.cols()-1] = -69.039400;
    
    try {
        std::cout << "Modifying element " << mat.rows() << ',' << mat.cols() << '\n';
        mat[mat.rows()][mat.cols()] = mat.size();
        std::cerr << "ERROR - Able to mutate out of bounds element (" << mat.rows() << ',' << mat.cols() << ")\n";
        return 7;
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    
    try {
        std::cout << "Modifying element -1,-1\n";
        mat[-1][-1] = -1.1;
        std::cerr << "ERROR - Able to mutate out of bounds element (-1,-1)\n";
        return 8;
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    
    std::cout << '\n';
    return 0;
}





int main() {
    int success = 0;
    
    // Vector
    Cashew::Vector<double, 3> vec;
    std::cout << "Vector size " << vec.size() << '\n';
    
    success = testVecMutate(vec);
    if (success != 0) return success;
    
    success = testVecAccess(vec);
    if (success != 0) return success;
    
    std::cout << vec << "\n\n";
    
    // Matrix
    Cashew::Matrix<double, 4, 3> mat;
    std::cout << "Matrix dimensions " << mat.rows() << 'x' << mat.cols() << '\n';
    
    success = testMatMutate(mat);
    if (success != 0) return success;
    
    success = testMatAccess(mat);
    if (success != 0) return success;
    
    std::cout << mat << "\n\n";
    
    // Success
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
