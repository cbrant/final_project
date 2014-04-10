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
	Hole hole = Hole(150, 50);
	Disc disc;
	
	cout << "\n\n";
	player.print();
	cout << "\n\n";
	hole.print();
	cout << "\n\n";
	disc.print();
	cout << "\n\n";
	disc.letFly(15, 12.5, 19, player.getPower(), player.getAccuracy(), hole.getX(), hole.getY());
		disc.print();
	disc.letFly(10, 12.5, 19, player.getPower(), player.getAccuracy(), hole.getX(), hole.getY());
		disc.print();
	disc.letFly(5, 12.5, 19, player.getPower(), player.getAccuracy(), hole.getX(), hole.getY());
	cout << "\n\n";
	disc.print();
	cout << "\n\n";
	disc.distFromHole(hole.getX(), hole.getY());
}
