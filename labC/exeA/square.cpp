/*
 * File Name: square.cpp
 * Assignment: Lab 2 Exercise B
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: September 1, 2023
 */

#include "square.h"

// Square::Square(Point&orgn, double sideA,const char *sName):Shape(orgn, sName), side_a(sideA)
// {}
Square::Square(double x, double y, double sideA, const char *sName) : Shape(Point(x,y),sName), side_a(sideA)
{
}

double Square::area() const
{
    return side_a * side_a;
}
double Square::perimeter() const
{
    return side_a * 4;
}
void Square::set_side_a(double side)
{
    side_a = side;
}

double Square::get_side_a() const
{
    return side_a;
}

void Square::display()
{
    cout << endl;
    cout << "Square Name: " << getName() << endl;
    getOrigin().display();
    cout << "Side a: " << side_a << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
    cout << endl;
}
// Square &Square::operator=(const Square &other)
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
// Square::Square(const Square &other)
//     : Shape(Point(other.getOrigin().getx(), other.getOrigin().gety()), other.getName()), side_a(other.side_a)
// {
//     cout << "calling shape copy" << endl;
// }