#include "executive.h"



executive::executive(string filename)
{
	
	ifstream infile;
	infile.open(filename);
	string command;
	int num;
	if(infile.is_open())
	{
		try
		{
			while(infile >> command)
			{
				if(command == "WAIT")
				{
					infile>> command;
					list.enqueue(command);
				}
				else if(command == "INSPECTION")
				{
					inspection();
				}
				else if (command == "PICK_UP")
				{
					infile>>num;
					for(int i=0; i<num; i++)
					{
						
						if(!list.isempty())
						{
						
							elevator.push(list.peekfront());
							list.dequeue();
						}
						else
						{
							list.dequeue();
						}
						
						
					}
				
				}
				else if (command == "DROP_OFF")
				{
					infile>>num;
					for (int i =0; i<num; i++)
					{
						
						elevator.pop();
					}
				}
				else
				{
					
				}
			}
		}
			
		catch (exception& error)
		{
			cout <<"Something wrong!\n";
				cout <<error.what();
		}
		
				
		
	}
	else
	{
		cout <<"Invalid file\n";
	}
}

executive::~executive()
{

	
	
}


void executive::inspection()
{
	cout<<"Elevator status:\n";
	if(elevator.isempty())
	{
		cout<< "The elevator is empty.\n";
	}
	else
	{
		cout<< "The elevator is not empty.\n";
	}
	if(elevator.isempty())
	{
		cout << "No one is in the elevator.\n";
	}
	else
	{
		cout << elevator.peek() << " will be the next person to leave the elevator.\n";
	}
	if(list.isempty())
	{
		cout << "No one is in line for the elevator.\n" ;
	}
	else
	{
		cout << list.peekfront() <<" will be the next person to get on the elevator.\n";
	}
}
