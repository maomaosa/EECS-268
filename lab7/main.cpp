/**
*
*@file main.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab7
*@brief main file
*@date July.27/2021
*
*/

#include <iostream>
#include <stdexcept>
#include "executive.h"

using namespace std;


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
        }
    }
    catch(std::exception& error)
	{
		std::cout <<error.what();
	}


    return 0;
}
