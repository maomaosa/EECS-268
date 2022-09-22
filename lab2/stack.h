#ifndef STACK_H
#define STACK_H
#include "node.h"
#include <stdexcept>
#include <string>
using namespace std;

class stack
{
	private:
	node* list;
	
	
	public:
	stack();
	~stack();
	void push(string name);//put one
	void pop();// dele the last one
	string peek() const;//show the list's last one
	bool isempty() const;
	
	
	
};

#endif