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
#include <cstdlib>

using namespace std;

int main(void) {
	Player player = Player("Jimmy Mickle", 4, 4);
	Hole hole = Hole(150, 50, 1);
	cout << "\n\n";
	player.print();
	cout << "\n\n";
	player.toss(hole.getX(), hole.getY());
	
	cout << "\n\n";

	
	//hole.print();
}
