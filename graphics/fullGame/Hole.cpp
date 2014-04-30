/*
Hole.h
Patrick Hansen
3/18/14
interface of Hole object
*/

#include "Hole.h"
#include <iostream>

using namespace std;

//main constructor
Hole::Hole(int X, int Y) {
	x = X;
	y = Y;
	
	isHit = 0; //initially unhit
}

//print function for Hole object
void Hole::print() {
	cout << "Printing hole." << endl << "The hole is located " << x << " meters forward ";
	if(y < 0) {
		cout << "and " << y << " meters to the left." << endl;
	} else if(y > 0) {
		cout << "and " << y << " meters to the right." << endl;
	} else {
		cout << " DEAD AHEAD." << endl;
	}
	
	/*cout << "Threshold vals are : \n";
	for(int i = 0; i < 5; i++) {
		cout << thresholds[i] << " ";
	}
	
	cout << endl << endl;*/
}

//getter for x pos
int Hole::getX() {
	return x;
}

//getter for y pos
int Hole::getY() {
	return y;
}
