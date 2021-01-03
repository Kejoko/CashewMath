#include <iostream>

#include "Cashew/Linear.h"

int testVectorNorm() {
    std::cout << "----- Vector norm -----\n";
    
    Cashew::Vector<int, 2> vec1;
    vec1[0] = 3;
    vec1[1] = 4;
    double result1 = vec1.norm();
    if (result1 != 5) {
        std::cerr << "ERROR - Vec1 norm " << result1 << " is not 5.\n";
        return 1;
    } else {
        std::cout << "Success : Vec1 norm = " << result1 << '\n';
    }
    
    Cashew::Vector<long long, 80> vec2;
    vec2[67] = -144;
    double result2 = vec2.norm();
    if (result2 != 144) {
        std::cerr << "ERROR - Vec2 norm " << result2 << " is not 144.\n";
        return 2;
    } else {
        std::cout << "Success : Vec2 norm = " << result2 << '\n';
    }
    
    Cashew::Vector<bool, 1> vec3;
    vec3[0] = true;
    double result3 = vec3.norm();
    if (result3 != 1) {
        std::cerr << "ERROR - Vec3 norm " << result3 << " is not 1.\n";
        return 3;
    } else {
        std::cout << "Success : Vec3 norm = " << result3 << '\n';
    }
    
    Cashew::Vector<char, 8> vec4;
    double result4 = vec4.norm();
    if (result4 != 0) {
        std::cerr << "ERROR - Vec4 norm " << result4 << " is not 0.\n";
        return 4;
    } else {
        std::cout << "Success : Vec4 norm = " << result4 << '\n';
    }
    
    std::cout << '\n';
    return 0;
}





int testVectorNormalization() {
    std::cout << "----- Vector normalization -----\n";
    
    std::cout << '\n';
    return 0;
}





int main() {
    int success = 0;
    
    success = testVectorNorm();
    if (success != 0) return success;
    
    success = testVectorNormalization();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
