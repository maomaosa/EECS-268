#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename T>
class queue
{
	private:
	node<T>* front;
	node<T>* back;
	
	public:
	queue();
	~queue();
	
	void enqueue(T entry);
	void dequeue();
	T peekfront() const ; 
	
	bool isempty() const ;
	
	
};

#include "queue.cpp"

#endif
