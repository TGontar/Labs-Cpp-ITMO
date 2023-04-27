#define pi M_PI

#include "ellipse.h"

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

//default constructor
Ellipse::Ellipse() {
    center = CVector2D{0, 0};
    big_axis = 0;
    small_axis = 0;
}

//ellipse with given params
Ellipse::Ellipse(CVector2D &c, double small, double big) {
    center = c;
    big_axis = big;
    small_axis = small;
}

//ellipse square
double Ellipse::square() {
    double ans = pi * big_axis * small_axis;
    return ans;
}

//ellipse perimeter
double Ellipse::perimeter() {
    double ans = 4 * ((pi * big_axis * small_axis + (big_axis - small_axis)) / (big_axis + small_axis));
    return ans;
}

//ellipse mass
double Ellipse::mass() {
    return square();
}

//ellipse mass centre - diagonals intersection
CVector2D Ellipse::position() {
    return center;
}

//mass comparing operator overloading
bool Ellipse::operator==(const IPhysObject &other) const {
    double first = const_cast<Ellipse &>(*this).mass();
    double second = const_cast<Ellipse &>(dynamic_cast<const Ellipse &>(other)).mass();

    if (first == second) {
        return true;
    } else {
        return false;
    }
}

//mass comparing operator overloading
bool Ellipse::operator<(const IPhysObject &other) const {
    double first = const_cast<Ellipse &>(*this).mass();
    double second = const_cast<Ellipse &>(dynamic_cast<const Ellipse &>(other)).mass();

    if (first < second) {
        return true;
    } else {
        return false;
    }
}

//draw an ellipse
void Ellipse::draw() {
    cout << "Эллипс: " << classname() << endl;
    cout << "Координаты центра эллипса:" << endl;
    cout << center.x << " " << center.y << endl;
    cout << "Большая полуось: " << big_axis << endl;
    cout << "Малая полуось: " << small_axis << endl;
    cout << endl;
}

//initialise an ellipse from console
void Ellipse::initFromDialog() {
    double cx, cy, big, small;
    cout << "Введите координаты центра эллипса: " << endl;
    cin >> cx >> cy;
    cout << "Введите большую и малую полуось: " << endl;
    cin >> big >> small;

    center = CVector2D{cx, cy};
    big_axis = big;
    small_axis = small;
}

//ellipse's classname
const char * Ellipse::classname() {
    return typeid(*this).name();
}

//ellipse's class size
unsigned int Ellipse::size() {
    return sizeof(*this);
}


