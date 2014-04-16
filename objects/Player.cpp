/*
Player.cpp
Patrick Hansen
3/18/14
implementation of Player object
*/

#include "Player.h"
#include <iostream>

using namespace std;

Player::Player (string n, int pow, int acc, string son) {
	name = n;
	power = pow;
	accuracy = acc;
	song = son;
}

int Player::getPower() {
	return power;
}

int Player::getAccuracy() {
	return accuracy;
}

void Player::print() {
	cout << "Printing player." << endl << "Player name: " << name << endl << "Power: " << power << " Accuracy: " << accuracy << endl;
	return;
}

