

#ifndef MATRIX_H_INCLUDE
#define MATRIX_H_INCLUDE

namespace Cashew {

    template <class T>
    class Matrix {
      public:
        
        Matrix(int rows, int cols);
        
        void clear();
        
        int rows() { return mRows; }
        int cols() { return mCols; }
        
        T minval();
        T maxval();
        
      private:
        
        int mRows;
        int mCols;
        
        T** mData;
        
    };

    template <class T>
    Matrix<T>::Matrix(int rows, int cols) {
        
    }

}


#endif //MATRIX_H_INCLUDE
