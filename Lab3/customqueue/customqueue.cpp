#ifndef LAB3_CUSTOMQUEUE_C
#define LAB3_CUSTOMQUEUE_C

#include "customqueue.h"

#include <iostream>

using std::cout;
using std::endl;

//default constructor
CustomQueue::CustomQueue() {
    head = 0;
    tail = 0;
    cqueue = new int[maximum]{};
}

//constructor with given array and capacity
CustomQueue::CustomQueue(int n, int *arr) {
    head = 0;
    tail = 0;
    cqueue = new int[maximum]{};
    for (int i = 0; i < n; i++) {
        if (!pushBack(arr[i])) {
            break;
        }
    }
}

//constructor of copying
CustomQueue::CustomQueue(CustomQueue &q) {
    head = q.head;
    tail = q.tail;
    cqueue = new int[maximum]{};

    for (int i = head; i <= tail; i++) {
        cqueue[i % maximum] = q.cqueue[i % maximum];
    }
}

//destructor
CustomQueue::~CustomQueue() {
    delete[] cqueue;
}

//overloading assignment operator with copying
CustomQueue &CustomQueue::operator=(CustomQueue const &q) {
    if (&q == this) {
        return *this;
    }

    head = q.head;
    tail = q.tail;

    delete[]cqueue;
    cqueue = new int[maximum];

    for (int i = head; i <= tail; i++) {
        cqueue[i % maximum] = q.cqueue[i % maximum];
    }

    return *this;
}

//overloading << operator with pushing back element
bool CustomQueue::operator<<(int n) {
    if (pushBack(n)) {
        return true;
    } else {
        return false;
    }
}

//overloading >> operator with pop front element
int CustomQueue::operator>>(int n) {
    int ans = popFront();
    return ans;
}

//push into queue function
bool CustomQueue::pushBack(int n) {
    if (head != tail and (head % maximum) == (tail % maximum)) {
        return false;
    } else {
        tail += 1;
        cqueue[tail % maximum] = n;
        return true;
    }
}

//pop from queue function
int CustomQueue::popFront() {
    if (head == tail) {
        return INT32_MIN;
    } else {
        int tmp = cqueue[head % maximum];
        cqueue[head % maximum] = 0;
        head += 1;
        return tmp;
    }
}

//print queue
void CustomQueue::printQueue() {
    cout << "Queue:" << endl;
    for (int i = head; i <= tail; i++) {
        cout << cqueue[i % maximum] << " ";
    }
    cout << endl;
}

#endif //LAB3_CUSTOMQUEUE_C
