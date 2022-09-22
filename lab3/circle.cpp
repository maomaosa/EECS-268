/**
*
*@file circle.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab3
*@brief this progam will contain the function of the circle class
*@date June.28/2021
*
**/


#include "circle.h"

circle::circle(double num)
{
	radius = num;
}

circle::~circle()
{
}

double circle::area() const
{
	double area;
	area = M_PI*radius*radius;
	return (area);
}

std::string circle::shapeName() const
{
	return ("circle");
}