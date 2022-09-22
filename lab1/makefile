lab1:main.o executive.o gamelist.o
	g++ -std=c++11 -g -Wall main.o executive.o gamelist.o -o lab1
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
executive.o: executive.h
	g++ -std=c++11 -g -Wall -c executive.cpp
gamelist.o: gamelist.h
	g++ -std=c++11 -g -Wall -c gamelist.cpp
clean:
	rm *.o lab1
