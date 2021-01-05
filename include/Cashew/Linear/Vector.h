// Keegan Kochis
// 2020 December 27th

#ifndef CASHEW_VECTOR_H_INCLUDE
#define CASHEW_VECTOR_H_INCLUDE

#include <cmath>

#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

#include "Cashew/Util/Sqrt.h"

#define CASHEW_VEC_TEMPLATE template<class T, size_t S>
#define CASHEW_VEC_EXT_TEMPLATE_ARGS T, S, ArithmeticPolicy<T>, SizePolicy<S>

namespace Cashew {

    template<class T>
    using ArithmeticPolicy = typename std::enable_if<std::is_arithmetic<T>::value>::type;

    template<size_t S>
    using SizePolicy = typename std::enable_if<S >= 1>::type;

    template<class T, size_t S, typename TypeEnable = void, typename SizeEnable = void>
    class Vector;

    CASHEW_VEC_TEMPLATE
    class Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS> {
      public:
        Vector();
        Vector(T value);
        
        int size() const { return mSize; }
    
        void fill(T value);
        void clear() { fill(0); }
        
        double normSquared() const;
        double norm() const;
        double magnitude() const { return norm(); }
        Vector<double, S> normalized() const;
        void normalize();
        
        double dot(const Vector<T, S>& rhs) const;
        double cross(const Vector<T, S>& rhs) const;

        T operator[](int i) const;
        T& operator[](int i);
        
        Vector<T, S>& operator=(const Vector<T, S>& rhs);
        Vector<T, S>& operator+=(const Vector<T, S>& rhs);
        Vector<T, S>& operator-=(const Vector<T, S>& rhs);
        Vector<T, S>& operator*=(double scalar);
        Vector<T, S>& operator/=(double scalar);
    
      private:
        size_t mSize;
        T mData[S];
        
        void validateIndex(int i) const;
    };

    //
    // Member functions
    //

    CASHEW_VEC_TEMPLATE
    Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::Vector() {
        mSize = S;
        
        for (int i = 0; i < mSize; i++) {
            mData[i] = 0;
        }
    }

    CASHEW_VEC_TEMPLATE
    Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::Vector(T value) {
        mSize = S;
    
        for (int i = 0; i < mSize; i++) {
            mData[i] = value;
        }
    }

    CASHEW_VEC_TEMPLATE
    void Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::fill(T value) {
        for (int i = 0; i < mSize; i++) {
            mData[i] = value;
        }
    }

    CASHEW_VEC_TEMPLATE
    void Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::validateIndex(int i) const {
        if (i < 0 || i >= mSize) {
            throw std::out_of_range("Index " + std::to_string(i) +
                                    " is out of bounds for Cashew::Vector of size " +
                                    std::to_string(mSize) + '.');
        }
    }

    CASHEW_VEC_TEMPLATE
    double Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::normSquared() const {
        // Change T to be floating point or unsigned / signed int based on type
        T squaredSum = 0;
        for (int i = 0; i < mSize; i++) {
            squaredSum += (mData[i] * mData[i]);
        }
        
        return squaredSum;
    }

    CASHEW_VEC_TEMPLATE
    double Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::norm() const {
#if defined(CASHEW_REALTIME) || defined(CASHEW_FAST_SQRT)
        return sqrt(normSquared());
//        return fastSart(normSquared());
#else
        return sqrt(normSquared());
#endif // CASHEW_REALTIME
    }

    CASHEW_VEC_TEMPLATE
    Vector<double, S> Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::normalized() const {
        Vector<double, S> vec;
#if defined(CASHEW_REALTIME) || defined(CASHEW_FAST_SQRT)
        double invSqrt = fastInvSqrt(normSquared());
        for (int i = 0; i < mSize; i++) {
            vec[i] = mData[i] * invSqrt;
        }
#else
        double mag = norm();
        
        if (mag == 0) {
            return vec;
        }
        
        for (int i = 0; i < mSize; i++) {
            vec[i] = mData[i] / mag;
        }
#endif // CASHEW_REALTIME
        return vec;
    }

    //
    // Operator overloads
    //

    CASHEW_VEC_TEMPLATE
    T Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::operator[](int i) const {
        validateIndex(i);
        
        return mData[i];
    }

    CASHEW_VEC_TEMPLATE
    T& Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::operator[](int i) {
        validateIndex(i);
        
        return mData[i];
    }

    CASHEW_VEC_TEMPLATE
    Vector<T, S>& Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::operator=(const Vector<T, S>& rhs) {
        if (this == &rhs) {
            return *this;
        }
        
        for (int i = 0; i < mSize; i++) {
            mData[i] = rhs[i];
        }
        
        return *this;
    }

    CASHEW_VEC_TEMPLATE
    bool operator==(const Vector<T, S>& lhs, const Vector<T, S>& rhs) {
        for (int i = 0; i < lhs.size(); i++) {
            if (lhs[i] != rhs[i]) {
                return false;
            }
        }
        
        return true;
    }

    CASHEW_VEC_TEMPLATE
    bool operator!=(const Vector<T, S>& lhs, const Vector<T, S>& rhs) {
        return !(lhs == rhs);
    }

    CASHEW_VEC_TEMPLATE
    Vector<T, S> operator+(const Vector<T, S>& lhs, const Vector<T, S>& rhs) {
        Vector<T, S> vec;
        for (int i = 0; i < lhs.size (); i++) {
            vec[i] = lhs[i] + rhs[i];
        }
        
        return vec;
    }

    CASHEW_VEC_TEMPLATE
    Vector<T, S>& Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::operator+=(const Vector<T, S>& rhs) {
        *this = *this + rhs;
        return *this;
    }

    CASHEW_VEC_TEMPLATE
    Vector<T, S> operator-(const Vector<T, S>& lhs, const Vector<T, S>& rhs) {
        Vector<T, S> vec;
        for (int i = 0; i < lhs.size (); i++) {
            vec[i] = lhs[i] - rhs[i];
        }
        
        return vec;
    }

    CASHEW_VEC_TEMPLATE
    Vector<T, S>& Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::operator-=(const Vector<T, S>& rhs) {
        *this = *this - rhs;
        return *this;
    }

    CASHEW_VEC_TEMPLATE
    Vector<T, S> operator*(const Vector<T, S>& lhs, double scalar) {
        Vector<T, S> vec;
        for (int i = 0; i < lhs.size(); i++) {
            vec[i] = lhs[i] * scalar;
        }
        
        return vec;
    }

    CASHEW_VEC_TEMPLATE
    Vector<T, S> operator*(double scalar, const Vector<T, S>& rhs) {
        return rhs * scalar;
    }

    CASHEW_VEC_TEMPLATE
    Vector<T, S>& Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::operator*=(double scalar) {
        *this = *this * scalar;
        return *this;
    }

    CASHEW_VEC_TEMPLATE
    Vector<T, S> operator/(const Vector<T, S>& lhs, double scalar) {
        Vector<T, S> vec;
        for (int i = 0; i < lhs.size(); i++) {
            vec[i] = lhs[i] / scalar;
        }
        
        return vec;
    }

    CASHEW_VEC_TEMPLATE
    Vector<T, S> operator/(double scalar, const Vector<T, S>& rhs) {
        return rhs / scalar;
    }

    CASHEW_VEC_TEMPLATE
    Vector<T, S>& Vector<CASHEW_VEC_EXT_TEMPLATE_ARGS>::operator/=(double scalar) {
        *this = *this / scalar;
        return *this;
    }

    CASHEW_VEC_TEMPLATE
    std::ostream& operator<<(std::ostream& os, const Vector<T, S>& vec) {
        int width, precision, pad;
    
        os << '|';
        for (int i = 0; i < vec.size(); i++) {
            os << vec[i];
            
            if (i < vec.size()-1) {
                os << "  ";
            }
        }
        os << '|';
    
        return os;
    }
}

#endif // CASHEW_VECTOR_H_INCLUDE
