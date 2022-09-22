/*
Author: Yuyang Fan
KUid： 3022608
Filename:main.cpp
Assignment: EECS268 LAB2
Date: June 22 2021
*/
#include "executive.h"
#include <iostream>

using namespace std;

int main(int num, char* command[])
{
	if(num !=2)
	{
		cout << "Incrrect number of parameters!\n";
	}
	else
	{
		executive run(command[1]);
	}
	
	return 0;
}