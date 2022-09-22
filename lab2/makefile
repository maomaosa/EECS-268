lab2:main.o node.o stack.o queue.o executive.o
	g++ -std=c++11 -g -Wall main.o node.o stack.o queue.o executive.o -o lab2
main.o:main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
node.o:node.h node.cpp
	g++ -std=c++11 -g -Wall -c node.cpp
stack.o:stack.h stack.cpp
	g++ -std=c++11 -g -Wall -c stack.cpp
queue.o:queue.h queue.cpp
	g++ -std=c++11 -g -Wall -c queue.cpp
executive.o:executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp
clean:
	rm *.o lab2