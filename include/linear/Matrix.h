

#ifndef MATRIX_H_INCLUDE
#define MATRIX_H_INCLUDE

namespace Cashew {

    template <class T>
    class Matrix {
      public:
        
        int rows() { return mRows; }
        int cols() { return mCols; }
        
      private:
        
        int mRows;
        int mCols;
    };

}


#endif //MATRIX_H_INCLUDE
