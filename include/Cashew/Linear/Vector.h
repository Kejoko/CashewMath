// Keegan Kochis
// 2020 December 27th

#ifndef CASHEW_VECTOR_H_INCLUDE
#define CASHEW_VECTOR_H_INCLUDE

#include <string>
#include <vector>

namespace Cashew {

    template<class T>
    class Vector {
      public:
        Vector(int size);
        Vector(int size, T value);
        
        int size() const { return mSize; }
    
        void fill(T value);
        void clear();

        T operator[](int i) const;
        T& operator[](int i);
        
        Vector<T>& operator=(const Vector<T>& rhs);
        Vector<T>& operator+=(const Vector<T>& rhs);
        Vector<T>& operator-=(const Vector<T>& rhs);
        Vector<T>& operator*=(double scalar);
        Vector<T>& operator/=(double scalar);
        
        operator Vector<double>() const;
    
      private:
        int mSize;
        std::vector<T> mData;
        
        void validateIndex(int) const;
    };

    //
    // Member functions
    //

    template<class T>
    Vector<T>::Vector(int size) {
        if (size == 0) {
            throw std::domain_error("Cannot create a Cashew::Vector of size 0.");
        }
        
        mSize = size;
        mData.resize(mSize);
    }

    template<class T>
    Vector<T>::Vector(int size, T value) {
        if (size == 0) {
            throw std::domain_error("Cannot create a Cashew::Vector of size 0.");
        }
        
        mSize = size;
        mData.resize(mSize);
    
        fill(value);
    }

    template<class T>
    void Vector<T>::fill(T value) {
        for (int i = 0; i < mSize; i++) {
            mData[i] = value;
        }
    }

    template<class T>
    void Vector<T>::validateIndex(int i) const {
        if (i < 0 || i >= mSize) {
            throw std::out_of_range("Index " + std::to_string(i) +
                                    " is out of bounds for Cashew::Vector of size " +
                                    std::to_string(mSize) + '.');
        }
    }

    //
    // Operator overloads
    //

    template<class T>
    T Vector<T>::operator[](int i) const {
        validateIndex(i);
        
        return mData[i];
    }

    template<class T>
    T& Vector<T>::operator[](int i) {
        validateIndex(i);
        
        return mData[i];
    }

    template<class T>
    Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) {
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

    template<>
    Vector<int>::operator Vector<double>() const {
        Vector<double> dVec(mSize);
        for (int i = 0; i < mSize; i++) {
            dVec[i] = (double)mData[i];
        }
        return dVec;
    }

    template<class T>
    void validateSizes(const Vector<T>& vecA, const Vector<T>& vecB) {
        if (vecA.size() != vecB.size()) {
            throw std::domain_error("Comparison invalid for Cashew::Vector of size "
                                    + std::to_string(vecA.size())
                                    + " and Cashew::Vector of size "
                                    + std::to_string(vecB.size()) + '.');
        }
    }

    template<class T>
    bool operator==(const Vector<T>& lhs, const Vector<T>& rhs) {
        validateSizes(lhs, rhs);
        
        for (int i = 0; i < lhs.size(); i++) {
            if (lhs[i] != rhs[i]) {
                return false;
            }
        }
        
        return true;
    }

    template<class T>
    bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs) {
        return !(lhs == rhs);
    }

    template<class T>
    Vector<T> operator+(const Vector<T>& lhs, const Vector<T>& rhs) {
        validateSizes(lhs, rhs);
        
        Vector<T> vec(lhs.size());
        for (int i = 0; i < lhs.size (); i++) {
            vec[i] = lhs[i] + rhs[i];
        }
        
        return vec;
    }

    template<class T>
    Vector<T>& Vector<T>::operator+=(const Vector<T>& rhs) {
        *this = *this + rhs;
        return *this;
    }

    template<class T>
    Vector<T> operator-(const Vector<T>& lhs, const Vector<T>& rhs) {
        validateSizes(lhs, rhs);
        
        Vector<T> vec(lhs.size());
        for (int i = 0; i < lhs.size (); i++) {
            vec[i] = lhs[i] - rhs[i];
        }
        
        return vec;
    }

    template<class T>
    Vector<T>& Vector<T>::operator-=(const Vector<T>& rhs) {
        *this = *this - rhs;
        return *this;
    }

    template<class T>
    Vector<T> operator*(const Vector<T>& lhs, double scalar) {
        Vector<T> vec(lhs.size);
        for (int i = 0; i < lhs.size(); i++) {
            vec[i] = lhs[i] * scalar;
        }
        
        return vec;
    }

    template<class T>
    Vector<T> operator*(double scalar, const Vector<T>& rhs) {
        return rhs * scalar;
    }

    template<class T>
    Vector<T>& Vector<T>::operator*=(double scalar) {
        *this = *this * scalar;
        return *this;
    }

    template<class T>
    Vector<T> operator/(const Vector<T>& lhs, double scalar) {
        Vector<T> vec(lhs.size);
        for (int i = 0; i < lhs.size(); i++) {
            vec[i] = lhs[i] / scalar;
        }
        
        return vec;
    }

    template<class T>
    Vector<T> operator/(double scalar, const Vector<T>& rhs) {
        return rhs / scalar;
    }

    template<class T>
    Vector<T>& Vector<T>::operator/=(double scalar) {
        *this = *this / scalar;
        return *this;
    }

    template<class T>
    std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
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
