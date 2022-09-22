
template <typename T>
stack<T>::stack()
{
	list = nullptr;
}


template <typename T>
stack<T>::~stack()
{
	node<T>* temp;
	while(list!=nullptr)
	{
		temp = list->getnext();
		delete list;
		list = temp;
	}
	
}


template <typename T>
void stack<T>::push(T entry)
{
	node<T>* temp = new node<T>(entry);
	temp->setnext(list);
	list=temp;
}


template <typename T>
void stack<T>::pop()
{
	if(!isempty())
	{
		node<T>*temp = list->getnext();
		delete list;
		list = temp;
	}
	
	else
	{
		throw (runtime_error("ERROR: empty stack\n"));
	}
}


template <typename T>
T stack<T>::peek() const
{
	return(list->getname());
}


template <typename T>
bool stack<T>::isempty() const
{
	if(list == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}