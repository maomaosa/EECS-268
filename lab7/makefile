lab7: main.o pokemon.o executive.o
	g++ -std=c++11 -g -Wall main.o pokemon.o executive.o -o lab7
main.o: main.cpp BinaryNode.h BinaryNode.cpp BinarySearchTreeInterface.h BST.h BST.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
pokemon.o: pokemon.cpp
	g++ -std=c++11 -g -Wall -c pokemon.cpp
executive.o: executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp
clean:
	rm *.o lab7