/**
*
*@file executive.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab4
*@brief header file of executive class
*@date July.4/2021
*
**/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "ListInterface.h"
#include "LinkedList.h"
#include "BrowserHistoryInterface.h"
#include "BrowserHistory.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class executive
{
	private:
	ifstream infile;
	string filename;
	BrowserHistory webpage;
	
	
	public:
	executive(string name);
	//@pre - filename must be valid
	//@post - initializa the name for the file
	
	~executive();
	
	
	void run();
	//@pre - while the file is opened successfully 
	//@post - infile the command from the file and execitive the commads
	
	void print();
	//@post - funcition of printing the history 
	
	
	
};

#endif