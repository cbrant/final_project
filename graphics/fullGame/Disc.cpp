/*
Disc.cpp
Patrick Hansen
3/18/14
implemenation of Disc object
*/

#include "Disc.h"
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

//constructor
Disc::Disc() {
	x = 0;
	y = 0;
	z = 1;
	vx = 0;
	vz = 0;
}

//function that animates the flight of the disc with actual physics
void Disc::letFly(double power, double uAlpha, int throwAngle,  int playerPower, int playerAccuracy, Hole hole) {
	
	//get random seed
	srand(time(NULL));
	double random = ((rand()%4) * 1.0 - 1.5)*(6 - playerAccuracy);
	//cout << "Random is " << random << endl;
	
	//adjusting power and alpha based on Player's attributes
	double adjPower = (double)playerPower - 3.0 + power; //average power will result in same as powerbar
	double alpha = uAlpha + random;//angle of attack, specified by user, modified by player accuracy

	//cout << "Alpha with the randFactor is " << alpha << endl;
	
	double dist = 0;
	//x = 0; //x position (m)
	z = 1; //y position (m)
	vx = cos(uAlpha*M_PI/180)*adjPower; //x velocity (m/s)
	vz = sin(uAlpha*M_PI/180)*adjPower; //y velocity (m/s)
	float g = -9.81; //acceleration due to gravity 
	float m = 0.175; //mass of disc (kg)
	float rho = 1.23; //density of fluid--air (kg/m^3)
	float area = 0.0568; //area of disc (m^2)
	float cl0 = 0.1; //lift coefficient at alpha = 0
	float clA = 1.4; //lift coefficient dependent on alpha
	float cd0 = 0.08; //drag coefficient at alpha = 0
	float cdA = 2.72; //drag coefficient dependent on alpha
	int alpha0 = -4;
	double deltavx; //change in vx
	double deltavz; //change in vz
	double pi = M_PI; //pi
		
	//calculate coefficients of lift and drag
	double cl = cl0 + clA*alpha*pi/180; 
	double cd = pow(cd0 + cdA*((alpha + alpha0)*pi/180),2.0);
	
	//loop variables
	float dt = 0.01;
	int count = 0; //loop iteration count

	while (z > 0) {
		
		deltavx = -rho*pow(vx,2.0)*area*cd*dt;
		deltavz = (g + rho*pow(vx,2.0)*area*cl/(2*m))*dt;
		
		vx = vx + deltavx;
		vz = vz + deltavz;
		
		dist = dist + vx*dt;
		z = z + vz*dt;
		
		count = count + 1;
		
		calcYspot(throwAngle, vx*dt);
		calcXspot(throwAngle, vx*dt);
		
		if(checkHole(hole.getX(), hole.getY())) {
			//cout << "\n\nHit the hole!!!\n\n" << endl;
			break;
		}
	}

	//cout << "Time was " << count*dt << " seconds." << endl;
	//cout << "letFly(): The disc traveled " << dist << " meters." << endl;
	
	return;
}

//calculate the disc's spot in the x direction
void Disc::calcXspot(int angle, double dist) {
	x = x + dist*cos(angle*M_PI/180);
	return;
}

//calculate the disc's spot in the y direction
void Disc::calcYspot(int angle, double dist) {
	y = y + dist*sin(angle*M_PI/180);
	return;
}

//pick screen algorithm based on disc's position
std::string Disc::pickScreen(int num) {
	/*
	Thresholds for each hole in array form...not used but here for reference
	int hole1t[] = {25,75,-20,20,-5};
    int hole2t[] = {20,40,60};
    int hole3t[] = {25, 50};
    int hole4t[] = {30, 60, -15, 15, 15};
    int hole5t[] = {20,40,0,15};
	*/
	
	switch(num) {
		case 1: 
			if(x < 25) {
				return "../../pictures/Hole1/Hole1Start.png";
			} else if(x < 75) {
				if(y < -20) {
					return "../../pictures/Hole1/Hole1Left.png";
				} else if(y < 20) {
					return "../../pictures/Hole1/Hole1Middle.png";
				} else {
					return "../../pictures/Hole1/Hole1Right.png";
				}
			} else {
				if(y < -5) {
					return "../../pictures/Hole1/Hole1EndLeft.png";
				} else { 
					return "../../pictures/Hole1/Hole1EndRight.png";
				}
			}
			break;
		case 2: 
			if(x < 20) {
				return "../../pictures/Hole2/Hole2Start.png";
			} else if(x < 40) {
				return "../../pictures/Hole2/Hole2Middle.png";
			} else if(x < 60) {
				return "../../pictures/Hole2/Hole2Three.png";				
			} else {
				return "../../pictures/Hole2/Hole2End.png";				
			}
			break;
		case 3: 
			if(x < 25) {
				return "../../pictures/Hole3/Hole3Start.png";
			} else if(x < 50) {
				return "../../pictures/Hole3/Hole3Middle.png";
			} else {
				return "../../pictures/Hole3/Hole3End.png";				
			}
			break;
		case 4:
			if(x < 30) {
				return "../../pictures/Hole4/Hole4Start.png";
			} else if(x < 60) {
				if(y < -15) {
					return "../../pictures/Hole4/Hole4Left.png";
				} else if(y < 15) {
					return "../../pictures/Hole4/Hole4Middle.png";
				} else {
					return "../../pictures/Hole4/Hole4Right.png";
				}
			} else {
				if(y < 15) {
					return "../../pictures/Hole4/Hole4EndLeft.png";
				} else { 
					return "../../pictures/Hole4/Hole4EndRight.png";
				}
			} 
			break;
		case 5:
			if(x < 20) {
				return "../../pictures/Hole5/Hole5Start.png";
			} else if(x < 40) {
					return "../../pictures/Hole5/Hole5Middle.png";
			} else {
				if(y < 0) {
					return "../../pictures/Hole5/Hole5EndLeft.png";
				} else if(y < 15) {
					return "../../pictures/Hole5/Hole5End.png";
				} else { 
					return "../../pictures/Hole5/Hole5EndRight.png";
				}
			} 
			break;
		default:
			cout << "NOOO" << endl;
	}
}

//getter for x pos
double Disc::getX() {
	return x;
}

//getter for y pos
double Disc::getY() {
	return y;
}

//print function for Disc object
void Disc::print() {
	cout << "Location is (" << x << ", " << y << ")...relative to starting at (0,0)." << endl;
	return;
}

//function to check if disc is within acceptable range of hole
int Disc::checkHole(int xHole, int yHole) {
	if(abs(x - xHole) < 5 && abs(y - yHole) < 5) {
		return 1;
	}
	return 0;
}

//prints the disc's distance from the current hole
void Disc::distFromHole(int holex, int holey) {
	cout << "The disc is " << abs(x - holex) << " meters from the hole in the x-dir and " << abs(y - holey) << " in the y-dir." << endl;
}
