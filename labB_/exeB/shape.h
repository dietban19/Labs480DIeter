/*
 * File Name: shape.h
 * Assignment: Lab 2 Exercise B
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: October 1, 2023
 */
#include <iostream>
#include <string>
using namespace std;
#include "point.h"
#ifndef SHAPE_H
#define SHAPE_H

/*
 */
class Shape
{
protected:

    Point origin;
    char *shapeName;

public:
    // Point x, y
    Shape(double x, double y, const char *sName);
    virtual ~Shape();
    virtual double area() const = 0;      
    virtual double perimeter() const = 0; 
    const Point &getOrigin() const;
    const char *getName() const;
    virtual void display();
    double distance(const Shape &other);
    static double distance(Shape &main_shape, Shape &other);
    virtual void move(double dx, double dy);
    char &operator[](const int index) const;
};

#endif