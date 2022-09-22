template <typename T>
queue<T>::queue()
{
	front = nullptr;
	back = nullptr;
}


template <typename T>
queue<T>::~queue()
{
	while(!isempty())
	{
		dequeue();
	}
}


template <typename T>
void queue<T>::enqueue(T entry)
{
	if(isempty())
	{
		node<T>* temp = new node<T>(entry);
		front = temp;
		back = temp;
	}
	else
	{
		node<T>* temp = new node<T>(entry);
		back->setnext(temp);
		back = back->getnext();
	}
}


template <typename T>
void queue<T>::dequeue()
{
	if(!isempty())
	{
		node<T>* temp = front;
		front = front -> getnext();
		if(front == nullptr)
		{
			back = nullptr;
			delete temp;
		}
		else
		{
			delete temp;
		}
	}
	else
	{
		throw (runtime_error("ERROR: empty queue\n"));
	}
	
}

template <typename T>
T queue<T>::peekfront() const
{
	return front->getentry();
}

template <typename T>
bool queue<T>::isempty() const
{
	if (front == nullptr && back == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}