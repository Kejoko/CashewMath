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
