/*
 * File Name: circle.cpp
 * Assignment: Lab 3 Exercise B
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: October 1, 2023
 */

#include "circle.h"

Circle::Circle(double x, double y, double radius_a, const char *sName) : Shape(Point(x,y),sName), radius(radius_a)
{
}

double Circle::area() const
{
    return M_PI * pow(radius, 2);
}
double Circle::perimeter() const
{
    return 2 * M_PI * radius;
}

void Circle::set_radius(double radii)
{
    radius = radii;
}
double Circle::get_radius() const
{
    return radius;
}
void Circle::display()
{
    cout << endl;
    cout << "Circle Name: " << getName() << endl;
    getOrigin().display();
    cout << "Radius: " << radius << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
    cout << endl;
}
// Circle &Circle::operator=(const Circle &other)
// {
//     if (this != &other)
//     {
//         delete[] shapeName;
//         shapeName = new char[strlen(other.shapeName) + 1];
//         side_a = other.side_a;
//         strcpy(shapeName, other.shapeName);
//         origin = other.origin;
//     }
//     return *this;
// }
// Circle::Circle(const Square &other)
//     : Shape(other.getOrigin().getx(), other.getOrigin().gety(), other.getName()), side_a(other.side_a)
// {
// }