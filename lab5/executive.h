/**
*
*@file executive.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab5
*@brief this is the header file for the executive function
*@date July.13/2021
*
**/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "blobwalker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

class executive
{
	private:
	int numRows, numCols, startRow, startCol;
	string filename;
	ifstream infile;
	char** map = nullptr;
	
	public:
	
	executive(string name);
	/**
	*@pre the filename must be included before the function
	*@post initialize the filename
	*/
	
	
	~executive();
	
	
	
	void run();
	/**
	*@post check if the file is opend successfully, then *running the program
	*/
	
	
};


#endif