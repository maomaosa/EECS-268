/**
*
*@file executive.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab3
*@brief this progam will contain a executive class to contain files and process the commands that read from the files
*@date June.28/2021
*
**/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "ShapeContainer.h"
#include "Shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class executive
{
	private:
	ifstream infile;
	string filename;
	ShapeContainer* prog;
	
	public:
	executive(string name);
	//@pre - it must contain the name of the file
	//@post - get the name of the file, initialize nullptr to the prog
	
	~executive();
	
	void run();
	//@pre - file must be opend successfully
	//@post - read the commands from the file and running it with the functions from the ShapeContainer class
	
};
#endif