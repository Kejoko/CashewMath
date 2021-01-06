#include <iostream>

#include "Cashew/Linear.h"

int testVectorDotProduct() {
    std::cout << "----- Vector dot product -----\n";
    
    Cashew::Vec3d vec3a;
    vec3a[0] = -1;
    vec3a[1] = 2;
    vec3a[2] = -3;
    Cashew::Vec3d vec3b;
    vec3b[0] = 3;
    vec3b[1] = -4;
    vec3b[2] = 5;
    if (vec3a.dot(vec3b) != -26) {
        std::cerr << "ERROR - " << vec3a
                  << " dot " << vec3b
                  << " did not result in -26.\n";
        return 1;
    }
    
    Cashew::Vec4d vec4a;
    vec4a[0] = 6;
    vec4a[1] = 7;
    vec4a[2] = 6;
    vec4a[3] = 7;
    Cashew::Vec4d vec4b;
    vec4b[0] = 0;
    vec4b[1] = -8;
    vec4b[2] = 6;
    vec4b[3] = 7;
    if (vec4a.dot(vec4b) != 29) {
        std::cerr << "ERROR - " << vec4a
                  << " dot " << vec4b
                  << " did not result in 29.\n";
        return 2;
    }
    
    Cashew::Vector<int, 5> vec5a;
    vec5a[0] = 3;
    vec5a[1] = 2;
    vec5a[2] = 9;
    Cashew::Vector<int, 5> vec5b;
    vec5a[3] = 5;
    vec5a[4] = 7;
    if (vec5a.dot(vec5b) != 0) {
            std::cerr << "ERROR - " << vec5a
                      << " dot " << vec5b
                      << " did not result in 0.\n";
            return 3;
    }
    
    return 0;
}





int testVectorCrossProduct() {
    std::cout << "----- Vector cross product -----\n";
    
    Cashew::Vec3d vec1a;
    vec1a[0] = 3;
    vec1a[1] = -3;
    vec1a[2] = 1;
    Cashew::Vec3d vec1b;
    vec1b[0] = 4;
    vec1b[1] = 9;
    vec1b[2] = 2;
    Cashew::Vec3d res1;
    res1[0] = -15;
    res1[1] = -2;
    res1[2] = 39;
    
    if (vec1a.cross(vec1b) != res1) {
        std::cerr << "ERROR - " << vec1a
                  << " x " << vec1b
                  << " did not give " << res1 << ".\n";
        return 4;
    }
    
    Cashew::Vec3d vec2a;
    vec1a[0] = 3;
    vec1a[1] = -3;
    vec1a[2] = 1;
    Cashew::Vec3d vec2b;
    vec1b[0] = -12;
    vec1b[1] = 12;
    vec1b[2] = -4;
    Cashew::Vec3d res2;
    res1[0] = 0;
    res1[1] = 0;
    res1[2] = 0;
    
    if (vec2a.cross(vec2b) != res2) {
        std::cerr << "ERROR - " << vec2a
                  << " x " << vec2b
                  << " did not give " << res2 << ".\n";
        return 5;
    }
    
//    Cashew::Vector<int, 5> vec5a;
//    Cashew::Vector<int, 5> vec5b;
//    try {
//        Cashew::Vector<int, 5> res5 = vec5a.cross(vec5b);
//        std::cerr << "ERROR - Cross product should not be defined for Vectors not of length 3.\n";
//        return 6;
//    } catch (const std::exception& e) {
//        std::cout << "Success - Cross product not working for size 5 Vector.\n";
//    }

    return 0;
}





int main() {
    int success = 0;
    
    success = testVectorDotProduct();
    if (success != 0) return success;
    
    success = testVectorCrossProduct();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}
