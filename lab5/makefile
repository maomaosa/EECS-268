lab5: main.o executive.o blobwalker.o
	g++ -std=c++11 -g -Wall main.o executive.o blobwalker.o -o lab5
executive.o:executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp
blobwalker.o:blobwalker.h blobwalker.cpp
	g++ -std=c++11 -g -Wall -c blobwalker.cpp

clean:
	rm *.o lab5