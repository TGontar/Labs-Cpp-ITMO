#ifndef LAB7_CIRCULARBUFFER_H
#define LAB7_CIRCULARBUFFER_H

#include "iterator"
#include "stdexcept"
#include "iostream"

using std::iterator;
using std::cout;
using std::endl;

template<typename T>
class CircularBuffer {
private:
    int capacity{};
    int cursize{};
    int head{};
    int tail{};
    T *buffer;
public:
    class Custom_iterator : public iterator<std::random_access_iterator_tag, T> {
    private:
        T *ptr;
    public:
        //default constructor
        explicit Custom_iterator() = default;

        //constructor with given pointer
        explicit Custom_iterator(T *p) {
            ptr = p;
        }

        //constructor of copying
        Custom_iterator(const Custom_iterator &other) {
            ptr = other.ptr;
        }

        //overloading assignment operator
        Custom_iterator &operator=(const Custom_iterator &other) {
            if (this == other) {
                return *this;
            }

            ptr = other.ptr;

        }

        //overloading plus operator
        Custom_iterator &operator+(T value) {
            ptr += value;
            return *this;
        }

        //overloading minus operator
        Custom_iterator &operator-(T value) {
            ptr -= value;
            return *this;
        }

        //overloading minus operator with another iterator
        typename std::iterator<std::random_access_iterator_tag, T>::difference_type operator-(const Custom_iterator &other) const {
            return ptr - other.ptr;
        }


        //overloading increment operator
        Custom_iterator &operator++() {
            ptr += 1;
            return *this;
        }

        //overloading increment operator
        Custom_iterator &operator--() {
            ptr -= 1;
            return *this;
        }

        //overloading equality operator
        bool operator==(const Custom_iterator &other) const {
            if (ptr == other.ptr) {
                return true;
            } else {
                return false;
            }
        }

        //overloading inequality operator
        bool operator!=(const Custom_iterator &other) const {
            if (ptr != other.ptr) {
                return true;
            } else {
                return false;
            }
        }

        //overloading "less" operator
        bool operator<(const Custom_iterator &other) const {
            if (ptr < other.ptr) {
                return true;
            } else {
                return false;
            }
        }

        //overloading "less or equal" operator
        bool operator<=(const Custom_iterator &other) const {
            if (ptr <= other.ptr) {
                return true;
            } else {
                return false;
            }
        }

        //overloading "more" operator
        bool operator>(const Custom_iterator &other) const {
            if (ptr > other.ptr) {
                return true;
            } else {
                return false;
            }
        }

        //overloading "more or equal" operator
        bool operator>=(const Custom_iterator &other) const {
            if (ptr >= other.ptr) {
                return true;
            } else {
                return false;
            }
        }

        //overloading dereferencing operator
        T &operator*() const {
            return *ptr;
        }

        //overloading arrow operator
        T *operator->() const {
            return ptr;
        }

    };

    //default constructor
    explicit CircularBuffer() = default;

    //constructor with capacity given
    explicit CircularBuffer(int c) {
        capacity = c;
        cursize = 0;
        head = 0;
        tail = 0;
        buffer = new T[c]{};
    }

    //destructor with deleting dynamic object
    ~CircularBuffer() {
        delete [] buffer;
    }

    //begin iterator
    Custom_iterator begin() {
        return Custom_iterator(buffer);
    }

    //end iterator
    Custom_iterator end() {
        return Custom_iterator(buffer + capacity);
    }

    //push back method
    void push_back(T val) {
        if (head == tail and cursize == 0) {
            buffer[tail] = val;
            cursize += 1;
            return;
        }

        if (tail == capacity - 1) {
            tail = 0;
        } else {
            tail += 1;
        }

        if (cursize <= capacity) {
            cursize += 1;
        } else {
            if (head == capacity - 1) {
                head = 0;
            } else {
                head += 1;
            }
        }

        buffer[tail] = val;
    }

    //pop back method
    void pop_back() {
        if (cursize == 0) {
            throw std::out_of_range("Can't pop from empty buffer");
        } else {
            if (tail == 0) {
                tail = capacity - 1;
            } else {
                tail -= 1;
            }

            cursize -= 1;
        }
    }

    //push front method
    void push_front(T val) {
        if (head == tail and cursize == 0) {
            buffer[head] = val;
            cursize += 1;
            return;
        }

        if (head == 0) {
            head = capacity - 1;
        } else {
            head -= 1;
        }

        if (cursize <= capacity) {
            cursize += 1;
        } else {
            if (tail == 0) {
                tail = capacity - 1;
            } else {
                tail -= 1;
            }
        }

        buffer[head] = val;
    }

    //pop front method
    void pop_front() {
        if (cursize == 0) {
            throw std::out_of_range("Can't pop from empty buffer");
        } else {
            if (head == capacity - 1) {
                head = 0;
            } else {
                head += 1;
            }

            cursize -= 1;
        }
    }

    //insert into into buffer
    void insert(Custom_iterator it, T val) {
        int index = it - begin();

        for (int i = tail; i != index; i == 0 ? i = capacity - 1 : i--) {
            buffer[(i + 1) % capacity] = buffer[i % capacity];
        }

        buffer[index + 1] = val;

        if (cursize == capacity) {
            if (head == capacity - 1) {
                head = 0;
            } else {
                head += 1;
            }

            if (tail == capacity - 1) {
                tail = 0;
            } else {
                tail += 1;
            }
        } else {
            cursize += 1;

            if (tail == capacity - 1) {
                tail = 0;
            } else {
                tail += 1;
            }
        }

    }

    //remove from the buffer
    void remove(Custom_iterator it) {
        if (cursize == 0) {
            throw std::out_of_range("Can't remove from empty buffer");
        }

        int index = std::distance(begin(), it);
        for (int i = index; i != tail; i == capacity - 1 ? i = 0 : i++) {
            buffer[i % capacity] = buffer[(i + 1) % capacity];
        }

        cursize -= 1;

        if (tail == 0) {
            tail = capacity - 1;
        } else {
            tail -= 1;
        }
    }

    //overloading indexing operator
    T &operator[] (int ind) const {
        return buffer[ind % capacity];
    }

    //set new capacity
    void set_capacity(int newcapacity) {
        if (newcapacity <= capacity) {
            throw "New capacity should be more than current one";
        }

        T *newbuff = new T[newcapacity] {};
        for (int i = 0; i < capacity; i++) {
            newbuff[i] = buffer[i];
        }

        delete [] buffer;
        buffer = newbuff;
        head = 0;
        tail = capacity - 1;
        capacity = newcapacity;

    }


    //print the buffer
    void print_buffer() {
        for (int i = 0; i < capacity; i++) {
            cout << buffer[i] << " ";
        }

        cout << "\n";
    }

};

#endif //LAB7_CIRCULARBUFFER_H
