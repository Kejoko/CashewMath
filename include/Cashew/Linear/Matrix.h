// Keegan Kochis
// 2020 December 26th

#ifndef CASHEW_MATRIX_H_INCLUDE
#define CASHEW_MATRIX_H_INCLUDE

#include <stdlib.h>

#include <iomanip>
#include <ostream>
#include <vector>

#include "Cashew/Linear/Vector.h"

namespace Cashew {

    template<class T>
    class Matrix {
      public:

        Matrix(int rows, int cols);
        Matrix(int rows, int cols, T value);

        int rows() { return mRows; }
        int cols() { return mCols; }
        int size() { return mRows * mCols; }
        
        void fill(T value);
        void clear();

        Cashew::Vector<T>& operator[](int i);
        
      private:
        
        int mRows;
        int mCols;
        std::vector<Cashew::Vector<T>> mData;
        
    };

    //
    // Member functions
    //

    template<class T>
    Matrix<T>::Matrix(int rows, int cols) {
        mRows = rows;
        mCols = cols;
        
        for (int i = 0; i < mRows; i++) {
            mData.emplace_back(mCols);
        }
        mData.shrink_to_fit();
    }

    template<class T>
    Matrix<T>::Matrix(int rows, int cols, T value) {
        mRows = rows;
        mCols = cols;
        
        
    }

    template<class T>
    void Matrix<T>::fill(T value) {
        for (Cashew::Vector<T>& vec : mData) {
            vec.fill(value);
        }
    }

    //
    // Operator overloads
    //

    template<class T>
    Cashew::Vector<T>& Matrix<T>::operator[](int r) {
        if (r < 0 || r >= mRows) {
            throw std::out_of_range("Row " + std::to_string(r) + " is out of bounds for Cashew::Matrix with " + std::to_string(mRows) + " rows.");
        }
        
        return mData[r];
    }

    template<class T>
    std::ostream& operator<<(std::ostream& os, Matrix<T>& mat) {
        return os;
    }

    std::ostream& operator<<(std::ostream& os, Matrix<double>& mat) {
        // Determine widths of each column by extracting the number
        // of digits in each value
        std::vector<int> widths(mat.cols());
        for (int c = 0; c < mat.cols(); c++) {
            int maxDigits = 0;
            for (int r = 0; r < mat.rows(); r++) {
                double dVal = mat[r][c] + 0.5 - (mat[r][c] < 0);
                int iVal = std::abs((int)dVal);
                int digits = 0;
                
                while (iVal != 0) {
                    iVal /= 10;
                    digits++;
                }
                
                if (mat[r][c] < 0) {
                    digits++;
                }
                
                if (digits > maxDigits) {
                    maxDigits = digits;
                }
            }
            widths[c] = maxDigits;
        }
        
        // Print each row of the matrix
        int precision = 4;
        for (int r = 0; r < mat.rows(); r++) {
            os << '|';
            for (int c = 0; c < mat.cols(); c++) {
                os << std::setw(widths[c] + precision + 1)
                   << std::right
                   << std::setfill(' ')
                   << std::setprecision(precision)
                   << std::fixed
                   << mat[r][c];
                
                if (c < mat.cols() - 1) {
                    os << "  ";
                }
            }
            os << '|';
            
            if (r < mat.rows()-1) {
                os << '\n';
            }
        }
        
        return os;
    }

}


#endif // CASHEW_MATRIX_H_INCLUDE
