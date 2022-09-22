/**
*
*@file main.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab5
*@brief main file
*@date July.13/2021
*
**/

#include "executive.h"
#include <stdexcept>
#include <iostream>


int main(int num, char** command)
{
	try
	{
		if(num<2)
		{
			throw(std::runtime_error("The file does not exist\n"));
		}
		else
		{
			executive prog(command[1]);
			prog.run();
		}
	}
	catch(std::exception& error)
	{
		std::cout <<error.what();
	}
	
	return 0;
}