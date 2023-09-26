
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
private:
    Point origin;
    char *shapeName;

public:
    // Point x, y
    Shape(double x, double y, const char *sName);
    ~Shape();
    const Point &getOrigin() const;
    const char *getName() const;
    void display();
    double distance(const Shape &other);
    static double distance(Shape &the_shape, Shape &other);
    void move(double dx, double dy);
};

#endif