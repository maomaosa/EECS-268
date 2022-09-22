/**
*
*@file triangle.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab3
*@brief this progam will contain functions of the triangle class
*@date June.28/2021
*
**/
#include "triangle.h"

triangle::triangle(double num1, double num2)
{
	base = num1;
	height = num2;
}

triangle::~triangle()
{
}

double triangle::area() const
{

	return (0.5 * base * height);
}

std::string triangle::shapeName() const
{
	return ("triangle");
}