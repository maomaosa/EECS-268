#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "stack.h"
#include "queue.h"
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>

using namespace std;



class executive
{
	private:
	stack elevator;
	queue list;

	
	
	
	public:
	executive(string filename);
	void inspection();
	~executive();

	
	
};


#endif