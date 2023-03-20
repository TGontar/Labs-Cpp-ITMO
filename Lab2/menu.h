#include "subset.h"

#ifndef LAB2_MENU_H
#define LAB2_MENU_H

class Menu {
private:
    Subset *currentSubset;
public:
    Menu();

    void menuInterface();

    Subset *createSubset();

    void checkElement();

    void addElement();

    void popElement();

    void intersectSubsets();

    void uniteSubsets();

    void addFromAnother();

    void rmFromAnother();

    void printSubset(Subset *);

    void stopProgram();
};

#endif //LAB2_MENU_H
