/*
Player.cpp
Patrick Hansen
3/18/14
implementation of Player object
*/

#include "Player.h"
#include <iostream>

using namespace std;

Player::Player (string n, int pow, int acc) {
	name = n;
	power = pow;
	accuracy = acc;
}

void Player::print() {
	cout << "Player name: " << name << endl << "Power: " << power << " Accuracy: " << accuracy << endl;
}
