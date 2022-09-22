/**
*
*@file BinaryNode.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab7
*@brief header file of the BinaryNode.cpp
*@date July.25/2021
*
*/

#ifndef BINARYNODE_H
#define BINARYNODE_H

template <typename T>

class BinaryNode
{
	private:
	T m_entry;

	BinaryNode<T>* left_one;
    BinaryNode<T>* right_one;
	
	
	public:
	BinaryNode(T entry);
	//@post - set entry to m_entry and set left_one and right_one


	~BinaryNode();
	
	
	void setEntry(T entry);
	//@pre - it must get the entry
	//@post - get the entry and set the entry for m_entry
	
	T getEntry() const;
	//@pre - m_entry must be setted
	//@post - return the value of m_entry
	//@return - return the value of m_entry
	
	void setLeft(BinaryNode<T>* left_node);
	//@pre - it must get the left node
	//@post - set the getted node  as the left_one

    void setRight(BinaryNode<T>* right_node);
	//@pre - it must get the right node
	//@post - set the getted node  as the right_one
	
	BinaryNode<T>* getLeft() const;
	//@pre - left_one must be valid
	//@post - it returns left_one
	//@return - it returns the node of left_one

    BinaryNode<T>* getRight() const;
	//@pre - right_one must be valid
	//@post - it returns right_one
	//@return - it returns the node of right_one
	
	
};

#include "BinaryNode.cpp"

#endif