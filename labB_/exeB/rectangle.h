/*
 * File Name: rectangle.h
 * Assignment: Lab 2 Exercise B
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: September 23, 2023
 */
#include <iostream>
#include <stdlib.h>
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
using namespace std;
#include "square.h"
//  Inherits square
class Rectangle : public Square
{
protected:
    double side_b;

public:
    Rectangle(double x, double y, double side_a, double side_b, const char *sName);
    double area() const;
    double perimeter() const;
    void set_side_a(double side_a);
    double get_side_a() const;
    void set_side_b(double side);
    double get_side_b() const;
    void display();
    Rectangle(const Rectangle &other);
    Rectangle &operator=(const Rectangle &other);
};
#endif