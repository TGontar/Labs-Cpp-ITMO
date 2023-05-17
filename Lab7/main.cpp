#include "iostream"
#include "circularbuffer.h"

int main() {
    CircularBuffer<int> buff1(5);
    buff1.push_back(1);
    buff1.print_buffer();
    buff1.push_back(2);
    buff1.print_buffer();
    buff1.push_back(3);
    buff1.print_buffer();
    buff1.pop_back();
    buff1.print_buffer();
    buff1.push_back(4);
    buff1.print_buffer();
    buff1.pop_front();
    buff1.print_buffer();
    buff1.push_back(5);
    buff1.print_buffer();
    buff1.push_back(6);
    buff1.print_buffer();
    buff1.push_back(7);
    buff1.print_buffer();
    buff1.push_back(8);
    buff1.print_buffer();
    buff1.push_front(9);
    buff1.print_buffer();
    buff1.set_capacity(10);
    buff1.print_buffer();

    auto it1 = CircularBuffer<int>::Custom_iterator(buff1.begin());
    buff1.insert(it1, 10);
    buff1.print_buffer();
    buff1.remove(buff1.begin() + 4);
    buff1.print_buffer();

    return 0;
}
