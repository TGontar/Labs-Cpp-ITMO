#include "customqueue.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

inline CustomQueue &createQueue() {
    static const int maximum = 100;
    cout << "Enter queue: " << endl;

    //make a dynamic array of start queue
    cout << "Enter number of elements in queue" << endl;
    int curlen;
    cin >> curlen;
    while (curlen <= 0 or curlen > maximum) {
        cout << "The number of elements should be between 0 and 100" << endl;
        cin >> curlen;
    }

    cout << "Enter the elements of queue" << endl;
    int *temparr = new int[curlen];
    for (int i = 0; i < curlen; i++) {
        cin >> temparr[i];
    }

    CustomQueue *testqueue = new CustomQueue(curlen, temparr);

    delete[] temparr;

    return *testqueue;
}

inline void testingQueue() {
    cout << "Testing queue. First, enter a queue: " << endl;

    CustomQueue testqueue = createQueue();

    cout << "Enter elements to push" << endl;
    int curpush;
    cin >> curpush;
    for (int i = 0; i < curpush; i++) {
        int temp;
        cin >> temp;
        if (testqueue << temp) {
            cout << "Element " << temp << " pushed successfully" << endl;
        } else {
            cout << "Unable to push element " << temp << ": queue overflow" << endl;
        }
    }

    cout << "Now, enter the number of elements to pop" << endl;
    int curpop;
    cin >> curpop;
    for (int i = 0; i < curpop; i++) {
        int temp;
        temp = testqueue.popFront();
        if (temp != INT32_MIN) {
            cout << temp << endl;
        } else {
            cout << "Unable to pop element: queue is empty" << endl;
        }
    }

    cout << endl;
}