all: main

main: main.o Disc.o Hole.o Player.o
	g++ main.o Disc.o Hole.o Player.o -o main
main.o: main.cpp Disc.h Hole.h Player.h
	g++ -c main.cpp
Disc.o: Disc.h Disc.cpp
	g++ -c Disc.cpp
Hole.o: Hole.h Hole.cpp
	g++ -c Hole.cpp
Player.o: Player.h Player.cpp
	g++ -c Player.cpp
clean:
	rm -f *.o main
