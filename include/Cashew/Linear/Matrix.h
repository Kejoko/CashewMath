// Keegan Kochis
// 2020 December 26th

#ifndef CASHEW_MATRIX_H_INCLUDE
#define CASHEW_MATRIX_H_INCLUDE

#include <stdlib.h>

#include <iomanip>
#include <ostream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <type_traits>
#include <vector>

#include "Cashew/Linear/Vector.h"

#define CASHEW_MAT_TEMPLATE template<class T, size_t R, size_t C>
#define CASHEW_MAT_EXT_TEMPLATE_ARGS T, R, C, ArithmeticPolicy<T>, SizePolicy<R>, SizePolicy<C>

namespace Cashew {

    template<class T, size_t R, size_t C,
             typename TypeEnable = void,
             typename RowEnable = void,
             typename ColEnable = void>
    class Matrix;

    CASHEW_MAT_TEMPLATE
    class Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS> {
      public:
        Matrix();
        Matrix(T value);

        int rows() const { return mRows; }
        int cols() const { return mCols; }
        int size() const { return mRows * mCols; }
        
        void fill(T value);
        void clear() { fill(0); };
        
        T determinant() const;
        bool invertible() const;
        Matrix<double, R, C> inverse() const;
        
        template<class U = T>
        FloatingPolicy<U>
        invert() { *this = inverse(); };
        
        Matrix<T, C, R> transpose() const;

        Vector<T, C> operator[](int i) const;
        Vector<T, C>& operator[](int i);
        
        Matrix<T, R, C>& operator=(const Matrix<T, R, C>& rhs);
        Matrix<T, R, C>& operator+=(const Matrix<T, R, C>& rhs);
        Matrix<T, R, C>& operator-=(const Matrix<T, R, C>& rhs);
        Matrix<T, R, C>& operator*=(double scalar);
        Matrix<T, R, C>& operator*=(const Vector<T, C>& rhs);
        Matrix<T, R, C>& operator*=(const Matrix<T, C, C>& rhs);
        Matrix<T, R, C>& operator/=(double scalar);
        
      private:
        size_t mRows;
        size_t mCols;
        Vector<T, C> mData[R];
        
        void validateRow(int r) const;
        
        T determinantHelper(int n) const;
    };

    //
    // Member functions
    //

    CASHEW_MAT_TEMPLATE
    Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::Matrix() {
        if (R <= 0 || C <= 0) {
            throw std::domain_error("Cannot create Cashew::Matrix with less than 1 rows or less than 1 columns");
        }
        
        mRows = R;
        mCols = C;
        
        // Can replace with clear() even when const Matrix being constructed?
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                mData[r][c] = 0;
            }
        }
    }

    CASHEW_MAT_TEMPLATE
    Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::Matrix(T value) {
        if (R <= 0 || C <= 0) {
            throw std::domain_error("Cannot create Cashew::Matrix with less than 1 rows or less than 1 columns");
        }
        
        mRows = R;
        mCols = C;
        
        // Can replace with fill(value) even when const Matrix being constructed?
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                mData[r][c] = value;
            }
        }
    }

    CASHEW_MAT_TEMPLATE
    void Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::fill(T value) {
        for (int r = 0; r < R; r++) {
            mData[r].fill(value);
        }
    }

    CASHEW_MAT_TEMPLATE
    void Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::validateRow(int r) const {
        if (r < 0 || r >= mRows) {
            throw std::out_of_range("Row " + std::to_string(r) +
                                    " is out of bounds for Cashew::Matrix with " +
                                    std::to_string(mRows) + " rows.");
        }
    }

    CASHEW_MAT_TEMPLATE
    T Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::determinant() const {
        return determinantHelper(mRows);
    }

    CASHEW_MAT_TEMPLATE
    T Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::determinantHelper(int n) const {
        if (mRows != mCols) {
            throw std::domain_error("Cannot take determinant of a non square matrix.");
        }
        
        
        
        return 0;
    }

    CASHEW_MAT_TEMPLATE
    bool Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::invertible() const {
        if (determinant() != 0) {
            return true;
        }
        
        return false;
    }

    CASHEW_MAT_TEMPLATE
    Matrix<double, R, C> Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::inverse() const {
        Matrix<double, R, C> mat;
        
        return mat;
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, C, R> Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::transpose() const {
        Matrix<T, C, R> mat;
        
        return mat;
    }

    //
    // Operator overloads
    //

    CASHEW_MAT_TEMPLATE
    Vector<T, C> Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::operator[](int r) const {
        validateRow(r);
        
        return mData[r];
    }

    CASHEW_MAT_TEMPLATE
    Vector<T, C>& Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::operator[](int r) {
        validateRow(r);
        
        return mData[r];
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, R, C>& Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::operator=(const Matrix<T, R, C>& rhs) {
        if (this == &rhs) {
            return *this;
        }
        
        for (int r = 0; r < mRows; r++) {
            for (int c = 0; c < mCols; c++) {
                mData[r][c] = rhs[r][c];
            }
        }
        
        return *this;
    }

    CASHEW_MAT_TEMPLATE
    bool operator==(const Matrix<T, R, C>& lhs, const Matrix<T, R, C>& rhs) {
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                if (lhs[r][c] != rhs[r][c]) {
                    return false;
                }
            }
        }
        
        return true;
    }

    CASHEW_MAT_TEMPLATE
    bool operator!=(const Matrix<T, R, C>& lhs, const Matrix<T, R, C>& rhs) {
        return !(lhs == rhs);
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, R, C> operator+(const Matrix<T, R, C>& lhs, const Matrix<T, R, C>& rhs) {
        Matrix<T, R, C> mat;
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                mat[r][c] = lhs[r][c] + rhs[r][c];
            }
        }
        
        return mat;
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, R, C>& Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::operator+=(const Matrix<T, R, C>& rhs) {
        *this = *this + rhs;
        return *this;
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, R, C> operator-(const Matrix<T, R, C>& lhs, const Matrix<T, R, C>& rhs) {
        Matrix<T, R, C> mat;
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                mat[r][c] = lhs[r][c] - rhs[r][c];
            }
        }
        
        return mat;
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, R, C>& Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::operator-=(const Matrix<T, R, C>& rhs) {
        *this = *this - rhs;
        return *this;
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, R, C> operator*(const Matrix<T, R, C>& lhs, double scalar) {
        Matrix<T, R, C> mat;
        
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                mat[r][c] = lhs[r][c] * scalar;
            }
        }
        
        return mat;
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, R, C> operator*(double scalar, const Matrix<T, R, C>& rhs) {
        return rhs * scalar;
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, R, C>& Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::operator*=(double scalar) {
        *this = *this * scalar;
        return *this;
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, R, C> operator*(const Matrix<T, R, C>& lhs, const Vector<T, C>& vec) {
        Matrix<T, R, C> mat;
        
        
        
        return mat;
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, R, C>& Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::operator*=(const Vector<T, C>& vec) {
        *this = *this * vec;
        return *this;
    }

    template<class T, size_t A, size_t B, size_t C>
    Matrix<T, A, C> operator*(const Matrix<T, A, B>& lhs, const Matrix<T, B, C>& rhs) {
        Matrix<T, A, C> mat;
        
        
        
        return mat;
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, R, C>& Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::operator*=(const Matrix<T, C, C>& rhs) {
        *this = *this * rhs;
        return *this;
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, R, C> operator/(const Matrix<T, R, C>& lhs, double scalar) {
        Matrix<T, R, C> mat;
        
        for (int r = 0; r < lhs.rows(); r++) {
            for (int c = 0; c < lhs.cols(); c++) {
                mat[r][c] = lhs[r][c] / scalar;
            }
        }
        
        return mat;
    }

    CASHEW_MAT_TEMPLATE
    Matrix<T, R, C>& Matrix<CASHEW_MAT_EXT_TEMPLATE_ARGS>::operator/=(double scalar) {
        *this = *this / scalar;
        return *this;
    }

    CASHEW_MAT_TEMPLATE
    std::ostream& operator<<(std::ostream& os, const Matrix<T, R, C>& mat) {
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
        
        T dummy;
        std::string typeName = typeid(dummy).name();
        os << typeName << '\n';
        
        int precision = -1;
        if (typeName == "f" || typeName == "d" || typeName == "e") {
            precision = 4;
        }
        
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

    //
    // Special Types
    //

    typedef Matrix<double, 3, 3> Mat3d;
    typedef Matrix<double, 4, 4> Mat4d;
}


#endif // CASHEW_MATRIX_H_INCLUDE
