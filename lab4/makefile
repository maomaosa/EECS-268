lab4: main.o BrowserHistory.o executive.o
	g++ -std=c++11 -g -Wall main.o BrowserHistory.o executive.o -o lab4
main.o: main.cpp BrowserHistoryInterface.h LinkedList.h LinkedList.cpp ListInterface.h node.h node.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
BrowserHistory.o: BrowserHistory.h BrowserHistory.cpp
	g++ -std=c++11 -g -Wall -c BrowserHistory.cpp
executive.o:executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp
	
clean:
	rm *.o lab4