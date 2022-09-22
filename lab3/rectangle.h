/**
*
*@file rectangle.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab3
*@brief this progam will contain a rectangle class for contain *the area function and shapename function.
*@date June.28/2021
*
**/

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include <string>

using namespace std;

class rectangle: public Shape
{
	private:
	double length;
	double width;
	
	public:
	rectangle(double num1, double num2);
	//@post - contain the number of the length and width
	
	~rectangle();
	
	
	double area() const;
	//@pre - the length and width must be contained
	//@post - calculate the area of the reactangle, which is length*width
	//@return - return the calculated area
	
	string shapeName() const;
	//@return - return the shape name
	
};
#endif