/**
*
*@file BrowserHistory.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab4
*@brief the function file of BrowserHistory class
*@date July.4/2021
*
**/


#include "BrowserHistory.h"


BrowserHistory::BrowserHistory()
{
	webpage = new LinkedList<std::string>();
	length = 0;
	m_current = 0;
}

BrowserHistory::~BrowserHistory()
{
	delete webpage;
	
}

void BrowserHistory::navigateTo(std:: string url)
{
	if(length == m_current)
	{
		webpage->insert(length, url);
		length++;
		m_current++;
	}
	else
	{
		if(length == 0)
		{
			webpage->insert(length, url);
			length++;
			m_current++;
		}
		else
		{
			int time = length - m_current;
			for(int i =0; i<time; i++)
			{
				webpage->remove(length-1);
				length --;
			}
			webpage->insert(length,url);
			length++;
			m_current++;
		}
	}
			
}

void BrowserHistory::forward()
{
	if(length == 0)
	{
		throw (std::runtime_error("Empty List!\n"));
	}
	if(m_current == length)
	{
	}
	else
	{
		m_current ++;
	}
}

void BrowserHistory::back()
{
	if(length == 0)
	{
		throw (std::runtime_error("Empty List!\n"));
	}
	if(m_current == 1)
	{
	}
	else
	{
		m_current --;
	}
}

std::string BrowserHistory::current() const
{
	if(length == 0)
	{
		throw (std::runtime_error("Empty List!\n"));
	}
	
	return(webpage->getEntry(m_current-1));
}


void BrowserHistory::copyCurrentHistory(ListInterface<std::string>& destination)
{
	if(length == 0)
	{
		throw (std::runtime_error("Empty List!\n"));
	}
	
	
	int temp = length-1;
	for(int i =0; i<length; i++)
	{
		destination.insert(0,webpage->getEntry(temp));
		temp--;
	}
}
	










