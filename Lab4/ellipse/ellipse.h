#ifndef LAB4_ELLIPSE_H
#define LAB4_ELLIPSE_H

#include "../geomclasses.h"

class Ellipse: public IFigure {
private:
    CVector2D center{};
    double big_axis;
    double small_axis;
public:
    Ellipse();

    Ellipse(CVector2D &, double, double);

    double square() override;

    double perimeter() override;

    double mass() override;

    CVector2D position() override;

    bool operator==(const IPhysObject &) const override;

    bool operator<(const IPhysObject &) const override;

    void draw() override;

    void initFromDialog() override;

    const char * classname() override;

    unsigned int size() override;
};

#endif //LAB4_ELLIPSE_H
