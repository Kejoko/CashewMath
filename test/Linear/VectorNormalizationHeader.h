#ifndef CASHEW_TEST_VECNORMAL_H_INCLUDE
#define CASHEW_TEST_VECNORMAL_H_INCLUDE

#include <iostream>

#include "Cashew/Linear.h"

int testVectorNorm() {
    std::cout << "----- Vector norm -----\n";
    
    double desiredError = 0.001;
    
    Cashew::Vector<int, 2> vec1;
    vec1[0] = 3;
    vec1[1] = 4;
    double result1 = vec1.norm();
    if (abs(result1 - 5) > desiredError) {
        std::cerr << "ERROR - Vec1 norm " << result1 << " is not 5.\n";
        return 1;
    } else {
        std::cout << "Success : Vec1 norm = " << result1 << '\n';
    }
    
    Cashew::Vector<long long, 80> vec2;
    vec2[67] = -144;
    double result2 = vec2.norm();
    if (abs(result2 - 144) > desiredError) {
        std::cerr << "ERROR - Vec2 norm " << result2 << " is not 144.\n";
        return 2;
    } else {
        std::cout << "Success : Vec2 norm = " << result2 << '\n';
    }
    
    Cashew::Vector<bool, 1> vec3;
    vec3[0] = true;
    double result3 = vec3.norm();
    if (abs(result3 - 1) > desiredError) {
        std::cerr << "ERROR - Vec3 norm " << result3 << " is not 1.\n";
        return 3;
    } else {
        std::cout << "Success : Vec3 norm = " << result3 << '\n';
    }
    
    Cashew::Vector<char, 8> vec4;
    double result4 = vec4.norm();
    if (abs(result4 - 0) > desiredError) {
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
    
    double desiredError = 0.001;
    
    Cashew::Vector<int, 2> vec1;
    vec1[0] = 3;
    vec1[1] = 4;
    Cashew::Vector<double, 2> ans1;
    ans1[0] = 3.0/5.0;
    ans1[1] = 4.0/5.0;
    Cashew::Vector<double, 2> res1 = vec1.normalized();
    
    for (int i = 0; i < res1.size(); i++) {
        if (abs(res1[i] - ans1[i]) > desiredError) {
            std::cerr << "ERROR - Vec1 " << vec1 << " normalized did not give " << ans1 << ".\n";
            return 5;
        }
    }
    
    if (abs(res1.norm() - 1) > desiredError) {
        std::cerr << "ERROR - Normalized vector does not give norm of 1.\n"
                  << res1 << '\n'
                  << res1.norm() << '\n';
        return 6;
    }
    
    Cashew::Vector<long long, 70> vec2;
    Cashew::Vector<double, 70> ans2;
    Cashew::Vector<double, 70> res2 = vec2.normalized();
    
    for (int i = 0; i < res2.size(); i++) {
        if (abs(res2[i] - ans2[i]) > desiredError) {
            std::cerr << "ERROR - A 0 vector normalized did not give a 0 vector.\n";
            return 7;
        }
    }
    
    if (res2.norm() != 0) {
        std::cerr << "ERROR - Normalized 0 vector does not give norm of 0.\n"
                  << res2.norm() << '\n';
        return 8;
    }
    
    Cashew::Vector<bool, 10> vec3;
    vec3[7] = true;
    Cashew::Vector<double, 10> ans3;
    ans3[7] = 1;
    Cashew::Vector<double, 10> res3 = vec3.normalized();
    
    for (int i = 0; i < res3.size(); i++) {
        if (abs(res3[i] - ans3[i]) > desiredError) {
            std::cerr << "ERROR - A unit vector normalized did not give a unit vector.\n";
            return 9;
        }
    }
    
    if (abs(res3.norm() - 1) > desiredError) {
        std::cerr << "ERROR - Normalized vector does not give norm of 1.\n"
                  << res3 << '\n'
                  << res3.norm() << '\n';;
        return 10;
    }
    
    Cashew::Vec3d vec4;
    vec4[0] = 1;
    vec4[1] = 1;
    vec4[2] = 1;
    vec4.normalize();
    Cashew::Vec3d ans4;
    ans4[0] = 1 / sqrt(3);
    ans4[1] = 1 / sqrt(3);
    ans4[2] = 1 / sqrt(3);
    
    for (int i = 0; i < vec4.size(); i++) {
        if (abs(vec4[i] - ans4[i]) > desiredError) {
            std::cerr << "ERROR - Normalized vector did not give unit vector.\n"
                      << "Vec4 : " << vec4 << '\n'
                      << "Ans4 : " << ans4 << '\n';
            return 11;
        }
    }
    
    if (abs(vec4.norm() - 1) > desiredError) {
        std::cerr << "ERROR - Norm of " << vec4 << " is not 1.\n";
        return 12;
    }
    
    std::cout << '\n';
    return 0;
}





int testVectorNormalizationMain() {
    int success = 0;
    
    success = testVectorNorm();
    if (success != 0) return success;
    
    success = testVectorNormalization();
    if (success != 0) return success;
    
    std::cout << "( ͡` ᴗ ͡´)  <(success!)\n";
    return 0;
}


#endif // CASHEW_TEST_VECNORMAL_H_INCLUDE
