/*
Hole.h
Patrick Hansen
3/18/14
interface of Hole object
*/

#ifndef HOLE_H
#define HOLE_H

class Hole {
	
	//see implementation for function explanations
	public:
		
		Hole(int, int);
		
		void print();
		int getX();
		int getY();
		//void distFromHole(int, int); //prints distance from hole based on given current position
		
	private:
		int isHit; //bool to store whether or not the disc has contacted the hole
		int x; //hole's xpos
		int y; //hole's ypos
};

#endif
