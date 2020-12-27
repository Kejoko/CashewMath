// Keegan Kochis
// 2020 December 26th

#ifndef CASHEW_MATRIX_H_INCLUDE
#define CASHEW_MATRIX_H_INCLUDE

#include <ostream>

#include "Cashew/Linear/Vector.h"

namespace Cashew {

    template <class T>
    class Matrix {
      public:
        
        Matrix(int rows, int cols);
        ~Matrix() = default;
        
        void clear();
        
        int rows() { return mRows; }
        int cols() { return mCols; }
        
        T minval();
        T maxval();
        
      private:
        
        int mRows;
        int mCols;
        //std::vector<std::vector<T>> mData;
        
    };

    //
    // Member functions
    //

    template <class T>
    Matrix<T>::Matrix(int rows, int cols) {
        mRows = rows;
        mCols = cols;
        
    }

    //
    // Operator overloads
    //

//    template <class T>
//    std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat) {
//
//    }
}


#endif // CASHEW_MATRIX_H_INCLUDE
