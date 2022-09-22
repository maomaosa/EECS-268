#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "gamelist.h"
#include <string>


using namespace std;

class executive
{
	
	private:
	int size;
	gamelist* games = nullptr;
	
	
	
	
	
	public:
	executive(string filename);
	~executive();
	void print();
	void yearsgamesearch();
	void rankingrangesearch();
	void people_vs_Gibbons();
	void playtime_search();
	void run();
	
	
};

#endif