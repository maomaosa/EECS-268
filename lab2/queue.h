#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
#include <string>
#include <stdexcept>
using namespace std;


class queue
{
	private:
	node* front;
	node* back;
	
	
	public:
	queue();
	~queue();
	void enqueue(string name); //add to the lsit
	void dequeue(); // delete from the first
	string peekfront() const;//get the first name
	bool isempty() const;
	
	
};

#endif