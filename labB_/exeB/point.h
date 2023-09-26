

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
    void display();
    double getXPoint() const;
    double getYPoint() const;
    void setXPoint(double x);
    void setYPoint(double y);
    // static int counter();
    static int counter(); // Added this line
    static double euclideanDistance(const Point &point1, const Point &point2);
    double euclideanDistance(const Point &otherPoint);
};

#endif