/*
Hole.h
Patrick Hansen
3/18/14
interface of Hole object
*/

#include "Hole.h"
#include <iostream>

using namespace std;

Hole::Hole(int X, int Y, int H) {
	x = X;
	y = Y;
	h = H;
	isHit = 0; //initially unhit
}

void Hole::print() {
	cout << "The hole is located " << x << " meters forward and " << y << " meters to the left/right" << endl;
	cout << "You are aiming for a hole that is " << h << " meters off of the ground" << endl;
}

int Hole::getX() {
	return x;
}

int Hole::getY() {
	return y;
}
