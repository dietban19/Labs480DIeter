
#include <iostream>
#include <string>
using namespace std;
#include "point.h"
#ifndef SHAPE_H
#define SHAPE_H

/*
 */
class Shape
{
protected:
    // The type or member can be accessed only by code in the same class ,
    // or in a class that is derived from that class .
    Point origin;
    char *shapeName;

public:
    // Point x, y
    Shape(double x, double y, const char *sName);
    virtual ~Shape();
    virtual double area() const = 0;      // pure virtual function
    virtual double perimeter() const = 0; // pure virtual function
    const Point &getOrigin() const;
    const char *getName() const;
    virtual void display();
    double distance(const Shape &other);
    static double distance(Shape &main_shape, Shape &other);
    virtual void move(double dx, double dy);
    char &operator[](const int index) const;
};

#endif