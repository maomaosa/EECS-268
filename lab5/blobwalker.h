/**
*
*@file blobwalker.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab5
*@brief this is the header file for the blobwalker function
*@date July.13/2021
*
**/


#ifndef BLOBWALKER_H
#define BLOBWALKER_H

#include <iostream>

using namespace std;

class blobwalker
{
	private:
	int m_rangerow, m_rangecol;
	char** m_map = nullptr;
	int** marked = nullptr;
	int sewerrow, sewercol;
	
	
	
	public:
	
	
	blobwalker(int rangerow, int rangecol, char** map);
	/**
	*@pre rangerow,rangecol, startrow, startcol, map must be *included
	*@post initialize the rangerow, rangecol, startrow, *startcol and map
	*/
	
	
	~blobwalker();
	/**
	*@post clear the heap memory
	*/
	

	
	bool isvalid(int row, int col);
	/**
	*@pre the row and col must be contained before the *function
	*@post check if it is step is valid to go
	*@return return true for it is valid, else return false
	*/
	
	
	
	bool issewer(int row, int col);
	/**
	*@pre the row and col must be contained befre the 
	*function
	*@post check if it is a sewer
	*@return return true for a sewer, else return false
	*/
	
	
	void mark(int row, int col);
	/**
	*@pre the row and col must be contained befre the 
	*function
	*@post exchange the character of the passed 'S' into 'B'
	*/
	
	
	
	bool findsewer();
	/**
	*@pre the row and col of the start sewer
	*@post find the next sewer and keep moving
	*/
	
	
	
	
	bool move(int startrow, int startcol);
	/**
	*@pre rangerow,rangecol, startrow, startcol, map must be *included
	*@post the main function that using backtracking to move *the blob
	*@return reture ture for the function has been donw
	*/
	
	void print();
	/**
	*@post print the final map
	*/
	
};

#endif