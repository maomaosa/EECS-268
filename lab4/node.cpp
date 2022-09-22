/**
*
*@file node.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab4
*@brief the cpp file of the node header
*@date July.4/2021
*
**/


template <typename T>
node<T>::node(T entry)
{
	m_entry = entry;
	m_next=nullptr;
}

template <typename T>
void node<T>::setentry(T entry)
{
	m_entry = entry;
}

template <typename T>
T node<T>::getentry() const
{
	return(m_entry);
}

template <typename T>
void node<T>::setnext(node<T>* next)
{
	m_next = next;
}

template <typename T>
node<T>* node<T>::getnext() const
{
	return(m_next);
}
	