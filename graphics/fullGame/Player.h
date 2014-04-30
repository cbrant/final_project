/*
Player.h
Patrick Hansen
3/18/14
interface of Player object
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Disc.h"

using namespace std;

class Player {

	//see implementation for function explanations
	public:
		Player(string, int, int, string);
		void print();
		int getPower();
		int getAccuracy();
		string getSong();
		
	private:
		int power; //player's power, affects the initial velocity with which the disc is thrown
		int accuracy; //player's accuracy, affects the angle at which the disc is thrown
		string name; //name of player
		string song; //player's theme song
		
		//Disc disc;

};

#endif
