#include "Matrices.h"

namespace Matrices {
    Matrix::Matrix(int _rows, int _cols) {
        rows = _rows;
        cols = _cols;
        a = vector<vector<double>>(_rows, vector<double>(_cols, 0.0));
    }

    Matrix operator+(const Matrix &a, const Matrix &b) {
        int aRows = a.getRows();
        int bRows = b.getRows();
        int aCols = a.getCols();
        int bCols = b.getCols();
        if (aRows != bRows || aCols != bCols) {
            throw runtime_error("Error: dimensions must agree");
        }

        Matrix c(aRows, aCols);

        for (int i = 0; i < aRows; i++) {
            for (int j = 0; j < aCols; j++) {
                c(i, j) = a(i, j) + b(i, j);
            }
        }

        return c;
    }

    Matrix operator*(const Matrix &a, const Matrix &b) {
        int aRows = a.getRows();
        int bRows = b.getRows();
        int aCols = a.getCols();
        int bCols = b.getCols();
        if (aCols != bRows) {
            throw runtime_error("Error: dimensions must agree");
        }
        Matrix c(aRows, bCols);

        for (int i = 0; i < aRows; i++) {
            for (int k = 0; k < bCols; k++) {
                for (int j = 0; j < aCols; j++) {
                    c(i, k) += a(i, j) * b(j, k);
                }
            }
        }

        return c;
    }

    bool operator==(const Matrix &a, const Matrix &b) {
        int aRows = a.getRows();
        int bRows = b.getRows();
        int aCols = a.getCols();
        int bCols = b.getCols();
        if (aRows != bRows || aCols != bCols)
            return false;
        for (int i = 0; i < a.getRows(); i++) {
            for (int j = 0; j < a.getCols(); j++) {
                if (abs(a(i, j) - b(i, j)) < 0.001)
                    return false;
            }
        }
        return true;
    }

    bool operator!=(const Matrix &a, const Matrix &b) { return !(a == b); }

    ostream &operator<<(ostream &os, const Matrix &a) {
        for (int i = 0; i < a.getRows(); i++) {
            for (int j = 0; j < a.getCols(); j++) {
                os << a(i, j) << " ";
            }
            os << endl;
        }
        return os;
    }

    RotationMatrix::RotationMatrix(double theta) : Matrix(2, 2) {
        (*this)(0, 0) = cos(theta);
        (*this)(0, 1) = -sin(theta);
        (*this)(1, 0) = sin(theta);
        (*this)(1, 1) = cos(theta);
    }

    ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2) {
        (*this)(0, 0) = scale;
        (*this)(1, 1) = scale;
    }

    TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2, nCols) {
        for (int j = 0; j < nCols; j++) {
            (*this)(0, j) = xShift;
            (*this)(1, j) = yShift;
        }
    }
}