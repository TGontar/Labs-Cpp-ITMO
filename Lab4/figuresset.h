#ifndef LAB4_FIGURESSET_H
#define LAB4_FIGURESSET_H

#include "ellipse/ellipse.h"
#include "parallelogram/parallelogram.h"

#include <set>

using std::set;

class Figures {
private:
    set<IFigure *> figs;
public:
    void addfigure();

    void display();

    double squareall();

    double perimeterall();

    CVector2D positionall();

    unsigned int memoryall();

};


#endif //LAB4_FIGURESSET_H
