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
        T *buff;
        int size{};
        int current{};
    public:
        //constructor
        explicit Custom_iterator(T *buff, int capacity, int current) {
            this->buff = buff;
            this->size = capacity;
            this->current = current;
        }

        //overloading plus operator
        Custom_iterator &operator+(T value) {
            current = (current + value) % size;
            return *this;
        }

        //overloading minus operator
        Custom_iterator &operator-(T value) {
            current = (current + size - value) % size;
            return *this;
        }

        //overloading minus operator with another iterator
        typename std::iterator<std::random_access_iterator_tag, T>::difference_type
        operator-(const Custom_iterator &other) const {
            return &buff[current] - &buff[other.current];
        }

        //overloading increment operator
        Custom_iterator &operator++() {
            current = (current + 1) % size;
            return *this;
        }

        //overloading decrement operator
        Custom_iterator &operator--() {
            current = (current + size - 1) % size;
            return *this;
        }

        //overloading equality operator
        bool operator==(const Custom_iterator &other) const {
            if (current == other.current) {
                return true;
            } else {
                return false;
            }
        }

        //overloading inequality operator
        bool operator!=(const Custom_iterator &other) const {
            if (current != other.current) {
                return true;
            } else {
                return false;
            }
        }

        //overloading dereferencing operator
        T &operator*() const {
            return buff[current];
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
        delete[] buffer;
    }

    //begin iterator
    Custom_iterator begin() {
        return Custom_iterator(buffer, capacity, head);
    }

    //end iterator
    Custom_iterator end() {
        return Custom_iterator(buffer, capacity, tail);
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

        buffer[index] = val;
    }

    //remove from the buffer
    void remove(Custom_iterator it) {
        if (cursize == 0) {
            throw std::out_of_range("Can't remove from empty buffer");
        }

        int index = std::distance(begin(), it);

        buffer[index] = {};
    }

    //overloading indexing operator
    T &operator[](int ind) const {
        return buffer[ind % capacity];
    }

    //set new capacity
    void set_capacity(int newcapacity) {
        if (newcapacity <= capacity) {
            throw "New capacity should be more than current one";
        }

        T *newbuff = new T[newcapacity]{};
        for (int i = 0; i < capacity; i++) {
            newbuff[i] = buffer[i];
        }

        delete[] buffer;
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
