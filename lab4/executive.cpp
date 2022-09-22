/**
*
*@file executive.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab4
*@brief cpp file of executive class
*@date July.4/2021
*
**/

#include "executive.h"


executive::executive (std::string name)
{

	filename = name;

}

executive::~executive()
{
}

void executive::run()
{
	infile.open(filename);
	if (infile.is_open())
	{
		
		try
		{
			
			string command;
			
			while (infile >> command)
			{
				if (command == "NAVIGATE")
				{
					infile>>command;
					webpage.navigateTo(command);
				}
				else if (command == "HISTORY")
				{
					print();
				}
				else if (command == "FORWARD")
				{
					webpage.forward();
				}
				else if (command == "BACK")
				{
					webpage.back();
				}
			}
		}
		catch (std::exception& e)
		{
			cout << e.what() ;
		}
	}
	else
	{
		cout << "Invalid file or filename\n";
	}
}

void executive::print()
{
	webpage.current(); // check if it is empty, throw an error if it is empty.
	cout <<"Oldest";
	cout <<"\n===========";
	LinkedList<string> copylist;
	webpage.copyCurrentHistory(copylist);
	for (int i=0; i< copylist.getLength() ; i++)
	{
		cout << endl<<copylist.getEntry(i);
		if(copylist.getEntry(i) == webpage.current())
		{
			cout << "  <==current";
		}
	}
	cout << "\n===========";
	cout << "\nNewest\n\n";
}
			
		
			
			
			

