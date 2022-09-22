/**
*
*@file triangle.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab3
*@brief this progam will contain a triangle class for contain *the area function and shapename function.
*@date June.28/2021
*
**/

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
#include <string>



class triangle: public Shape
{
	private:
	double base;
	double height;
	
	public:
	triangle(double num1, double num2);
	//@post - contain the number of the base and height
	
	~triangle();
	
	double area() const;
	//@pre - the base and height must be contained
	//@post - calculate the area of the reactangle, which is 0.5*base*height
	//@return - return the calculated area
	
	std::string shapeName() const;
	//@return - return the name of shape
};
#endif