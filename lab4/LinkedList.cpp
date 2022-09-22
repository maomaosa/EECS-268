/**
*
*@file LinkedList.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab4
*@brief LinkedList.cpp file for the LinkedList header file
*@date July.4/2021
*
**/


template <typename T>
LinkedList<T> :: LinkedList()
{
	m_front = nullptr;
	m_length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template <typename T>
T LinkedList<T>::getEntry(int index) const
{
	node<T>* temp = m_front;
	if(m_front == nullptr)
	{
		throw (std::runtime_error ("The list is empty\n"));
	}
	
	if( index >= 0 && index <= m_length-1)
	{
		
		for(int i = 0; i < index; i++)
		{
			temp = temp->getnext();
		}
		return (temp->getentry());
	}
	
	else
	{
		throw (std::runtime_error("Invalid Index\n"));
	}
	
}

template <typename T>
void LinkedList<T>::insert(int index, T entry)
{
	node<T>* nodebeforetarget = m_front;
	node<T>* nodeaftertarget = m_front;
	
	if(index >= 0 && index <= m_length)
	{
		if(index == 0)
		{
			node<T>* temp = new node<T>(entry);
			if(m_front == nullptr)
			{
				m_front=temp;
			}
			else
			{
				temp->setnext(m_front);
				m_front = temp;
			}
			m_length ++;
		}
		else if(index == m_length+1)
		{
			node<T>* temp = new node<T>(entry);
			for(int i =1; i < m_length; i++)
			{
				nodebeforetarget = nodebeforetarget->getnext();
			}
			nodebeforetarget->setnext(temp);
			m_length ++;
		}
		else
		{
			node<T>* temp = new node<T>(entry);
			for(int i = 0; i < index-1; i++)
			{
				nodebeforetarget = nodebeforetarget->getnext();
			}
			for(int i = 0; i < index; i++)
			{
				nodeaftertarget = nodeaftertarget->getnext();
			}
			nodebeforetarget->setnext(temp);
			temp->setnext(nodeaftertarget);
			m_length ++;
		}
	}
	else
	{
		throw (std::runtime_error("Invalid Index\n"));
	}
}

template <typename T>
void LinkedList<T>::remove(int index)
{
	node<T>* nodebeforetarget = m_front;
	node<T>* nodeaftertarget = m_front;
	if(index >= 0 && index <= m_length-1)
	{
		if (index == 0)
		{
			nodeaftertarget = m_front->getnext();
			
			if (nodeaftertarget == nullptr)
			{
				delete m_front;
				m_front = nullptr;
				m_length --;
			}
			else
			{
				delete m_front;
				m_front = nodeaftertarget;
				m_length --;
			}
		}
		else
		{
			for(int i = 0; i < index-1; i++)
			{
				nodebeforetarget = nodebeforetarget->getnext();
			}
			for(int i =0; i< index+1; i++)
			{
				nodeaftertarget = nodeaftertarget->getnext();
			}
			
			node<T>* temp = nodebeforetarget->getnext();
			nodebeforetarget->setnext(nodeaftertarget);
			delete temp;
			
			m_length --;
		}
	}
	else
	{
		throw (std::runtime_error("Invalid Index\n"));
	}
}

template <typename T>
void LinkedList<T>::clear()
{
	while(m_front != nullptr)
	{
		remove (0);

	}
}
	

template <typename T>
int LinkedList<T>::getLength () const
{
	return(m_length);
}

template <typename T>
void LinkedList<T>::setEntry(int index, T entry)
{
	node<T>* nodebeforetarget = m_front;
	node<T>* nodeaftertarget = m_front;
	if(index >= 0 && index <= m_length-1)
	{
		node<T>* target = new node<T>(entry);
		
		if(index == 0)
		{
			nodeaftertarget = nodeaftertarget->getnext();
			delete m_front;
			target->setnext(nodeaftertarget);
			m_front = target;
		}
		else
		{
			for(int i = 0; i < index-1; i++)
			{
				nodebeforetarget = nodebeforetarget->getnext();
			}
			for(int i =0; i< index+1; i++)
			{
				nodeaftertarget = nodeaftertarget->getnext();
			}
			node<T>* temp = nodebeforetarget->getnext();
			delete temp;
			nodebeforetarget->setnext(target);
			target->setnext(nodeaftertarget);
		}
	}
	else
	{
		throw (std::runtime_error("Invalid Index\n"));
	}
	
}