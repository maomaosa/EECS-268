#include "queue.h"


queue::queue()
{
	front=nullptr;
	back=nullptr;
}

queue::~queue()
{
	node* temp = nullptr;
	while(front != nullptr)
	{
		temp = front->getnext();
		delete front;
		front = temp;
	}
		
	
}

void queue::enqueue(string name)
{
	if (front == nullptr && back == nullptr)
	{
		front = new node(name);
		back = front;
	}
	
	else
	{
		node* temp = new node(name);
		back->setnext(temp);
		back = back->getnext();
	}
}

void queue::dequeue()
{
	if (isempty())
	{
		throw (runtime_error("ERROR:empty queue\n"));
	}
	else
	{
		
		
			node* temp = front;
			front=front->getnext();
			if(front == nullptr)
			{
				back = nullptr;
				delete temp;
			}
			else
			{
				delete temp;
			}
		
	}
}

string queue::peekfront() const
{
	return front->getname();
}

bool queue::isempty() const
{
	if (front == nullptr && back == nullptr)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
 
	