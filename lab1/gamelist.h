#ifndef GAMELIST_H
#define GAMELIST_H
#include <string>


using namespace std;

class gamelist
{
	private:
	string g_name;
	double g_rate;
	double p_rate;
	int g_year;
	int min_player;
	int min_time;
	
	
	public:
	void setgname (string name);  //set
	void setgrate (double rate);
	void setprate (double rate);
	void setgyear (int year);
	void setminplayer (int num);
	void setmintime (int time);
	
	string getgname (); //get
	double getgrate ();
	double getprate ();
	int getgyear ();
	int getminplayer ();
	int getmintime ();
	
};
#endif
	
	