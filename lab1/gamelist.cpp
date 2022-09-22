#include "gamelist.h"
using namespace std;


	void gamelist::setgname (string name)
	{
		g_name=name;
	}
	
	void gamelist::setgrate (double rate)
	{
		g_rate=rate;
	}
	
	void gamelist::setprate (double rate)
	{
		p_rate=rate;
	}
	
	void gamelist::setgyear (int year)
	{
		g_year=year;
	}
	
	void gamelist::setminplayer (int num)
	{
		min_player=num;
	}
	
	void gamelist::setmintime (int time)
	{
		min_time=time;
	}
	
	//
	
	string gamelist::getgname ()
	{
		return g_name;
	}
	
	double gamelist::getgrate ()
	{
		return g_rate;
	}
	
	double gamelist::getprate ()
	{
		return p_rate;
	}
	
	int gamelist::getgyear ()
	{
		return g_year;
	}
	
	int gamelist::getminplayer ()
	{
		return min_player;
	}
	
	int gamelist::getmintime ()
	{
		return min_time;
	}
	
	
	
	
	
	
	
