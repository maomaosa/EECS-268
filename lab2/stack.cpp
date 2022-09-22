#include "stack.h"


stack::stack()
{
	list = nullptr;
}

stack::~stack()
{
	node* temp;
	while(list!=nullptr)
	{
		temp = list->getnext();
		delete list;
		list = temp;
	}
	
}

void stack::push(string name)
{
	node* temp = new node(name);
	temp->setnext(list);
	list=temp;
}

void stack::pop()
{
	if(!isempty())
	{
		node*temp = list->getnext();
		delete list;
		list = temp;
	}
	
	else
	{
		throw (runtime_error("ERROR: empty stack\n"));
	}
}

string stack::peek() const
{
	return(list->getname());
}

bool stack::isempty() const
{
	if(list == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}