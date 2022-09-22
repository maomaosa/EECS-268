/**
*
*@file circle.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab3
*@brief this progam will contain a circle class for contain the *area function and shapename function.
*@date June.28/2021
*
**/

#ifndef CIRCLR_H
#define CIRCLR_H
#include "Shape.h"
#include <string>
#include <math.h>


class circle : public Shape
{
	private:
	double radius;
	
	public:
	circle(double num);
	//@post- contain the radius for the circle
	
	~circle();
	
	
	double area() const;
	//@pre - radius must be contained
	//@post - claculate the area of circle which is M_PI*radius*radius
	//@return - return the calculated area
	
	std::string shapeName() const;
	//@return - return the name of shape
};
#endif
	