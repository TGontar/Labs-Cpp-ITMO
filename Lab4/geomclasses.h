#ifndef LAB4_GEOMCLASSES_H
#define LAB4_GEOMCLASSES_H

// Интерфейс "Геометрическая фигура".
class IGeoFig {
public:
    virtual double square() = 0;

    virtual double perimeter() = 0;
};


// Вектор
class CVector2D {
public:
    double x, y;
};


// Интерфейс "Физический объект".
class IPhysObject {
public:
    virtual double mass() = 0;

    virtual CVector2D position() = 0;

    virtual bool operator==(const IPhysObject &ob) const = 0;

    virtual bool operator<(const IPhysObject &ob) const = 0;
};


// Интерфейс "Отображаемый"
class IPrintable {
public:
    virtual void draw() = 0;
};


// Интерфейс для классов, которые можно задать через диалог с пользователем.
class IDialogInitiable {
    virtual void initFromDialog() = 0;
};


// Интерфейс "Класс"
class BaseCObject {
public:
    virtual const char *classname() = 0;

    virtual unsigned int size() = 0;
};

class IFigure: public IGeoFig, public IPhysObject, public IPrintable, public IDialogInitiable, public BaseCObject {};


#endif //LAB4_GEOMCLASSES_H

