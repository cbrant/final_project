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
		
		void letFly(double, double);
		void print();
	
		//can we just use protected?
		double getX();
		double getY();
		double getVx();
		double getVy();
		
	private:
		double x; //xpos
		double y; //ypos
		double vx; //xvel
		double vy; //yvel
};

#endif
