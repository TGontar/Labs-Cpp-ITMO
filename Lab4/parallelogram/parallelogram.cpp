#include "parallelogram.h"

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

//default constructor
Parallelogram::Parallelogram() {
    start = CVector2D{0, 0};
    a = CVector2D{0, 0};
    b = CVector2D{0, 0};
}

//constuctor with given vectors
Parallelogram::Parallelogram(CVector2D &s, CVector2D &one, CVector2D &two) {
    start = s;
    a = one;
    b = two;
}

//length of a side
double Parallelogram::sidelength(CVector2D &vec) {
    double len = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    return len;
}

//parallelogram square
double Parallelogram::square() {
    double ans = a.x * b.y - a.y * b.x;
    return ans;
}

//parallelogram perimeter
double Parallelogram::perimeter() {
    double ans = 2 * (sidelength(a) + sidelength(b));
    return ans;
}

//parallelogram mass
double Parallelogram::mass() {
    return square();
}

//parallelogram mass centre - diagonals intersection
CVector2D Parallelogram::position() {
    CVector2D *vec = new CVector2D;
    vec->x = (a.x + b.x) / 2 + start.x;
    vec->y = (a.y + b.y) / 2 + start.y;

    return *vec;
}

//mass comparing operator overloading
bool Parallelogram::operator==(const IPhysObject &other) const {
    double first = const_cast<Parallelogram &>(*this).mass();
    double second = const_cast<Parallelogram &>(dynamic_cast<const Parallelogram &>(other)).mass();

    if (first == second) {
        return true;
    } else {
        return false;
    }
}

//mass comparing operator overloading
bool Parallelogram::operator<(const IPhysObject &other) const {
    double first = const_cast<Parallelogram &>(*this).mass();
    double second = const_cast<Parallelogram &>(dynamic_cast<const Parallelogram &>(other)).mass();

    if (first < second) {
        return true;
    } else {
        return false;
    }
}

//draw a parallelogram
void Parallelogram::draw() {
    cout << "Пареллелограмм: " << classname() << endl;
    cout << "Координаты векторов параллелограмма:" << endl;
    cout << "Вектор координат стартовой точки: " << start.x << " " << start.y << endl;
    cout << "Вектор 1 стороны: " << a.x << " " << a.y << endl;
    cout << "Вектор 2 стороны: " << b.x << " " << b.y << endl;
    cout << endl;
}

//initialise a parallelogram from console
void Parallelogram::initFromDialog() {
    double sx, sy, ax, ay, bx, by;
    cout << "Введите координаты векторов для параллелограмма" << endl;
    cout << "Координаты вектора смещения для стартовой точки:" << endl;
    cin >> sx >> sy;
    cout << "Координаты вектора стороны 1:" << endl;
    cin >> ax >> ay;
    cout << "Координаты вектора стороны 2:" << endl;
    cin >> bx >> by;
    cout << endl;

    start = CVector2D{sx, sy};
    a = CVector2D{ax, ay};
    b = CVector2D{bx, by};
}

//parallelogram's classname
const char * Parallelogram::classname() {
    return typeid(*this).name();
}

//parallelogram's class size
unsigned int Parallelogram::size() {
    return sizeof(*this);
}

