#include "matrix.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

inline Matrix &createMatrix(int number) {
    static const int dimension = 3;
    cout << "Enter matrix " << number << ":" << endl;

    //make a 3x3 array in dynamic memory
    float **testarr = new float *[dimension];
    for (int i = 0; i < dimension; i++) {
        testarr[i] = new float[dimension] {};
        for (int j = 0; j < dimension; j++) {
            cin >> testarr[i][j];
        }
    }

    Matrix *testmatrix = new Matrix(testarr);

    //free the memory
    for (int i = 0; i < dimension; i++) {
        delete [] testarr[i];
    }
    delete [] testarr;

    return *testmatrix;
}

inline void testingMatrix() {
    cout << "Testing matrix. First, enter 2 matrices and a real number: " << endl;

    Matrix testmatrix1 = createMatrix(1);
    Matrix testmatrix2 = createMatrix(2);

    cout << "Now, enter a float number" << endl;

    float num;
    cin >> num;

    cout << "Results:" << endl << endl;

    Matrix *temp = new Matrix();

    cout << "Matrix 1 * Matrix 2: " << endl;
    *temp = testmatrix1 * testmatrix2;
    temp->printMatrix();

    cout << "Matrix 1 * number: " << endl;
    *temp = testmatrix1 * num;
    temp->printMatrix();

    cout << "Matrix 1 + Matrix 2: " << endl;
    *temp = testmatrix1 + testmatrix2;
    temp->printMatrix();

    cout << "Matrix 1 - Matrix 2: " << endl;
    *temp = testmatrix1 - testmatrix2;
    temp->printMatrix();

    if (testmatrix1 == testmatrix2) {
        cout << "Matrix 1 is equal to Matrix 2" << endl;
    } else if (testmatrix1 != testmatrix2) {
        cout << "Matrix 1 is not equal to Matrix 2" << endl;
    }

    if (testmatrix1 > testmatrix2) {
        cout << "Matrix 1 is more than Matrix 2" << endl;
    } else if (testmatrix1 < testmatrix2) {
        cout << "Matrix 1 is less than Matrix 2" << endl;
    } else {
        cout << "Can't compare Matrix 1 and Matrix 2" << endl;
    }

    cout << endl;
    delete temp;
}
