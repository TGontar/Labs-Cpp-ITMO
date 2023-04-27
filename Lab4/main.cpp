#include "figuresset.h"
#include "parallelogram/parallelogram.h"
#include "ellipse/ellipse.h"

#include <iostream>
#include <string>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Figures figs1;

    cout << "1. Добавить фигуру в множество" << endl;
    cout << "2. Отобразить все фигуры" << endl;
    cout << "3. Суммарная площадь фигур" << endl;
    cout << "4. Суммарный периметр фигур" << endl;
    cout << "5. Центр масс всех фигур" << endl;
    cout << "6. Память на все экземляры классов" << endl;
    cout << "Символ точки - остановить программу" << endl;

    while (true) {
        string str;
        cin >> str;
        if (str == ".") {
            break;
        } else if (str == "1") {
            figs1.addfigure();
            cout << "Успех" << endl;
        } else if (str == "2") {
            figs1.display();
        } else if (str == "3") {
            cout << "Cуммарная площадь равна " << figs1.squareall() << endl;
        } else if (str == "4") {
            cout << "Cуммарный периметр равен " << figs1.perimeterall() << endl;
        } else if (str == "5") {
            cout << "Центр масс координаты " << figs1.positionall().x << " " << figs1.positionall().y << endl;
        } else if (str == "6") {
            cout << "Всего фигуры занимают " << figs1.memoryall() << " байт памяти" << endl;
        }
    }


    cout << "До свидания" << endl;

    return 0;
}
