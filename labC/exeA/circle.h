/*
 * File Name: circle.h
 * Assignment: Lab 3 Exercise B
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: October 1, 2023
 */
#include <iostream>
#include <stdlib.h>
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
using namespace std;
#include "square.h"
#include <cmath>
//  Inherits square
class Circle : virtual public Shape
{
protected:
    double radius;

public:
    Circle(double x, double y, double radius_a, const char *sName);
    double area() const;
    double perimeter() const;
    void set_radius(double radii);
    double get_radius() const;
    void display();
    // Circle(const Circle &other);
    // Circle &operator=(const Circle &other);
};
#endif