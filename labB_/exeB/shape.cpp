/*
 * File Name: shape.cpp
 * Assignment: Lab 2 Exercise B
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: October 1, 2023
 */
#include <string.h>
#include <iostream>
#include "point.h"
#include "shape.h"
using namespace std;

Shape::Shape(double x, double y, const char *sName) : origin(x, y)
{
    shapeName = new char[strlen(sName) + 1];
    strcpy(shapeName, sName);
}
Shape::~Shape()
{
    delete[] shapeName;
}

const Point &Shape::getOrigin() const
{
    return origin;
}

const char *Shape::getName() const
{
    return shapeName;
}

void Shape::display()
{
    cout << endl;
    cout << "Shape Name: " << shapeName << endl;
    origin.display();
}
double Shape::distance(Shape &main_shape, Shape &other)
{
    return Point::distance(main_shape.origin, other.origin);
}
double Shape::distance(const Shape &other)
{
    return origin.distance(other.origin);
}
void Shape::move(double dx, double dy)
{
    origin.setx(origin.getx() + dx);
    origin.sety(origin.gety() + dy);
}

char &Shape::operator[](const int index) const
{
    return shapeName[index];
}