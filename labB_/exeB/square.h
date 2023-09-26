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
private:
    double side_a;

public:
    Square(double x, double y, const char *sName, double side_a);
    double area() const;
    double perimeter() const;
    void setSideA(double side);
    double getSideA() const;
    void display();
};
#endif