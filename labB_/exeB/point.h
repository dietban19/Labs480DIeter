

#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    double x, y;
    int id;
    static int idNum;

public:
    Point(double x, double y);
    void display() const;
    // getters setters
    double getx() const;
    double gety() const;
    void setx(double x);
    void sety(double y);
    static int counter();
    static double distance(const Point &point1, const Point &point2);
    double distance(const Point &otherPoint);
};

#endif