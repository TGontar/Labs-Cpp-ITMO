#ifndef LAB3_MATRIX_C
#define LAB3_MATRIX_C

#include "matrix.h"

#include <iostream>

using std::cout;
using std::endl;

//default constructor
Matrix::Matrix() {
    matrix = new float *[dim];
    for (int i = 0; i < dim; i++) {
        matrix[i] = new float[dim]{};
    }

    determinant = 0;
}

//constructor with given array
Matrix::Matrix(float **arr) {
    matrix = new float *[dim];
    for (int i = 0; i < dim; i++) {
        matrix[i] = new float[dim];
        for (int j = 0; j < dim; j++) {
            matrix[i][j] = arr[i][j];
        }
    }

    determinant = countDeterminant(*this);
}

//constructor of copying
Matrix::Matrix(Matrix &m) {
    matrix = new float *[dim];
    for (int i = 0; i < dim; i++) {
        matrix[i] = new float[dim];
        for (int j = 0; j < dim; j++) {
            matrix[i][j] = m.matrix[i][j];
        }
    }

    determinant = m.determinant;
}

//destructor
Matrix::~Matrix() {
    for (int i = 0; i < dim; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

//overloading assignment operator with copying
Matrix &Matrix::operator=(Matrix const &m) {
    if (&m == this) {
        return *this;
    }

    for (int i = 0; i < dim; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = new float *[dim];
    for (int i = 0; i < dim; i++) {
        matrix[i] = new float[dim];
        for (int j = 0; j < dim; j++) {
            matrix[i][j] = m.matrix[i][j];
        }
    }

    determinant = m.determinant;

    return *this;
}

//overloading multiply operator for multiplying 2 matrices
Matrix &Matrix::operator*(Matrix &m) {
    Matrix *multiply = new Matrix();

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            float cur = 0;
            for (int k = 0; k < dim; k++) {
                cur += matrix[i][k] * m.matrix[k][j];
            }
            multiply->matrix[i][j] = cur;
        }
    }

    multiply->determinant = countDeterminant(*multiply);

    return *multiply;
}

//overloading multiply operator for multiplying a matrix by a float number
Matrix &Matrix::operator*(float n) {
    Matrix *multiplyFloat = new Matrix();

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            multiplyFloat->matrix[i][j] = matrix[i][j] * n;
        }
    }

    multiplyFloat->determinant = n * determinant;

    return *multiplyFloat;
}

//overloading addition operator for 2 matrices
Matrix &Matrix::operator+(Matrix &m) {
    Matrix *addition = new Matrix();

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            addition->matrix[i][j] = matrix[i][j] + m.matrix[i][j];
        }
    }

    addition->determinant = countDeterminant(*addition);

    return *addition;
}

//overloading subtraction operator for 2 matrices
Matrix &Matrix::operator-(Matrix &m) {
    Matrix *subtraction = new Matrix();

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            subtraction->matrix[i][j] = matrix[i][j] - m.matrix[i][j];
        }
    }

    subtraction->determinant = countDeterminant(*subtraction);

    return *subtraction;
}

//overloading comparison operator - equality
bool Matrix::operator==(Matrix &m) {
    if (determinant != m.determinant) {
        return false;
    }

    bool flag = true;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (matrix[i][j] != m.matrix[i][j]) {
                flag = false;
                break;
            }
        }
    }

    return flag;
}

//overloading comparison operator - inequality
bool Matrix::operator!=(Matrix &m) {
    if (determinant != m.determinant) {
        return true;
    }

    bool flag = false;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (matrix[i][j] != m.matrix[i][j]) {
                flag = true;
                break;
            }
        }
    }

    return flag;
}

//overloading comparison operator - matrix 1 is more than matrix 2
bool Matrix::operator>(Matrix &m) {
    bool flag = true;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (matrix[i][j] <= m.matrix[i][j]) {
                flag = false;
                break;
            }
        }
    }

    return flag;
}

//overloading comparison operator - matrix 1 is less than matrix 2
bool Matrix::operator<(Matrix &m) {
    bool flag = true;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (matrix[i][j] >= m.matrix[i][j]) {
                flag = false;
                break;
            }
        }
    }

    return flag;
}

//static function to calculate determinant for 3x3 matrix
float Matrix::countDeterminant(Matrix &m) {
    float plus = m.matrix[0][0] * m.matrix[1][1] * m.matrix[2][2] + m.matrix[0][1] * m.matrix[1][2] * m.matrix[2][0] +
                 m.matrix[0][2] * m.matrix[1][0] * m.matrix[1][2];
    float minus = m.matrix[0][2] * m.matrix[1][1] * m.matrix[2][0] + m.matrix[0][1] * m.matrix[1][0] * m.matrix[2][2] +
                  m.matrix[0][0] * m.matrix[1][2] * m.matrix[2][1];
    float ans = plus - minus;

    return ans;
}

//print the matrix
void Matrix::printMatrix() {
    cout << "Matrix:" << endl;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

#endif //LAB3_MATRIX_C
