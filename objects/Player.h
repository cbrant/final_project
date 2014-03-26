/*
Player.h
Patrick Hansen
3/18/14
interface of Player object
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player {

	public:
		Player(string, int, int);
		
		void print();
		
	private:
		int power;
		int accuracy;
		string name;

};

#endif
