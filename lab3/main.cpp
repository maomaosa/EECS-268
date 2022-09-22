/**
*
*@file main.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab3
*@brief main.cpp
*@date June.28/2021
*
**/
#include "executive.h"
#include <iostream>
using namespace std;


int main(int num, char** command)
{
	if (num<2)
	{
		cout << "Incorrect number of paremeters!\n";
	}
	else
	{
		executive prog(command[1]);
		prog.run();
	}
	
	return 0;
}
	