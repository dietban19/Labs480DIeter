/*
 * File Name: square.cpp
 * Assignment: Lab 2 Exercise B
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: September 23, 2023
 */

#include "square.h"

Square::Square(double x, double y, const char *sName, double sideA) : Shape(x, y, sName), side_a(sideA)
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
void Square::setSideA(double side)
{
    side_a = side;
}

double Square::getSideA() const
{
    return side_a;
}

void Square::display()
{
    Shape::display();
    cout << "Side a: " << side_a << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}