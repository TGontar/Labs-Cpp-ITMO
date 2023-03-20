#ifndef LAB2_SUBSET_H
#define LAB2_SUBSET_H

class Subset {
private:
    int maxsize;
    int cursize;
    int *dynset;
public:
    Subset();

    Subset(int);

    Subset(Subset &);

    ~Subset();

    Subset &operator=(const Subset &);

    bool checkInSubset(int);

    bool pushElem(int);

    bool popElem(int);

    Subset *intersectSubset(Subset &);

    Subset *unionSubset(Subset &);

    void addFromAnotherSubset(Subset &);

    void removeFromAnotherSubset(Subset &);

    void printSubset();

};


#endif //LAB2_SUBSET_H
