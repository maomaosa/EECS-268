/**
*
*@file node.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab4
*@brief node.h, header of the node
*@date July.4/2021
*
*/

#ifndef NODE_H
#define NODE_H

template <typename T>

class node
{
	private:
	T m_entry;
	node<T>* m_next;
	
	
	public:
	node(T entry);
	//@post - set entry to m_entry and set m_next ad nullptr
	
	void setentry(T entry);
	//@pre - it must get the entry
	//@post - get the entry and set the entry for m_entry
	
	T getentry() const;
	//@pre - m_entry must be setted
	//@post - return the value of m_entry
	//@return - return the value of m_entry
	
	void setnext(node<T>* next);
	//@pre - it must get the next node
	//@post - set the getted node  as the m_next
	
	node<T>* getnext() const;
	//@pre - m_next must be valid
	//@post - it returns the m_next
	//@return - it returns the node of m_next
	
	
};

#include "node.cpp"

#endif