/*
Hole.h
Patrick Hansen
3/18/14
interface of Hole object
*/

#ifndef HOLE_H
#define HOLE_H

class Hole {
	public:
		
		Hole(int, int, int);
		
	private:
		int isHit; //bool to store whether or not the disc has contacted the hole
		int x; //hole's xpos
		int y; //hole's ypos
		int h; //may include this or not...hole's height. (disc will have height calculated, so it could technically fly over the hole)
};

#endif
