/*
 * File Name: curvecut.h
 * Assignment: Lab 3 Exercise B
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: October 1, 2023
 */
#include <iostream>
#include <stdlib.h>

using namespace std;
#include "circle.h"
#include "rectangle.h"
#include <cmath>

#ifndef CURVECUT_H
#define CURVECUT_H

class CurveCut : public Rectangle, public Circle
{
    private:

    public:
    //CurveCut rc(6, 5, 10, 12, 9, "CurveCut rc");
        CurveCut(double x, double y, double sideA, double sideB, double radius, const char *sName);
        double area() const;
        double perimeter() const;
        void display();
};
#endif