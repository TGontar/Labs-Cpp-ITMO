#ifndef LAB4_Parallelogram_H
#define LAB4_Parallelogram_H

#include "../geomclasses.h"

class Parallelogram: public IFigure{
private:
    CVector2D start{};
    CVector2D a{};
    CVector2D b{};
public:
    Parallelogram();

    Parallelogram(CVector2D &, CVector2D &, CVector2D &);

    double sidelength(CVector2D &);

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

#endif //LAB4_Parallelogram_H
