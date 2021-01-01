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

    template<class T, size_t R, size_t C>
    class Matrix {
      public:
        Matrix();
        Matrix(T value);

        int rows() const { return mRows; }
        int cols() const { return mCols; }
        int size() const { return mRows * mCols; }
        
        void fill(T value);
        void clear();

        Vector<T, C> operator[](int i) const;
        Vector<T, C>& operator[](int i);
        
        Matrix<T, R, C>& operator=(const Matrix<T, R, C>& rhs);
        Matrix<T, R, C>& operator+=(const Matrix<T, R, C>& rhs);
        Matrix<T, R, C>& operator-=(const Matrix<T, R, C>& rhs);
        Matrix<T, R, C>& operator*=(double scalar);
        Matrix<T, R, C>& operator/=(double scalar);
        
//        operator Matrix<double>() const;
        
      private:
        int mRows;
        int mCols;
        std::vector<Vector<T, C>> mData;
        
        void validateRow(int r) const;
    };

    //
    // Member functions
    //

    template<class T, size_t R, size_t C>
    Matrix<T, R, C>::Matrix() {
        if (R <= 0 || C <= 0) {
            throw std::domain_error("Cannot create Cashew::Matrix with less than 1 rows or less than 1 columns");
        }
        
        mRows = R;
        mCols = C;
        
        for (int i = 0; i < mRows; i++) {
            mData.emplace_back();
        }
        mData.shrink_to_fit();
    }

    template<class T, size_t R, size_t C>
    Matrix<T, R, C>::Matrix(T value) {
        if (R <= 0 || C <= 0) {
            throw std::domain_error("Cannot create Cashew::Matrix with less than 1 rows or less than 1 columns");
        }
        
        mRows = R;
        mCols = C;
        
        for (int i = 0; i < mRows; i++) {
            mData.emplace_back();
        }
        mData.shrink_to_fit();
        
        fill(value);
    }

    template<class T, size_t R, size_t C>
    void Matrix<T, R, C>::fill(T value) {
        for (Vector<T, C>& vec : mData) {
            vec.fill(value);
        }
    }

    template<class T, size_t R, size_t C>
    void Matrix<T, R, C>::validateRow(int r) const {
        if (r < 0 || r >= mRows) {
            throw std::out_of_range("Row " + std::to_string(r) +
                                    " is out of bounds for Cashew::Matrix with " +
                                    std::to_string(mRows) + " rows.");
        }
    }

    //
    // Operator overloads
    //

    template<class T, size_t R, size_t C>
    Vector<T, C> Matrix<T, R, C>::operator[](int r) const {
        validateRow(r);
        
        return mData[r];
    }

    template<class T, size_t R, size_t C>
    Vector<T, C>& Matrix<T, R, C>::operator[](int r) {
        validateRow(r);
        
        return mData[r];
    }

    template<class T, size_t R, size_t C>
    void validateDimensions(const Matrix<T, R, C>& matA, const Matrix<T, R, C>& matB, const std::string& operation) {
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

    template<class T, size_t R, size_t C>
    Matrix<T, R, C>& Matrix<T, R, C>::operator=(const Matrix<T, R, C>& rhs) {
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

//    template<>
//    Matrix<int>::operator Matrix<double>() const {
//        Matrix<double> dMat(mRows, mCols);
//        for (int r = 0; r < mRows; r++) {
//            for (int c = 0; c < mCols; c++) {
//                dMat[r][c] = (double)mData[r][c];
//            }
//        }
//        return dMat;
//    }

    template<class T, size_t R, size_t C>
    bool operator==(const Matrix<T, R, C>& lhs, const Matrix<T, R, C>& rhs) {
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

    template<class T, size_t R, size_t C>
    bool operator!=(const Matrix<T, R, C>& lhs, const Matrix<T, R, C>& rhs) {
        return !(lhs == rhs);
    }

    template<class T, size_t R, size_t C>
    Matrix<T, R, C> operator+(const Matrix<T, R, C>& lhs, const Matrix<T, R, C>& rhs) {
        validateDimensions(lhs, rhs, "Addition");
        
        Matrix<T, R, C> mat;
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                mat[r][c] = lhs[r][c] + rhs[r][c];
            }
        }
        
        return mat;
    }

    template<class T, size_t R, size_t C>
    Matrix<T, R, C>& Matrix<T, R, C>::operator+=(const Matrix<T, R, C>& rhs) {
        *this = *this + rhs;
        return *this;
    }

    template<class T, size_t R, size_t C>
    Matrix<T, R, C> operator-(const Matrix<T, R, C>& lhs, const Matrix<T, R, C>& rhs) {
        validateDimensions(lhs, rhs, "Subtraction");
        
        Matrix<T, R, C> mat;
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                mat[r][c] = lhs[r][c] - rhs[r][c];
            }
        }
        
        return mat;
    }

    template<class T, size_t R, size_t C>
    Matrix<T, R, C>& Matrix<T, R, C>::operator-=(const Matrix<T, R, C>& rhs) {
        *this = *this - rhs;
        return *this;
    }

    template<class T, size_t R, size_t C>
    Matrix<T, R, C> operator*(const Matrix<T, R, C>& lhs, double scalar) {
        Matrix<T, R, C> mat;
        
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                mat[r][c] = lhs[r][c] * scalar;
            }
        }
        
        return mat;
    }

    template<class T, size_t R, size_t C>
    Matrix<T, R, C> operator*(double scalar, const Matrix<T, R, C>& rhs) {
        return rhs * scalar;
    }

    template<class T, size_t R, size_t C>
    Matrix<T, R, C>& Matrix<T, R, C>::operator*=(double scalar) {
        *this = *this * scalar;
        return *this;
    }

    template<class T, size_t R, size_t C>
    Matrix<T, R, C> operator/(const Matrix<T, R, C>& lhs, double scalar) {
        Matrix<T, R, C> mat;
        
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                mat[r][c] = lhs[r][c] / scalar;
            }
        }
        
        return mat;
    }

    template<class T, size_t R, size_t C>
    Matrix<T, R, C> operator/(double scalar, const Matrix<T, R, C>& rhs) {
        return rhs / scalar;
    }

    template<class T, size_t R, size_t C>
    Matrix<T, R, C>& Matrix<T, R, C>::operator/=(double scalar) {
        *this = *this / scalar;
        return *this;
    }

    template<class T, size_t R, size_t C>
    std::ostream& operator<<(std::ostream& os, const Matrix<T, R, C>& mat) {
        for (int r = 0; r < mat.rows(); r++) {
            os << mat[r] << '\n';
        }
        return os;
    }

    template<class T, size_t R, size_t C>
    std::vector<int> getColWidths(const Matrix<double, R, C>& mat) {
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

    template<class T, size_t R, size_t C>
    void printNumericMatrix(std::ostream& os, const Matrix<T, R, C>& mat, const std::vector<int>& widths, int precision) {
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

    template<class T, size_t R, size_t C>
    std::ostream& operator<<(std::ostream& os, const Matrix<double, R, C>& mat) {
        std::vector<int> widths = getColWidths(mat);
        
        int decimalPlaces = 4;
        printNumericMatrix(os, mat, widths, decimalPlaces);
        
        return os;
    }

    template<class T, size_t R, size_t C>
    std::ostream& operator<<(std::ostream& os, const Matrix<int, R, C>& mat) {
        std::vector<int> widths = getColWidths(mat);

        printNumericMatrix(os, mat, widths, -1);

        return os;
    }
}


#endif // CASHEW_MATRIX_H_INCLUDE
