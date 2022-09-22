/**
*
*@file BinaryNode.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab7
*@brief cpp file of the BinaryNode
*@date July.25/2021
*
*/


template <typename T>
BinaryNode<T>::BinaryNode(T entry)
{
	m_entry = entry;
	left_one = nullptr;
    right_one = nullptr;
}

template <typename T>
BinaryNode<T>::~BinaryNode()
{
	
}

template <typename T>
void BinaryNode<T>::setEntry(T entry)
{
	m_entry = entry;
}

template <typename T>
T BinaryNode<T>::getEntry() const
{
	return(m_entry);
}

template <typename T>
void BinaryNode<T>::setLeft(BinaryNode<T>* left_node)
{
	left_one = left_node;
}

template <typename T>
void BinaryNode<T>::setRight(BinaryNode<T>* right_node)
{
    right_one = right_node;
}

template <typename T>
BinaryNode<T>* BinaryNode<T>::getLeft() const
{
	return(left_one);
}


template <typename T>
BinaryNode<T>* BinaryNode<T>::getRight() const
{
	return(right_one);
}