#include "subset.h"

#include <iostream>
#include <algorithm>


using std::cout;
using std::copy_n;

//default constructor
Subset::Subset() {
    maxsize = 0;
    cursize = 0;
    dynset = nullptr;
};

//constructor with maximum size
Subset::Subset(int mx) {
    maxsize = mx;
    cursize = 0;
    dynset = new int[mx];
}

//constructor of copying
Subset::Subset(Subset &s) {
    maxsize = s.maxsize;
    cursize = s.cursize;
    if (s.dynset != nullptr) {
        dynset = new int[s.maxsize];
        std::copy_n(s.dynset, s.maxsize, dynset);
    } else {
        dynset = nullptr;
    }
}

//destructor
Subset::~Subset() {
    delete[] dynset;
};

//overloading assignment operator with copying
Subset &Subset::operator=(const Subset &s) {
    if (this == &s) {
        return *this;
    }
    maxsize = s.maxsize;
    cursize = s.cursize;
    delete[] dynset;
    if (s.dynset != nullptr) {
        dynset = new int[s.maxsize];
        copy_n(s.dynset, s.maxsize, dynset);
    } else {
        dynset = nullptr;
    }

    return *this;
}

//check if integer n is in subset
bool Subset::checkInSubset(int n) {
    if (dynset == nullptr) {
        return false;
    } else {
        bool flag = false;
        for (int i = 0; i < cursize; i++) {
            if (dynset[i] == n) {
                flag = true;
                break;
            }
        }

        return flag;
    }
}

//push element n to the end of subset
bool Subset::pushElem(int n) {
    if (cursize == maxsize or checkInSubset(n)) {
        return false;
    } else {
        cursize += 1;
        dynset[cursize - 1] = n;
        return true;
    }
}

//pop element n from subset
bool Subset::popElem(int n) {
    if (cursize == 0 or !checkInSubset(n)) {
        return false;
    } else {
        int it = 0;
        while (it < cursize) {
            if (dynset[it] == n) {
                break;
            } else {
                it++;
            }
        }
        cursize -= 1;
        for (int i = it; i < cursize; i++) {
            dynset[i] = dynset[i + 1];
        }
        return true;
    }
}

//find the intersection of 2 subsets
Subset *Subset::intersectSubset(Subset &s) {
    int newmax = std::max(maxsize, s.maxsize);
    Subset *intersection = new Subset(newmax);

    for (int i = 0; i < cursize; i++) {
        if (s.checkInSubset(dynset[i])) {
            intersection->pushElem(dynset[i]);
        }
    }

    return intersection;
}

//find the union of 2 subsets
Subset *Subset::unionSubset(Subset &s) {
    int newmax = maxsize + s.maxsize;
    Subset *united = new Subset(newmax);

    for (int i = 0; i < cursize; i++) {
        if (!united->checkInSubset(dynset[i])) {
            united->pushElem(dynset[i]);
        }
    }

    for (int i = 0; i < s.cursize; i++) {
        if (!united->checkInSubset(s.dynset[i])) {
            united->pushElem(s.dynset[i]);
        }
    }

    return united;
}

//add all elements from another subset
void Subset::addFromAnotherSubset(Subset &s) {
    int newmax = maxsize + s.maxsize;
    int *newdynset = new int[newmax];
    std::copy_n(dynset, maxsize, newdynset);
    delete[] dynset;
    dynset = newdynset;

    for (int i = 0; i < s.cursize; i++) {
        pushElem(s.dynset[i]);
    }
}


//remove all elements from another subset
void Subset::removeFromAnotherSubset(Subset &s) {
    for (int i = 0; i < s.cursize; i++) {
        popElem(s.dynset[i]);
    }
}



//print the subset
void Subset::printSubset() {
    if (dynset == nullptr) {
        cout << "Subset is empty";

        return;
    } else {
        cout << "Subset: ";
        for (int i = 0; i < cursize; i++) {
            cout << dynset[i] << " ";
        }
        cout << "\n";

        return;
    }
}