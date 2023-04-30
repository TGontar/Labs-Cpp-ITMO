#ifndef LAB6_CUSTOM_TYPE_H
#define LAB6_CUSTOM_TYPE_H

#include <iostream>

using std::cout;
using std::endl;

//complex number custom template class
template <typename T>
class Custom_complex {
private:
    T re;
    T im;
public:
    Custom_complex(T a, T b) {
        re = a;
        im = b;
    };

    T get_re() {
        return re;
    }

    T get_im() {
        return im;
    }

    T print_num() {
        cout << re << " " << im << endl;
    }

};
#endif //LAB6_CUSTOM_TYPE_H
