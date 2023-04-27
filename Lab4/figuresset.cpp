#include "ellipse/ellipse.h"
#include "parallelogram/parallelogram.h"
#include "figuresset.h"

#include "iostream"

using std::cin;
using std::cout;
using std::endl;

//add a figure to set
void Figures::addfigure() {
    int choice;
    cout << "Какую фигуру вы хотите добавить? Параллелограмм - 1, Эллипс - 2:" << endl;
    cin >> choice;
    while (choice != 1 and choice != 2) {
        cout << "Введите 1 или 2" << endl;
        cin >> choice;
    }

    if (choice == 1) {
        Parallelogram *temp = new Parallelogram;
        temp->initFromDialog();
        figs.insert(temp);
    } else {
        Ellipse *temp = new Ellipse;
        temp ->initFromDialog();
        figs.insert(temp);
    }
}

//display all figures
void Figures::display() {
    for (auto i:figs) {
        i->draw();
    }

    for (auto i:figs) {
        i->draw();
    }
}

//sum of all squares
double Figures::squareall() {
    double counter = 0;
    for (auto i:figs) {
        counter += i->square();
    }

    for (auto i:figs) {
        counter += i->square();
    }

    return counter;
}

//sum of all perimeters
double Figures::perimeterall() {
    double counter = 0;
    for (auto i:figs) {
        counter += i->perimeter();
    }

    for (auto i:figs) {
        counter += i->perimeter();
    }

    return counter;
}

//central position of all
CVector2D Figures::positionall() {
    CVector2D ans{0, 0};
    double curx = 0;
    double cury = 0;
    double m = 0;

    for (auto i:figs) {
        curx += i->position().x * i->mass();
        cury += i->position().y * i->mass();
        m += i->mass();
    }

    for (auto i:figs) {
        curx += i->position().x * i->mass();
        cury += i->position().y * i->mass();
        m += i->mass();
    }

    ans.x = curx/m;
    ans.y = cury/m;

    return ans;
}

//memory of all classes
unsigned int Figures::memoryall() {
    unsigned int ans = 0;

    for (auto i:figs) {
        ans += i->size();
    }

    for (auto i:figs) {
        ans += i->size();
    }

    return ans;
}