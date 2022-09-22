/**
*
*@file executive.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab6
*@brief function file of the executive class
*@date July.19/2021
*
**/


#include "executive.h"
using namespace std;

executive::executive()
{
}

executive::~executive()
{
}


void executive::makechoice()
{
	cout << "1. Stack's pop" << endl;
    cout << "2. Stack's destructor" << endl;
    cout << "3. Queue's enqueue" << endl;
    cout << "4. Linked List getEntry at specifically index 1" << endl;
    cout << "5. Linked List getEntry at specifically the last index" << endl;
    cout << "6. Printing all elements in a LinkedList using getEntry" << endl;
    cout << "7. Fiish" << endl;
	cin >> choice;
}

void executive::run()
{
	while(1)
	{
		makechoice();
		
		if (choice == 1)
		{
			stack_pop();
		}
		else if (choice == 2)
		{
			stack_destructor();
		}
		else if (choice == 3)
		{
			queue_enqueue();
		}
		else if (choice == 4)
		{
			LinkedList_getfirstentry();
		}
		else if (choice == 5)
		{
			LinkedList_getlastentry();
		}
		else if (choice == 6)
		{
			LinkedList_print();
		}
		else if (choice == 7)
		{
			break;
		}
		else 
		{
			cout << "Invalid Choice\n";
			break;
		}
	}
}


void executive::stack_pop()
{
	stack<int> list ;
	
	clock_t before, after, diff;
	outfile.open("stack_pop.csv");
	for (int i = 1000 ; i<=100000; i=i+1000)
	{
		for ( int j = 1; j <= 1000; j++)
		{
			list.push(j);
		}
		before = clock();
		list.pop();
		after = clock();
		list.push(i);
		diff = after - before;
		cout << fixed;
		cout << "Pop took " << (int)diff << " ticks and ";
		cout << ((float)diff)/CLOCKS_PER_SEC << " seconds.\n";
		outfile << i<<','<<(int)diff <<endl;
	}
	outfile.close();
	
}

void executive::stack_destructor()
{
	stack<int> list;
	
	clock_t before, after, diff;
	outfile.open("stack_destructor.csv");
	for (int i = 1000 ; i<=100000; i=i+1000)
	{
		for ( int j = 1; j <= i; j++)
		{
			list.push(j);
		}
		before = clock();
		list.~stack();
		after = clock();
		diff = after - before;
		cout << fixed;
		cout << "Destructor took " << (int)diff << " ticks and ";
		cout << ((float)diff)/CLOCKS_PER_SEC << " seconds.\n";
		outfile << i<<','<<(int)diff <<endl;
	}
	outfile.close();
}

void executive::queue_enqueue()
{
	queue<int> list;
	
	clock_t before, after, diff;
	outfile.open("queue_enqueue.csv");
	for (int i = 1000 ; i<=100000; i=i+1000)
	{
		for ( int j = 1; j <= 999; j++)
		{
			list.enqueue(j);
		}
		before = clock();
		list.enqueue(0);
		after = clock();
		diff = after - before;
		cout << fixed;
		cout << "Enqueue took " << (int)diff << " ticks and ";
		cout << ((float)diff)/CLOCKS_PER_SEC << " seconds.\n";
		outfile << i<<','<<(int)diff <<endl;
	}
	outfile.close();
}


void executive::LinkedList_getfirstentry()
{
	LinkedList<int> list;
	
	clock_t before, after, diff;
	outfile.open("LinkedList_getfirstentry.csv");
	for (int i = 0 ; i<100000; i=i+1000)
	{
		for ( int j = 1; j <=1000; j++)
		{
			list.insert(j+i-1,j+i);
		}
		before = clock();
		list.getEntry(1);
		after = clock();
		diff = after - before;
		cout << fixed;
		cout << "GetEntry at specifically index 1 took " << (int)diff << " ticks and ";
		cout << ((float)diff)/CLOCKS_PER_SEC << " seconds.\n";
		outfile << i+1000<<','<<(int)diff <<endl;
	}
	outfile.close();
}
	

void executive::LinkedList_getlastentry()	
{
	LinkedList<int> list;
	
	clock_t before, after, diff;
	outfile.open("LinkedList_getlastentry.csv");
	for (int i = 0 ; i<100000; i=i+1000)
	{
		for ( int j = 1; j <=1000; j++)
		{
			list.insert(j+i-1,j+i);
		}
		before = clock();
		list.getEntry(i+999);
		after = clock();
		diff = after - before;
		cout << fixed;
		cout << "GetEntry at last index took " << (int)diff << " ticks and ";
		cout << ((float)diff)/CLOCKS_PER_SEC << " seconds.\n";
		outfile << i+1000<<','<<(int)diff <<endl;
	}
	outfile.close();
}


void executive::LinkedList_print()
{
	LinkedList<int> list;
	
	clock_t before, after, diff;
	outfile.open("LinkedList_print.csv");
	for (int i = 0 ; i<100000; i=i+1000)
	{
		for ( int j = 1; j <=1000; j++)
		{
			list.insert(j+i-1,j+i);
		}
		before = clock();
		for (int k=0; k<=i+999; k++)
		{
			cout << list.getEntry(k) <<endl;
		}
		after = clock();
		diff = after - before;
		cout << fixed;
		cout << "Print all elements took " << (int)diff << " ticks and ";
		cout << ((float)diff)/CLOCKS_PER_SEC << " seconds.\n";
		outfile << i+1000<<','<<(int)diff <<endl;
	}
	outfile.close();
}
		
		
		
		
		