/**
*
*@file executive.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab6
*@brief this is the header file for the executive function
*@date July.19/2021
*
**/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H


#include <iostream>
#include <math.h>
#include <ctime>
#include <time.h>

#include <fstream>

#include "node.h"
#include "stack.h"
#include "queue.h"
#include "LinkedList.h"
#include "ListInterface.h"


using namespace std;

class executive
{
	private:
	int choice;
	ofstream outfile;
	
	public:
	
	executive();
	
	~executive();
	
	void makechoice();
	//@post - print the list of the choices and ask the user choose one to running
	
	void run();
	//@post - running the function
	
	void stack_pop();
	//@pre - while the choice is 1
	//@post - running the stack class and renturn the used time of pop() function for different amount of elements
	
	void stack_destructor();
	//@pre - while the choice is 2
	//@post - running the stack class and renturn the used time of destructor function of different amount of elements
	
	void queue_enqueue();
	//@pre - while the choice is 3
	//@post - running the queue class and renturn the used time of enqueue function of different amount of elements
	
	void LinkedList_getfirstentry();
	//@pre - while the choice is 4
	//@post - running the LinkedList class and renturn the used time of getentry function for the fisrt value of different amount of elements
	
	void LinkedList_getlastentry();
	//@pre - while the choice is 5
	//@post - running the LinkedList class and renturn the used time of getentry function for the last value of different amount of elements
	
	void LinkedList_print();
	//@pre - while the choice is 6
	//@post - running the LinkedList class and renturn the used time of getentry function for printing of different amount of elements
};

#endif
	
