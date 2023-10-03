/*
 * File Name: point.h
 * Assignment: Lab 2 Exercise B
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: October 1, 2023
 */
#include <iostream>
#include <stdlib.h>
#include "point.h"

using namespace std;

// start at 1000, and for each new object, incremenet by one
int Point::idNum = 1000;
Point::Point(double x, double y) : x(x), y(y), id(++idNum) {}

void Point::display() const
{
    cout << "X-Coordinate: " << x;
    cout << endl;
    cout << "Y-Coordinate: " << y;
    cout << endl;
}

double Point::getx() const { return x; }
double Point::gety() const { return y; }
void Point::setx(double x)
{
    this->x = x;
}
void Point::sety(double y)
{
    this->y = y;
}

int Point::counter()
{
    // subtract 1000 so we can find the amount of Point Objects.
    return idNum - 1000;
}

// Distance formula = √((x2 - x1)^2 + (y2 - y1)^2)
double Point::distance(const Point &point1, const Point &point2)
{
    return sqrt((pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2)));
}

double Point::distance(const Point &otherPoint)
{
    return sqrt(pow(otherPoint.x - this->x, 2) + pow(otherPoint.y - this->y, 2));
}
