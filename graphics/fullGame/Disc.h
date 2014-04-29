/*
Disc.h
Patrick Hansen
3/18/14
interface of Disc object
*/

#ifndef DISC_H
#define DISC_H

#include "Hole.h"
#include <iostream>

using namespace std;

class Disc {

	public:
		Disc();
		
		void letFly(double, double, int, int, int, Hole);
		void print();
		int checkHole(int, int);
		
		void calcXspot(int, double);
		void calcYspot(int, double);
		void distFromHole(int, int);
		string pickScreen(int);
	
		double getX();
		double getY();
		double getVx();
		double getVy();
		
	private:
		double x; //xpos
		double y; //ypos
		double z; //zpos (height)
		double vx; //xvel
		double vz; //zvel
};

#endif
