start: main.o source.o
	g++ main.o locminreorder.o -o gotest

main.o: main.cpp
	g++ -c main.cpp

source.o: locminreorder.cpp locminreorder.h
	g++ -c locminreorder.cpp

go:
	clear
	./gotest
	rm *.o
	rm gotest
	ls
