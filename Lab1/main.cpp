#include <iostream>
#include "funcs.h"

using std::cout;
using std::endl;

int main() {
    //change the values of variables
    int a = 2;
    int b = 3;
    change_variables_p(&a, &b);
    cout << a << " " << b << endl;

    change_variables_l(a, b);
    cout << a << " " << b << endl;


    //round the float
    float fl = 324.5423;
    round_float_p(&fl);
    cout << fl << endl;

    round_float_l(fl);
    cout << fl << endl;


    //multiply a complex number by float
    complex_float compla{2, 3};
    float complb = 4.5;
    multiply_p(&compla, &complb);
    cout << compla.re << " + " << compla.im << endl;

    multiply_l(compla, complb);
    cout << compla.re << " + " << compla.im << endl;


    //transpose a 3x3 matrix
    int arr[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};
    transp_p(arr);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    transp_l(arr);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
