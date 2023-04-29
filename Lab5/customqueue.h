#ifndef LAB5_CUSTOMQUEUE_H
#define LAB5_CUSTOMQUEUE_H

#include "queuexception.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
class CustomQueue {
private:
    int capacity;
    int head;
    int tail;
    T *cqueue;
public:
    //defeault constructor
    CustomQueue() {
        capacity = 0;
        head = 0;
        tail = 0;
        cqueue = nullptr;
    };

    //constructor with N given
    CustomQueue(int N) {
        capacity = N;
        head = 0;
        tail = 0;
        cqueue = new T[N] {};
    }

    //constructor of copying
    CustomQueue(CustomQueue &q) {
        head = q.head;
        tail = q.tail;
        cqueue = new T[capacity];

        for (int i = head; i <= tail; i++) {
            cqueue[i % capacity] = q.cqueue[i % capacity];
        }

    }

    //destructor
    ~CustomQueue() {
        delete [] cqueue;
    }

    //overloading assignment operator with copying
    CustomQueue &operator=(CustomQueue const &q) {
        if (&q == this) {
            return *this;
        }

        head = q.head;
        tail = q.tail;

        delete[]cqueue;
        cqueue = new T[capacity];

        for (int i = head; i <= tail; i++) {
            cqueue[i % capacity] = q.cqueue[i % capacity];
        }

        return *this;
    }

    //push back func
    void push_back(T val) {
        if (head != tail and (head % capacity) == (tail % capacity)) {
            throw QueueException("Queue overflow");
        } else {
            tail += 1;
            cqueue[tail % capacity] = val;
            return;
        }
    }

    //pop front func
    T pop_front() {
        if (head == tail) {
            throw QueueException("Queue is empty");
        } else {
            T tmp = cqueue[head % capacity];
            head += 1;
            return tmp;
        }
    }

    //print queue
    void print_queue() {
        cout << "Queue:" << endl;
        for (int i = head; i <= tail; i++) {
            cout << cqueue[i % capacity] << " ";
        }
        cout << endl;
    }



};

#endif //LAB5_CUSTOMQUEUE_H
