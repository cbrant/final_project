/*
Disc.h
Patrick Hansen
3/18/14
interface of Disc object
*/

#ifndef DISC_H
#define DISC_H

class Disc {

	public:
		Disc();
		
		void letFly(double, double, int, int, int, int , int);
		void print();
		int checkHole(int, int);
		
		void calcXspot(int);
		void calcYspot(int);
		void distFromHole(int, int);
	
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
