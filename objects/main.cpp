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
	
	int hole1[4] = {50, 100, -50, 50};
	
	Hole hole = Hole(150, -50, hole1);
	Disc disc;
	
//	cout << "\n\n";
//	player.print();
	cout << "\n\n";
//	hole.print();
//	cout << "\n\n";
//	disc.print();
//	cout << "\n\n";
	disc.letFly(30, 12.5, -19, player.getPower(), player.getAccuracy(), hole);
		disc.print();
	
	cout << "\n\n";

//	cout << "\n\n";
	disc.distFromHole(hole.getX(), hole.getY());
}
