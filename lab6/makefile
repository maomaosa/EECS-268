lab6: main.o executive.o 
	g++ -std=c++11 -g -Wall main.o executive.o  -o lab6

main.o: main.cpp node.h node.cpp queue.h queue.cpp stack.h stack.cpp LinkedList.cpp LinkedList.h ListInterface.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.cpp executive.h
	g++ -g -Wall -std=c++11 -c executive.cpp

make clean:
	rm *.o *.csv lab6