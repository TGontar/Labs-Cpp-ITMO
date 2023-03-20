#ifndef LAB1_FUNCS_H
#define LAB1_FUNCS_H

struct complex_float {
    float re;
    float im;
};

void change_variables_p(int *, int *);

void change_variables_l(int &, int &);

void round_float_p(float *);

void round_float_l(float &);

void multiply_p(complex_float *, float *);

void multiply_l(complex_float &, float &);

void transp_p(int (*)[3]);

void transp_l(int (&)[3][3]);

#endif
