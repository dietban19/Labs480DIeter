#include <iostream>
#include "point.h"
#include "square.h"

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