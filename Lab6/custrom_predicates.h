#ifndef LAB6_CUSTROM_PREDICATES_H
#define LAB6_CUSTROM_PREDICATES_H

#include "cmath"

using std::pow;
using std::sqrt;

//check if the number is even
template <typename T>
bool is_even(T value) {
    if (value % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

//check if the number is less than given
template <typename T>
bool less_than_10(T value) {
    if (value < 10) {
        return true;
    } else {
        return false;
    }
}

//check if the module of number is more than value
template <typename T>
bool module_more_than_10(Custom_complex<T> num) {
    if (sqrt(pow(num.get_re(), 2) + pow(num.get_im(), 2)) > 10) {
        return true;
    } else {
        return false;
    }
}

//comparison predicate for normal numbers
template <typename T>
bool compare_normal(T first, T second) {
    if (first == second) {
        return true;
    } else {
        return false;
    }
}


//comparison predicate for complex numbers
template<typename T>
bool compare_complex(Custom_complex<T> first, Custom_complex<T> second) {
    if (first.get_re() == second.get_re() and first.get_im() == first.get_im()) {
        return true;
    } else {
        return false;
    }
}

#endif //LAB6_CUSTROM_PREDICATES_H
