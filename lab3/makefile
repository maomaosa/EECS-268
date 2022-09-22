
lab3: main.o executive.o ShapeContainer.o circle.o rectangle.o triangle.o
	g++ -std=c++11 -g -Wall main.o executive.o ShapeContainer.o circle.o rectangle.o triangle.o -o lab3

main.o: main.cpp executive.h Shape.h ShapeContainer.h circle.h rectangle.h triangle.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

ShapeContainer.o: ShapeContainer.h ShapeContainer.cpp
	g++ -std=c++11 -g -Wall -c ShapeContainer.cpp

circle.o: circle.h circle.cpp
	g++ -std=c++11 -g -Wall -c circle.cpp
	
rectangle.o: rectangle.h rectangle.cpp
	g++ -std=c++11 -g -Wall -c rectangle.cpp

triangle.o: triangle.h triangle.cpp
	g++ -std=c++11 -g -Wall -c triangle.cpp

make clean:
	rm *.o lab3