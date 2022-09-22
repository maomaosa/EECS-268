/**
*
*@file executive.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab3
*@brief this progam will contain functiond for the executive class
*@date June.28/2021
*
**/
#include "executive.h"

executive::executive(string name)
{
	filename = name;
	prog = nullptr;
}

executive::~executive()
{
	if(prog != nullptr)
	{
		
		delete prog;
	}
}

void executive::run()
{
	string command;
	int size;
	int index;
	double num1, num2;
	
	infile.open(filename);
	if (infile.is_open())
	{
			
		infile >> size;
		prog = new ShapeContainer(size);
		while (infile >> command)
		{
			try
			{
				
				if(command == "ADD")
				{
					infile>> index;
					infile >> command;
					if(command == "CIR")
					{
						infile >> num1;
						Shape* shape = new circle(num1);
						prog->add(shape, index);
					}
					else if (command == "TRI")
					{
						infile >> num1;
						infile >> num2;
						Shape* shape = new triangle(num1, num2);
						prog->add(shape, index);
					}
					else if (command == "REC")
					{
						infile>>num1;
						infile>>num2;
						Shape* shape = new rectangle(num1, num2);
						prog->add(shape, index);
					}
				}
				else if (command == "DELETE")
				{
					infile >> index;
					prog->remove(index);
				}
				else if (command == "PRINT")
				{
					infile>> index;
					cout << "Shape at index " <<index<<": "<<prog->shapeName(index)<<" area = " <<prog->area(index)<<endl;
			}
			else if (command == "EXIT")
			{
				cout << "Exiting...\n";
				break;
			}
			
			}
			
			catch (exception& error)
			{
				cout << error.what();
			}
		}
	}
}
			