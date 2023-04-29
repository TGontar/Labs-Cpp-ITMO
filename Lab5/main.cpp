#include "minnumber.h"
#include "customqueue.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "How many will there be elements in your queue?" << endl;
    int n;
    cin >> n;

    CustomQueue<int> q(n);

    cout << "How many elems do you want to push?" << endl;
    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int tmp;
        cin >> tmp;

        try {
            q.push_back(tmp);
        } catch(QueueException &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    cout << "How many elems do you want to pop?" << endl;
    int w;
    cin >> w;
    for (int i = 0; i < w; i++) {
        try {
            int k = q.pop_front();
            cout << k << endl;
        } catch(QueueException &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

}
