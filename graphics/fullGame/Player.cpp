/*
Player.cpp
Patrick Hansen
3/18/14
implementation of Player object
*/

#include "Player.h"
#include <iostream>

using namespace std;

//main constructor
Player::Player (string n, int pow, int acc, string son) {
	name = n;
	power = pow;
	accuracy = acc;
	song = son;
}

//getter for power
int Player::getPower() {
	return power;
}

//getter for accuracy
int Player::getAccuracy() {
	return accuracy;
}

//print function for Player object
void Player::print() {
	cout << "Printing player." << endl << "Player name: " << name << endl << "Power: " << power << " Accuracy: " << accuracy << endl;
	return;
}

//getter for song
string Player::getSong() {
	return song;
}
