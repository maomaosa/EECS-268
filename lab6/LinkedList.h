/**
*
*@file LinkedList.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab4
*@brief the header file of LinkedList
*@date July.4/2021
*
**/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include "ListInterface.h"

template <typename T>
class LinkedList : public ListInterface<T>
{
	protected:
	node<T>* m_front;
	int m_length;
	
	public:
	LinkedList();
	//@post - set m_front = nullptr m_length = 0
	
	
	~LinkedList();
	//@post - clean the stack/heap memory
	
	

    /**
    * @pre The index is valid
    * @post The entry is added to the list at the index, increasing length by 1
    * @param index, position to insert at (1 to length+1)
    * @param entry, value/object to add to the list
    * @throw std::runtime_error if the index is invalid
    */
    void insert(int index, T entry);
	//@pre - index and entry must be valid
	//@post - insert the entry to the list

    /**
    * @pre The index is valid
    * @post The entry at given position is removed, reducing length by 1 
    * @param index, position to insert at (1 to length)
    * @throw std::runtime_error if the index is invalid
    */
    void remove(int index);
	//@pre - index must be valid
	//@Post - remve certain index with its entry from list
	
	

    /**
    * @pre The index is valid
    * @post None 
    * @param index, position to insert at (1 to length)
    * @throw std::runtime_error if the index is invalid
    */
    T getEntry(int index) const ;
	//@pre - index must be valid
	//@return - renturn entry for certain index

    /**
    * @pre None
    * @post None 
    */
    int getLength() const;
	//@return - return m_length
	

    /**
    * @pre None
    * @post List is empty
    * @throw None
    */
    void clear();
	//@post - deallocate the memory
	

    /**
    * @pre The index is valid (must already exist)
    * @post Given entry overrides the entry at the given index 
    * @param index, position to override at (1 to length)
    * @param entry, value/object to place at given index
    * @throw std::runtime_error if the index is invalid
    */
    void setEntry(int index, T entry);
	//@pre - index and entry must be valid
	//@post - replace the entry for certain index
	
};

#include "LinkedList.cpp"

#endif