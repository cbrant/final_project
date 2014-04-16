all: Player.o Disc.o Hole.o fullGame

fullGame: fullGame.cpp Player.o Disc.o Hole.o
	g++ fullGame.cpp Player.o Disc.o Hole.o -o fullGame -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
Player.o: Player.cpp
	g++ -c Player.cpp 
Disc.o: Disc.cpp
	g++ -c Disc.cpp 
Hole.o: Hole.cpp
	g++ -c Hole.cpp 
	
clean:
	rm *.o *~ fullGame
