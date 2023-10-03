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

class CurveCut : public Circle, public Rectangle
{
}
#endif