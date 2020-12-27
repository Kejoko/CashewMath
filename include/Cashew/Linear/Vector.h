// Keegan Kochis
// 2020 December 27th

#ifndef CASHEW_VECTOR_H_INCLUDE
#define CASHEW_VECTOR_H_INCLUDE

#include <vector>

namespace Cashew {

template<class T>
class Vector {
  public:
    Vector(int size);
    Vector(int size, T value);
    
    void fill(T value);
    
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
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
    int width, precision, pad;
    
    // Need [] overloaded to access elements
    
    return os;
}

}

#endif // CASHEW_VECTOR_H_INCLUDE
