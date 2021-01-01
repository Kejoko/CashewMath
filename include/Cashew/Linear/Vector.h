// Keegan Kochis
// 2020 December 27th

#ifndef CASHEW_VECTOR_H_INCLUDE
#define CASHEW_VECTOR_H_INCLUDE

#include <string>
#include <vector>

namespace Cashew {

    template<class T, size_t S>
    class Vector {
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
        int mSize;
        std::vector<T> mData;
        
        void validateIndex(int) const;
    };

    //
    // Member functions
    //

    template<class T, size_t S>
    Vector<T, S>::Vector() {
        if (S <= 0) {
            throw std::domain_error("Cannot create a Cashew::Vector of size less than 1.");
        }
        
        mSize = S;
        mData.resize(S);
    }

    template<class T, size_t S>
    Vector<T, S>::Vector(T value) {
        if (S <= 0) {
            throw std::domain_error("Cannot create a Cashew::Vector of size less than 1.");
        }
        
        mSize = S;
        mData.resize(S);
    
        fill(value);
    }

    template<class T, size_t S>
    void Vector<T, S>::fill(T value) {
        for (int i = 0; i < mSize; i++) {
            mData[i] = value;
        }
    }

    template<class T, size_t S>
    void Vector<T, S>::validateIndex(int i) const {
        if (i < 0 || i >= mSize) {
            throw std::out_of_range("Index " + std::to_string(i) +
                                    " is out of bounds for Cashew::Vector of size " +
                                    std::to_string(mSize) + '.');
        }
    }

    //
    // Operator overloads
    //

    template<class T, size_t S>
    T Vector<T, S>::operator[](int i) const {
        validateIndex(i);
        
        return mData[i];
    }

    template<class T, size_t S>
    T& Vector<T, S>::operator[](int i) {
        validateIndex(i);
        
        return mData[i];
    }

    template<class T, size_t S>
    Vector<T, S>& Vector<T, S>::operator=(const Vector<T, S>& rhs) {
        if (this == &rhs) {
            return *this;
        }
        
        if (mSize != rhs.size()) {
            throw std::domain_error("Cannot assign Cashew::Vector of different sizes to eachother.");
        }
        
        for (int i = 0; i < mSize; i++) {
            mData[i] = rhs[i];
        }
        
        return *this;
    }

//    template<size_t S>
//    Vector<int, S>::operator Vector<double, S>() const {
//        Vector<double> dVec(mSize);
//        for (int i = 0; i < mSize; i++) {
//            dVec[i] = (double)mData[i];
//        }
//        return dVec;
//    }

    template<class T, size_t S>
    void validateSizes(const Vector<T, S>& vecA, const Vector<T, S>& vecB) {
        if (vecA.size() != vecB.size()) {
            throw std::domain_error("Comparison invalid for Cashew::Vector of size "
                                    + std::to_string(vecA.size())
                                    + " and Cashew::Vector of size "
                                    + std::to_string(vecB.size()) + '.');
        }
    }

    template<class T, size_t S>
    bool operator==(const Vector<T, S>& lhs, const Vector<T, S>& rhs) {
        validateSizes(lhs, rhs);
        
        for (int i = 0; i < lhs.size(); i++) {
            if (lhs[i] != rhs[i]) {
                return false;
            }
        }
        
        return true;
    }

    template<class T, size_t S>
    bool operator!=(const Vector<T, S>& lhs, const Vector<T, S>& rhs) {
        return !(lhs == rhs);
    }

    template<class T, size_t S>
    Vector<T, S> operator+(const Vector<T, S>& lhs, const Vector<T, S>& rhs) {
        validateSizes(lhs, rhs);
        
        Vector<T, S> vec;
        for (int i = 0; i < lhs.size (); i++) {
            vec[i] = lhs[i] + rhs[i];
        }
        
        return vec;
    }

    template<class T, size_t S>
    Vector<T, S>& Vector<T, S>::operator+=(const Vector<T, S>& rhs) {
        *this = *this + rhs;
        return *this;
    }

    template<class T, size_t S>
    Vector<T, S> operator-(const Vector<T, S>& lhs, const Vector<T, S>& rhs) {
        validateSizes(lhs, rhs);
        
        Vector<T, S> vec;
        for (int i = 0; i < lhs.size (); i++) {
            vec[i] = lhs[i] - rhs[i];
        }
        
        return vec;
    }

    template<class T, size_t S>
    Vector<T, S>& Vector<T, S>::operator-=(const Vector<T, S>& rhs) {
        *this = *this - rhs;
        return *this;
    }

    template<class T, size_t S>
    Vector<T, S> operator*(const Vector<T, S>& lhs, double scalar) {
        Vector<T, S> vec;
        for (int i = 0; i < lhs.size(); i++) {
            vec[i] = lhs[i] * scalar;
        }
        
        return vec;
    }

    template<class T, size_t S>
    Vector<T, S> operator*(double scalar, const Vector<T, S>& rhs) {
        return rhs * scalar;
    }

    template<class T, size_t S>
    Vector<T, S>& Vector<T, S>::operator*=(double scalar) {
        *this = *this * scalar;
        return *this;
    }

    template<class T, size_t S>
    Vector<T, S> operator/(const Vector<T, S>& lhs, double scalar) {
        Vector<T, S> vec;
        for (int i = 0; i < lhs.size(); i++) {
            vec[i] = lhs[i] / scalar;
        }
        
        return vec;
    }

    template<class T, size_t S>
    Vector<T, S> operator/(double scalar, const Vector<T, S>& rhs) {
        return rhs / scalar;
    }

    template<class T, size_t S>
    Vector<T, S>& Vector<T, S>::operator/=(double scalar) {
        *this = *this / scalar;
        return *this;
    }

    template<class T, size_t S>
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
