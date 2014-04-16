/*
Hole.h
Patrick Hansen
3/18/14
interface of Hole object
*/

#include "Hole.h"
#include <iostream>

using namespace std;

Hole::Hole(int X, int Y, int *arr) {
	x = X;
	y = Y;
	
	int i;
	for(i = 0; i < 5; i++) {
		thresholds[i] = arr[i];
	}
	
	isHit = 0; //initially unhit
}

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

int Hole::getX() {
	return x;
}

int Hole::getY() {
	return y;
}

int* Hole::getThresh() {
	return thresholds;
}
