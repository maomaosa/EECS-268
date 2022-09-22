#include "executive.h"
#include "gamelist.h"
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;



executive::executive(string filename)
{
	ifstream infile;
	infile.open(filename);
	if(infile.is_open())
	{
		infile >> size;
		games = new gamelist[size];
		string gamename;
		double gibbons_rating;
		double peoples_rating;
		int year_published;
		int min_players;
		int min_playtime;
		
		int times=0;//gamelist's times
		
		while (infile >> gamename >> gibbons_rating >> peoples_rating >> year_published >> min_players >> min_playtime)
		{
			games[times].setgname(gamename);
			games[times].setgrate(gibbons_rating);
			games[times].setprate(peoples_rating);
			games[times].setgyear(year_published);
			games[times].setminplayer(min_players);
			games[times].setmintime(min_playtime);
			times++;
		}
		
		run();
		
	}
	else
	{
		cout << "invalid file." << endl;
	}
}

executive::~executive()
{
	if (games != nullptr)
	{
		delete[] games;
	}
}

void executive::print()
{
	for(int i=0; i<size; i++)
	{
		cout<<games[i].getgname() <<"("<<games[i].getgyear()<<")[GR="<<games[i].getgrate()<<", PR="<<games[i].getprate()<<", MP="<<games[i].getminplayer()<<", MT"<<games[i].getmintime()<<"]\n";
	}
}

void executive::yearsgamesearch()
{
	int user_year=0;
	cout << "What's the year?\n";
	cin >> user_year;
	int check_times=0;
	for(int i=0; i<size; i++)
	{
		if (games[i].getgyear() == user_year)
		{
			cout<<games[i].getgname() <<"("<<games[i].getgyear()<<")[GR="<<games[i].getgrate()<<", PR="<<games[i].getprate()<<", MP="<<games[i].getminplayer()<<", MT"<<games[i].getmintime()<<"]\n";
			check_times++;
		}
	}
	
	if (check_times==0)
	{
		cout << "No games found\n";
	}
}
		
void executive::rankingrangesearch()
{
	double lower_range=0.0;
	double higher_range=0.0;
	int check_times=0;
	cout << "what's the lower rank?\n";
	cin>> lower_range ;
	cout << "what's the higher rank?\n";
	cin>> higher_range ;
	
	if(lower_range>=0 && higher_range<=10 && lower_range <= higher_range)
	{
		for(int i=0; i<size; i++)
		{
			if (lower_range<=games[i].getgrate() && higher_range >= games[i].getgrate())
			{
				cout<<games[i].getgname() <<"("<<games[i].getgyear()<<")[GR="<<games[i].getgrate()<<", PR="<<games[i].getprate()<<", MP="<<games[i].getminplayer()<<", MT"<<games[i].getmintime()<<"]\n";
				check_times++;
			}
		}
		
		if (check_times==0)
		{
		cout << "No games found\n";
		}
	}
	else
	{
		cout << "invalid value, please check it.\n";
	}
}

void executive::people_vs_Gibbons()
{
	double difference=0.0;
	int check_times=0;
	cout<<"Enter a number, it will show games that seperation ranger equal or bigger than that number.\n";
	cin >> difference;
	if(difference >= 0 && difference <= 10)
	{
		for(int i=0; i<size; i++)
		{
			if(abs(games[i].getgrate()-games[i].getprate()) >= difference)
			{
				cout<<games[i].getgname() <<"("<<games[i].getgyear()<<")[GR="<<games[i].getgrate()<<", PR="<<games[i].getprate()<<", MP="<<games[i].getminplayer()<<", MT"<<games[i].getmintime()<<"]\n";
				check_times++;
			}
		}
		if (check_times==0)
		{
		cout << "No games found\n";
		}
	}
	else
	{
		cout << "invalid value, please check it.\n";
	}
}

void executive:: playtime_search()
{
	int play_time=0;
	int check_times=0;
	cout << "what's the minimun time?\n";
	cin >> play_time;
	if (play_time >0)
	{
		for(int i=0; i<size; i++)
		{
			if (games[i].getmintime()>=play_time)
			{
				cout<<games[i].getgname() <<"("<<games[i].getgyear()<<")[GR="<<games[i].getgrate()<<", PR="<<games[i].getprate()<<", MP="<<games[i].getminplayer()<<", MT"<<games[i].getmintime()<<"]\n";
				check_times++;
			}
		}
		if (check_times==0)
		{
		cout << "No games found\n";
		}
	}
	else
	{
		cout << "invalid value, please check it.\n";
	}
}
		
	
				
	

void executive::run()
{
	while(1)
  {
    int choice;
    cout << "1. Print all games" << endl;
    cout << "2. Print all games from a certain year" << endl;
    cout << "3. Print based on ranking range" << endl;
    cout << "4. The People VS Dr.Gibbons" << endl;
    cout << "5. Print based on the play time" << endl;
    cout << "6. Exit" << endl;
    cin >> choice;
	
	if(choice==1)
	{
		print();
	}
	else if(choice==2)
	{
		yearsgamesearch();
	}
	else if (choice==3)
	{
		rankingrangesearch();
	}
	else if (choice==4)
	{
		people_vs_Gibbons();
	}
	else if (choice==5)
	{
		playtime_search();
	}
	else if(choice==6)
	{
		break;
	}
	else
	{
		cout<< "Invalid, choice again.\n";
	}
  }
  
}

	





















		