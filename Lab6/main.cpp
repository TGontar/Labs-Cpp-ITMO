#include "custom_algorithms.h"
#include "custom_type.h"
#include "custrom_predicates.h"

#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    std::vector<int> test = {2, 6, 2, 1, 3};
    cout << all_of(test.begin(), test.end(), is_even<int>) << endl;
    cout << all_of(test.begin(), test.end(), less_than_10<int>) << endl;
    cout << is_partitioned(test.begin(), test.end(), is_even<int>) << endl;
    cout << *find_backward(test.begin(), test.end(), compare_normal<int>, 3) << endl;
    cout << endl;

    std::vector<Custom_complex<float>> test2 = {Custom_complex<float>(6, 9),
                                                Custom_complex<float>(15, 12),
                                                Custom_complex<float>(45, 11),
                                                Custom_complex<float>(62, 71),
                                                Custom_complex<float>(156, 3)};

    cout << all_of(test2.begin(), test2.end(), module_more_than_10<float>) << endl;
    cout << is_partitioned(test2.begin(), test2.end(), module_more_than_10<float>) << endl;
    (*find_backward(test2.begin(), test2.end(), compare_complex<float>, Custom_complex<float>(45, 11))).print_num();


    return 0;
}
