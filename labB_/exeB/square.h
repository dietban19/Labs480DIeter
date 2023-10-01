/*
 * File Name: square.h
 * Assignment: Lab 2 Exercise B
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: September 23, 2023
 */
#include <iostream>
#include <stdlib.h>
#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
using namespace std;
#include "shape.h"
// Square Inherits Shapesasdf
class Square : public Shape
{
protected:
    double side_a;

public:
    Square(double x, double y, double side_a, const char *sName);
    double area() const;
    double perimeter() const;
    void set_side_a(double side);
    double get_side_a() const;
    void display();
    Square(const Square &other); // Copy Constructor declaration
    Square &operator=(const Square &other);
};
#endif