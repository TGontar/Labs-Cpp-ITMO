#ifndef LAB3_MATRIX_H
#define LAB3_MATRIX_H

class Matrix {
private:
    static const int dim = 3;
    float **matrix;
    float determinant;

    static float countDeterminant(Matrix &);

public:
    Matrix();

    Matrix(float **);

    Matrix(Matrix &);

    ~Matrix();

    Matrix &operator=(Matrix const &);

    Matrix &operator*(Matrix &);

    Matrix &operator*(float);

    Matrix &operator+(Matrix &);

    Matrix &operator-(Matrix &);

    bool operator==(Matrix &);

    bool operator!=(Matrix &);

    bool operator>(Matrix &);

    bool operator<(Matrix &);

    void printMatrix();
};


#endif //LAB3_MATRIX_H
