main: main.o Disc.o Hole.o Player.o
	g++ main.o Disc.o Hole.o Player.o -o main
main.o: main.cpp Disc.h Hole.h Player.h
	g++ -c main.cpp
Disc.o: Disc.h
	g++ -c Disc.cpp
Hole.o: Hole.h
	g++ -c Hole.cpp
Player.o: Player.h
	g++ -c Player.cpp
clean:
	rm -f *.o main
