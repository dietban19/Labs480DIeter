/*
 * File Name: circle.cpp
 * Assignment: Lab 3 Exercise B
 * Lab Section: B02
 * Completed by: Dieter Banaag
 * Submission Date: October 1, 2023
 */

#include "curvecut.h"



CurveCut::CurveCut(double x, double y, double sideA, double sideB, double radius, const char *sName)
    :    Shape(Point(x,y),sName),Rectangle(x,y,sideA,sideB,sName), Circle(x,y,radius,sName)
{
    if(radius > sideA || radius > sideB) {
            cout << "Error: The radius of the circle must be always less than or equal to the side_a and side_b." << endl;
            exit(1); // Exit the program
        }
}

void CurveCut::display(){
    cout << endl;
    cout << "CurveCut Name: " << getName() << endl;
    getOrigin().display();
    cout << "Radius: " << radius << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
    cout << endl;
}
//double Circle::area() const
double CurveCut::area() const {
    return Rectangle::area() - (Circle::area()/4);
}
double CurveCut::perimeter() const{
    return (Rectangle::perimeter() - (2*get_radius()))+(Circle::perimeter()/4);
}