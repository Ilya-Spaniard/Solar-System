all: compile link

compile:
	g++ -Isrc/include -c Movement.hpp Planet.hpp main.cpp

link:
	g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system