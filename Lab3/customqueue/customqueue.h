#ifndef LAB3_CUSTOMQUEUE_H
#define LAB3_CUSTOMQUEUE_H

class CustomQueue {
private:
    static const int maximum = 100;
    int head;
    int tail;
    int *cqueue;
public:
    CustomQueue();

    CustomQueue(int, int *);

    CustomQueue(CustomQueue &);

    ~CustomQueue();

    CustomQueue &operator=(CustomQueue const &);

    bool operator<<(int);

    int operator>>(int);

    bool pushBack(int);

    int popFront();

    void printQueue();
};

#endif //LAB3_CUSTOMQUEUE_H
