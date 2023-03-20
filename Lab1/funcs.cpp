#include "funcs.h"
#include "cmath"
void change_variables_p(int *pa, int *pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void change_variables_l(int &la, int &lb) {
    int temp = la;
    la = lb;
    lb = temp;
}

void round_float_p(float *pa) {
    float temp = std::floor(*pa);
    if (*pa - temp >= 0.5) {
        *pa = temp + 1;
    } else {
        *pa = temp;
    }
}

void round_float_l(float &la) {
    float temp = std::floor(la);
    if (la - temp >= 0.5) {
        la = temp + 1;
    } else {
        la = temp;
    }
}

void multiply_p(complex_float *pa, float *pb) {
    pa->re *= (*pb);
    pa->im *= (*pb);
}

void multiply_l(complex_float &la, float &lb) {
    la.re *= lb;
    la.im *= lb;
}

void transp_p(int (*pa)[3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            int temp = pa[i][j];
            pa[i][j] = pa[j][i];
            pa[j][i] = temp;
        }
    }
}

void transp_l(int (&la)[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            int temp = la[i][j];
            la[i][j] = la[j][i];
            la[j][i] = temp;
        }
    }

}

