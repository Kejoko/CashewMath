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
    
      private:
        int mSize;
        std::vector<T> mData;
    
    };

    //
    // Member functions
    //

    template<class T>
    Vector<T>::Vector(int size) {
        mSize = size;
        mData.resize(mSize);
    }

    template<class T>
    Vector<T>::Vector(int size, T value) {
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

    //
    // Operator overloads
    //

    template<class T>
    T Vector<T>::operator[](int i) const {
        if (i < 0 || i >= mSize) {
            throw std::out_of_range("Index " + std::to_string(i) + " is out of bounds for Cashew::Vector of size " + std::to_string(mSize) + ".");
        }
        
        return mData[i];
    }

    template<class T>
    T& Vector<T>::operator[](int i) {
        if (i < 0 || i >= mSize) {
            throw std::out_of_range("Index " + std::to_string(i) + " is out of bounds for Cashew::Vector of size " + std::to_string(mSize) + ".");
        }
        
        return mData[i];
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
