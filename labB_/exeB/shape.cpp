
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
    cout << "Shape Name: " << shapeName << endl;
    origin.display();
}
double Shape::distance(Shape &the_shape, Shape &other)
{
    return Point::euclideanDistance(the_shape.origin, other.origin);
}
double Shape::distance(const Shape &other)
{
    return origin.euclideanDistance(other.origin);
}
void Shape::move(double dx, double dy)
{
    origin.setXPoint(origin.getXPoint() + dx);
    origin.setYPoint(origin.getYPoint() + dy);
}