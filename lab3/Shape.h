/**
*
*@file Shape.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab3
*@brief this progam will contain a Shale class for the interface.
*@date June.28/2021
*
**/

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
class Shape
{
   public:
   virtual double area() const = 0;
   virtual std::string shapeName() const = 0;
   virtual ~Shape() {}
};

#endif