/*
 * File Name: rectangle.cpp
 * Assignment: Lab 2 Exercise B
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: October 1, 2023
 */

#include "rectangle.h"

// 5 7 12 15
// Square(5, 7, 12, name)
Rectangle::Rectangle(double x, double y, double side_a, double sideB, const char *sName) : Square(x, y, side_a, sName), side_b(sideB)
{
}
double Rectangle::area() const
{
    return side_a * side_b;
}
double Rectangle::perimeter() const
{
    return (side_a * 2) + (side_b * 2);
}
void Rectangle::set_side_a(double side_a)
{
    Square::set_side_a(side_a);
}

double Rectangle::get_side_a() const
{
    return Square::get_side_a();
}
void Rectangle::set_side_b(double side)
{
    side_b = side;
}

double Rectangle::get_side_b() const
{
    return side_b;
}
void Rectangle::display()
{
    cout << endl;
    // Square::display();
    cout << "Rectangle Name: " << Shape::getName() << endl;
    Square::getOrigin().display();
    cout << "Side a: " << side_a << endl;
    cout << "Side b: " << side_b << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
    cout << endl;
}
Rectangle::Rectangle(const Rectangle &other)

    : Square(other),
      side_b(other.side_b)
{
    cout
        << "\nCalling Copy: \n";
};

Rectangle &Rectangle::operator=(const Rectangle &other)
{
    if (this != &other)
    {
        Square::operator=(other); // call base class assignment operator
        side_b = other.side_b;
    }

    return *this;
}