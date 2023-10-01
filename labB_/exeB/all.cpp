#include <iostream>
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

#include <iostream>
#include <stdlib.h>
#include "point.h"

using namespace std;

// start at 1000, and for each new object, incremenet by one
int Point::idNum = 1000;
Point::Point(double x, double y) : x(x), y(y), id(++idNum) {}

void Point::display()
{
    cout << "Point X: " << x;
    cout << endl;
    cout << "Point Y: " << y;
    cout << endl;
}
double Point::getXPoint() const { return x; }
double Point::getYPoint() const { return y; }
void Point::setXPoint(double x)
{
    this->x = x;
}
void Point::setYPoint(double y)
{
    this->y = y;
}

int Point::counter()
{

    return idNum - 1000;
}

// Distance formula = √((x2 - x1)^2 + (y2 - y1)^2)
double Point::euclideanDistance(const Point &point1, const Point &point2)
{
    return sqrt((pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2)));
}

double Point::euclideanDistance(const Point &otherPoint)
{
    return sqrt(pow(otherPoint.x - this->x, 2) + pow(otherPoint.y - this->y, 2));
}

int main()
{
    Point p1(4, 6);
    Point p2(1, 7);
    p1.display();
    double staticDistance = Point::euclideanDistance(p1, p2);
    double normalDistance = p1.euclideanDistance(p2);
    cout << "Static: " << staticDistance << endl;
    cout << "normal: " << normalDistance << endl;
    cout << endl;
    // const char *names = "mysquare";
    Square square(0.0, 3.0, "MySquare", 5.0);
    square.display();

    // euclideanDistance(p1, p2);
}