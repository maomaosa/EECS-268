#include "node.h"


node::node(string name)
{
	list = name;
	next = nullptr;
}

void node::setname(string name)
{
	list = name;
}

string node::getname()
{
	return(list);
}

void node::setnext(node* nextone)
{
	next=nextone;
}

node* node::getnext()
{
	return(next);
}
