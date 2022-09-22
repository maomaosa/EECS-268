/**
*
*@file main.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab4
*@brief main.cpp it strats the program
*@date July.4/2021
*
**/
#include "executive.h"
#include <iostream>

int main(int num, char* command[])
{
	if (num< 2 )
    {
        std::cout << "ERROR: Invalid amount of arguments\n";
    }
    else
    {
        executive prog(command[1]);
		prog.run();
    }
    return 0;
	
}
