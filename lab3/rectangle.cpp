/**
*
*@file rectangle.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab3
*@brief this progam will contain functions for the rectangle class
*@date June.28/2021
*
**/

#include "rectangle.h"


rectangle::rectangle(double num1, double num2)
{
	length = num1;
	width = num2;
}

rectangle::~rectangle()
{
}

double rectangle::area() const
{
	double area = length*width;
	return (area);
}

string rectangle::shapeName() const
{
	return ("rectangle");
}