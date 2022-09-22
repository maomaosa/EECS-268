/**
*
*@file executive.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab5
*@brief function file of blobwalker
*@date July.13/2021
*
**/

#include "executive.h"
using namespace std;

executive::executive(string name)
{
	filename = name;
}

executive::~executive()
{
	if(map != nullptr)
	{
		for (int i=0; i<numRows; i++)
		{
			delete[] map[i];
		}
		delete[] map;
	}
}

void executive::run()
{
	infile.open(filename);
	if (infile.is_open())
	{
		infile >> numRows >> numCols >> startRow >> startCol;
		
		if (numRows < 1) // throw the error
		{
			throw(std::runtime_error("The range of Rows is too small\n"));
		}
		
		if (numCols < 1)
		{
			throw(std::runtime_error("The range of Cols is too small\n"));
		}
		
		if (startRow >= numRows || startCol >= numCols || startRow <0 || startCol < 0)
		{
			throw(std::runtime_error("The start point is not within range\n"));
		}
		
		map = new char*[numRows]; // initialize and inflie the map
		for (int i=0; i< numRows; i++)
		{
			map[i] = new char[numCols];
		}
		
		for (int i=0; i<numRows; i++)
		{
			for (int j=0; j<numCols; j++)
			{
				infile >> map[i][j];
			}
		}
		
		blobwalker ablob(numRows, numCols, map);
		ablob.move(startRow, startCol);
		
		
		
		cout << numRows <<' ' <<numCols <<'\n'; //print
		cout << startRow<<' ' <<startCol <<'\n';
		ablob.print();
		
	}
	else
	{
		throw(std::runtime_error ("Invalid file\n"));
	}
	
}