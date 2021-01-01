// Keegan Kochis
// 2020 December 26th

#ifndef CASHEW_MATRIX_H_INCLUDE
#define CASHEW_MATRIX_H_INCLUDE

#include <stdlib.h>

#include <iomanip>
#include <ostream>
#include <string>
#include <type_traits>
#include <vector>

#include "Cashew/Linear/Vector.h"

namespace Cashew {

    template<class T>
    class Matrix {
      public:
        Matrix(int rows, int cols);
        Matrix(int rows, int cols, T value);

        int rows() const { return mRows; }
        int cols() const { return mCols; }
        int size() const { return mRows * mCols; }
        
        void fill(T value);
        void clear();

        Vector<T> operator[](int i) const;
        Vector<T>& operator[](int i);
        
        Matrix<T>& operator=(const Matrix<T>& rhs);
        Matrix<T>& operator+=(const Matrix<T>& rhs);
        Matrix<T>& operator-=(const Matrix<T>& rhs);
        Matrix<T>& operator*=(double scalar);
        Matrix<T>& operator/=(double scalar);
        
        operator Matrix<double>() const;
        
      private:
        int mRows;
        int mCols;
        std::vector<Vector<T>> mData;
        
        void validateRow(int r) const;
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
        
        fill(value);
    }

    template<class T>
    void Matrix<T>::fill(T value) {
        for (Vector<T>& vec : mData) {
            vec.fill(value);
        }
    }

    template<class T>
    void Matrix<T>::validateRow(int r) const {
        if (r < 0 || r >= mRows) {
            throw std::out_of_range("Row " + std::to_string(r) +
                                    " is out of bounds for Cashew::Matrix with " +
                                    std::to_string(mRows) + " rows.");
        }
    }

    //
    // Operator overloads
    //

    template<class T>
    Vector<T> Matrix<T>::operator[](int r) const {
        validateRow(r);
        
        return mData[r];
    }

    template<class T>
    Vector<T>& Matrix<T>::operator[](int r) {
        validateRow(r);
        
        return mData[r];
    }

    template<class T>
    void validateDimensions(const Matrix<T>& matA, const Matrix<T>& matB, const std::string& operation) {
        if (matA.rows() != matB.rows() || matA.cols() != matB.cols()) {
            throw std::domain_error(operation +
                                    " invalid for Cashew::Matrix of size " +
                                    std::to_string(matA.rows()) + ',' +
                                    std::to_string(matA.cols()) +
                                    " and Cashew::Matrix of size " +
                                    std::to_string(matB.rows()) + ',' +
                                    std::to_string(matB.cols()) + '.');
        }
    }

    template<class T>
    Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
        if (this == &rhs) {
            return *this;
        }
        
        validateDimensions(*this, rhs, "Assignmnt");
        
        for (int r = 0; r < mRows; r++) {
            for (int c = 0; c < mCols; c++) {
                mData[r][c] = rhs[r][c];
            }
        }
        
        return *this;
    }

    template<>
    Matrix<int>::operator Matrix<double>() const {
        Matrix<double> dMat(mRows, mCols);
        for (int r = 0; r < mRows; r++) {
            for (int c = 0; c < mCols; c++) {
                dMat[r][c] = (double)mData[r][c];
            }
        }
        return dMat;
    }

    template<class T>
    bool operator==(const Matrix<T>& lhs, const Matrix<T>& rhs) {
        validateDimensions(lhs, rhs, "Comparison");
        
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                if (lhs[r][c] != rhs[r][c]) {
                    return false;
                }
            }
        }
        
        return true;
    }

    template<class T>
    bool operator!=(const Matrix<T>& lhs, const Matrix<T>& rhs) {
        return !(lhs == rhs);
    }

    template<class T>
    Matrix<T> operator+(const Matrix<T>& lhs, const Matrix<T>& rhs) {
        validateDimensions(lhs, rhs, "Addition");
        
        Matrix<T> mat(lhs.rows(), lhs.cols());
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                mat[r][c] = lhs[r][c] + rhs[r][c];
            }
        }
        
        return mat;
    }

    template<class T>
    Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs) {
        *this = *this + rhs;
        return *this;
    }

    template<class T>
    Matrix<T> operator-(const Matrix<T>& lhs, const Matrix<T>& rhs) {
        validateDimensions(lhs, rhs, "Subtraction");
        
        Matrix<T> mat(lhs.rows(), lhs.cols());
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                mat[r][c] = lhs[r][c] - rhs[r][c];
            }
        }
        
        return mat;
    }

    template<class T>
    Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs) {
        *this = *this - rhs;
        return *this;
    }

    template<class T>
    Matrix<T> operator*(const Matrix<T>& lhs, double scalar) {
        Matrix<T> mat(lhs.rows(), lhs.cols());
        
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                mat[r][c] = lhs[r][c] * scalar;
            }
        }
        
        return mat;
    }

    template<class T>
    Matrix<T> operator*(double scalar, const Matrix<T>& rhs) {
        return rhs * scalar;
    }

    template<class T>
    Matrix<T>& Matrix<T>::operator*=(double scalar) {
        *this = *this * scalar;
        return *this;
    }

    template<class T>
    Matrix<T> operator/(const Matrix<T>& lhs, double scalar) {
        Matrix<T> mat(lhs.rows(), lhs.cols());
        
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                mat[r][c] = lhs[r][c] / scalar;
            }
        }
        
        return mat;
    }

    template<class T>
    Matrix<T> operator/(double scalar, const Matrix<T>& rhs) {
        return rhs / scalar;
    }

    template<class T>
    Matrix<T>& Matrix<T>::operator/=(double scalar) {
        *this = *this / scalar;
        return *this;
    }

    template<class T>
    std::ostream& operator<<(std::ostream& os, const Matrix<T>& mat) {
        for (int r = 0; r < mat.rows(); r++) {
            os << mat[r] << '\n';
        }
        return os;
    }

    std::vector<int> getColWidths(const Matrix<double>& mat) {
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
        return widths;
    }

    template<class T>
    void printNumericMatrix(std::ostream& os, const Matrix<T>& mat, const std::vector<int>& widths, int precision) {
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
    }

    std::ostream& operator<<(std::ostream& os, const Matrix<double>& mat) {
        std::vector<int> widths = getColWidths(mat);
        
        int decimalPlaces = 4;
        printNumericMatrix(os, mat, widths, decimalPlaces);
        
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const Matrix<int>& mat) {
        std::vector<int> widths = getColWidths(mat);

        printNumericMatrix(os, mat, widths, -1);

        return os;
    }
}


#endif // CASHEW_MATRIX_H_INCLUDE
