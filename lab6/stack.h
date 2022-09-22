#ifndef STACK_H
#define STACK_H
#include "node.h"
#include <stdexcept>

using namespace std;

template <typename T>

class stack
{
	private:
	node<T>* list;
	
	
	public:
	stack();
	~stack();
	void push(T entry);//put one
	void pop();// dele the last one
	T peek() const;//show the list's last one
	bool isempty() const;
	
	
	
};

#include "stack.cpp"

#endif