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
	Hole hole = Hole(150, 50, 1);
	
	player.toss();

	disc.print();
	
	player.print();
	
	hole.print();
}
