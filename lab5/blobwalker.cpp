/**
*
*@file blobwalker.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab5
*@brief function file of blobwalker
*@date July.13/2021
*
**/


#include "blobwalker.h"
using namespace std;

blobwalker::blobwalker(int rangerow, int rangecol, char** map)
{
	m_rangerow = rangerow;
	m_rangecol = rangecol;
	
	m_map = new char*[m_rangerow];
	for (int i=0; i<m_rangerow; i++)
	{
		m_map[i] = new char[m_rangecol];
	}
	
	for (int i=0; i<m_rangerow; i++)
	{
		for (int j =0; j<m_rangecol; j++)
		{
			m_map[i][j] = map[i][j];
		}
	}
	
	marked = new int*[m_rangerow];
	for (int i=0; i<m_rangerow; i++)
	{
		marked[i] = new int [m_rangecol];
	}
	
	for (int i=0; i<m_rangerow; i++)
	{
		for (int j =0; j<m_rangecol; j++)
		{
			marked[i][j] = 0;
		}
	}
	
}

blobwalker::~blobwalker()
{
	for(int i=0; i<m_rangerow; i++)
	{
		delete[] m_map[i];
	}
	delete[] m_map;
	
	for(int i=0; i<m_rangerow; i++)
	{
		delete[] marked[i];
	}
	delete[] marked;
}


bool blobwalker::isvalid(int row, int col)
{
	if(row >= m_rangerow || row <0 || col >= m_rangecol || col < 0)
	{
		return false;
	}
	if(marked[row][col] == 1 || marked[row][col] == 2)
	{
		return false;
	}
	if (m_map[row][col] == 'S')
	{
		return true;
	}
	if (m_map[row][col] == '#')
	{
		return false;
	}

	if (m_map[row][col] == '@')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool blobwalker::issewer(int row, int col)
{
	if(m_map[row][col] == '@')
	{
		return true;
	}
	else
	{
		return false;
	}
}


void blobwalker::mark(int row, int col)
{
	if(issewer(row, col))
	{
		marked[row][col] = 2;
	}
	else
	{
		marked[row][col] = 1;
	}
}


bool blobwalker::findsewer()
{
	
	for(int i=0; i< m_rangerow; i++)
	{
		for(int j=0; j<m_rangecol; j++)
		{
			if (m_map[i][j] == '@')
			{
				if(marked[i][j] == 0)
				{
					sewerrow = i;
					sewercol = j;
					return true;
				}
				else
				{
				}
			}
		}
	}
	return false;
}

bool blobwalker::move (int startrow, int startcol)
{
	
	mark(startrow, startcol);
	

	if ( isvalid ( startrow-1, startcol)) // up
	{
		move (startrow-1, startcol);
	}
	if (isvalid (startrow, startcol-1)) //left
	{
		move (startrow, startcol-1);
	}
	if (isvalid (startrow, startcol+1)) //right
	{
		move (startrow, startcol+1);
	}
	if (isvalid (startrow+1, startcol)) //down
	{
		move (startrow+1, startcol);
	}
	if (issewer(startrow, startcol ) && findsewer() )// sewer
	{
		findsewer();
		move (sewerrow, sewercol);
	}
	
		return true;
}
	
	
void blobwalker::print()
{
	for (int i =0; i< m_rangerow; i++)
	{
		for (int j=0; j<m_rangecol; j++)
		{
			if(marked[i][j] == 1)
			{
				std::cout << 'B';
			}
			else if(marked[i][j] == 2)
			{
				std::cout << '@';
			}
			else 
			{
				std::cout << m_map[i][j];
			}
		
		}
			std::cout <<std::endl;
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	