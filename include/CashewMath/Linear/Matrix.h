// Keegan Kochis
// 2020 December 26th

#ifndef MATRIX_H_INCLUDE
#define MATRIX_H_INCLUDE

#include <ostream>
#include <vector>

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
        std::vector<std::vector<T>> mData;
        
    };

    //
    // Member functions
    //

    template <class T>
    Matrix<T>::Matrix(int rows, int cols) {
        mRows = rows;
        mCols = cols;
        
        mData.resize(mRows);
        for (int i = 0; i < mRows; i++) {
            mData[i].resize(mCols);
        }
    }

    //
    // Operator overloads
    //

    template <class T>
    std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat) {
        
    }
}


#endif //MATRIX_H_INCLUDE
