/*
main.cpp
Patrick Hansen
3/27/14
purp: for testing the objectes
*/

#include "Disc.h"
#include "Hole.h"
#include "Player.h"
#include <iostream>

using namespace std;

int main(void) {
	Disc disc;
	Player player = Player("Jimmy Mickle", 3, 5);
	Hole hole = Hole(150, 50, 5);
	
	disc.letFly(14, 12.5);
	disc.print();
	
	player.print();
	
	hole.print();
}
