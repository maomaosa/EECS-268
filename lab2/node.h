#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;


class node
{
	private:
	string list;
	node* next;
	
	
	public:
	node(string name);
	void setname(string name);
	string getname();
	void setnext(node* nextone);
	node* getnext();
	
	
};

#endif