/*
 * File Name: square.h
 * Assignment: Lab 2 Exercise B
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: October 1, 2023
 */
#include <iostream>
#include <stdlib.h>
#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
using namespace std;
#include "shape.h"
#include <string.h>
// Square Inherits Shapesasdf
class Square : virtual public Shape
{
protected:
    double side_a;

public:
// Square(Point&orgn, double sideA,const char *sName);
    Square(double x, double y, double side_a, const char *sName);
    double area() const;
    double perimeter() const;
    void set_side_a(double side);
    double get_side_a() const;
    void display();
    // Square(const Square &other); // Copy Constructor declaration
    // Square &operator=(const Square &other);
};
#endif