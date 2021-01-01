// Keegan Kochis
// 2020 December 27th

#ifndef CASHEW_VECTOR_H_INCLUDE
#define CASHEW_VECTOR_H_INCLUDE

#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

#define CASHEW_VECTOR_TEMPLATE template<class T, size_t S>

namespace Cashew {

    template<class T>
    using ArithmeticPolicy = typename std::enable_if<std::is_arithmetic<T>::value>::type;

    template<class T, size_t S, typename Enable = void>
    class Vector;

    CASHEW_VECTOR_TEMPLATE
    class Vector<T, S, ArithmeticPolicy<T>> {
      public:
        Vector();
        Vector(T value);
        
        int size() const { return mSize; }
    
        void fill(T value);
        void clear();
        
        double norm() const;
        Vector<T, S> normalized() const;
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
        
//        operator Vector<double, S>() const;
    
      private:
        size_t mSize;
        T mData[S];
        
        void validateIndex(int) const;
    };

    //
    // Member functions
    //

    CASHEW_VECTOR_TEMPLATE
    Vector<T, S, ArithmeticPolicy<T>>::Vector() {
        if (S <= 0) {
            throw std::domain_error("Cannot create a Cashew::Vector of size less than 1.");
        }
        
        mSize = S;
    }

    CASHEW_VECTOR_TEMPLATE
    Vector<T, S, ArithmeticPolicy<T>>::Vector(T value) {
        if (S <= 0) {
            throw std::domain_error("Cannot create a Cashew::Vector of size less than 1.");
        }
        
        mSize = S;
    
        fill(value);
    }

    CASHEW_VECTOR_TEMPLATE
    void Vector<T, S, ArithmeticPolicy<T>>::fill(T value) {
        for (int i = 0; i < mSize; i++) {
            mData[i] = value;
        }
    }

    CASHEW_VECTOR_TEMPLATE
    void Vector<T, S, ArithmeticPolicy<T>>::validateIndex(int i) const {
        if (i < 0 || i >= mSize) {
            throw std::out_of_range("Index " + std::to_string(i) +
                                    " is out of bounds for Cashew::Vector of size " +
                                    std::to_string(mSize) + '.');
        }
    }

    //
    // Operator overloads
    //

    CASHEW_VECTOR_TEMPLATE
    T Vector<T, S, ArithmeticPolicy<T>>::operator[](int i) const {
        validateIndex(i);
        
        return mData[i];
    }

    CASHEW_VECTOR_TEMPLATE
    T& Vector<T, S, ArithmeticPolicy<T>>::operator[](int i) {
        validateIndex(i);
        
        return mData[i];
    }

    CASHEW_VECTOR_TEMPLATE
    Vector<T, S>& Vector<T, S, ArithmeticPolicy<T>>::operator=(const Vector<T, S>& rhs) {
        if (this == &rhs) {
            return *this;
        }
        
        for (int i = 0; i < mSize; i++) {
            mData[i] = rhs[i];
        }
        
        return *this;
    }

    CASHEW_VECTOR_TEMPLATE
    bool operator==(const Vector<T, S>& lhs, const Vector<T, S>& rhs) {
        for (int i = 0; i < lhs.size(); i++) {
            if (lhs[i] != rhs[i]) {
                return false;
            }
        }
        
        return true;
    }

    CASHEW_VECTOR_TEMPLATE
    bool operator!=(const Vector<T, S>& lhs, const Vector<T, S>& rhs) {
        return !(lhs == rhs);
    }

    CASHEW_VECTOR_TEMPLATE
    Vector<T, S> operator+(const Vector<T, S>& lhs, const Vector<T, S>& rhs) {
        Vector<T, S> vec;
        for (int i = 0; i < lhs.size (); i++) {
            vec[i] = lhs[i] + rhs[i];
        }
        
        return vec;
    }

    CASHEW_VECTOR_TEMPLATE
    Vector<T, S>& Vector<T, S, ArithmeticPolicy<T>>::operator+=(const Vector<T, S>& rhs) {
        *this = *this + rhs;
        return *this;
    }

    CASHEW_VECTOR_TEMPLATE
    Vector<T, S> operator-(const Vector<T, S>& lhs, const Vector<T, S>& rhs) {
        Vector<T, S> vec;
        for (int i = 0; i < lhs.size (); i++) {
            vec[i] = lhs[i] - rhs[i];
        }
        
        return vec;
    }

    CASHEW_VECTOR_TEMPLATE
    Vector<T, S>& Vector<T, S, ArithmeticPolicy<T>>::operator-=(const Vector<T, S>& rhs) {
        *this = *this - rhs;
        return *this;
    }

    CASHEW_VECTOR_TEMPLATE
    Vector<T, S> operator*(const Vector<T, S>& lhs, double scalar) {
        Vector<T, S> vec;
        for (int i = 0; i < lhs.size(); i++) {
            vec[i] = lhs[i] * scalar;
        }
        
        return vec;
    }

    CASHEW_VECTOR_TEMPLATE
    Vector<T, S> operator*(double scalar, const Vector<T, S>& rhs) {
        return rhs * scalar;
    }

    CASHEW_VECTOR_TEMPLATE
    Vector<T, S>& Vector<T, S, ArithmeticPolicy<T>>::operator*=(double scalar) {
        *this = *this * scalar;
        return *this;
    }

    CASHEW_VECTOR_TEMPLATE
    Vector<T, S> operator/(const Vector<T, S>& lhs, double scalar) {
        Vector<T, S> vec;
        for (int i = 0; i < lhs.size(); i++) {
            vec[i] = lhs[i] / scalar;
        }
        
        return vec;
    }

    CASHEW_VECTOR_TEMPLATE
    Vector<T, S> operator/(double scalar, const Vector<T, S>& rhs) {
        return rhs / scalar;
    }

    CASHEW_VECTOR_TEMPLATE
    Vector<T, S>& Vector<T, S, ArithmeticPolicy<T>>::operator/=(double scalar) {
        *this = *this / scalar;
        return *this;
    }

    CASHEW_VECTOR_TEMPLATE
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
