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

Disc::Disc() {
	x = 0;
	y = 0;
	z = 1;
	vx = 0;
	vz = 0;
}

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
			cout << "\n\nHit the hole!!!\n\n" << endl;
			break;
		}
	}

	//cout << "Time was " << count*dt << " seconds." << endl;
	cout << "letFly(): The disc traveled " << dist << " meters." << endl;
	

	pickScreen(hole.getThresh());
	
	return;
}

void Disc::calcXspot(int angle, double dist) {
	x = x + dist*cos(angle*M_PI/180);
	return;
}

void Disc::calcYspot(int angle, double dist) {
	y = y + dist*sin(angle*M_PI/180);
	return;
}

string Disc::pickScreen(int num) {
	
	switch(num) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			cout << "NOOO" << endl;	
	}
	
	if(x < arr[0]) {
		cout << "Picking screen 0" << endl;
		return 0;
	} else if (x > arr[1]) {
		cout << "Picking screen 4" << endl;
		return 4;
	} else {
		if(y < arr[2]) {
			cout << "Picking screen 1" << endl;
			return 1;
		} else if(y > arr[3]) {
			cout << "Picking screen 3" << endl;
			return 3;
		} else {
			cout << "Picking screen 2" << endl;
			return 2;
		}
	}
}

double Disc::getX() {
	return x;
}

double Disc::getY() {
	return y;
}

void Disc::print() {
	cout << "Location is (" << x << ", " << y << ")...relative to starting at (0,0)." << endl;
	return;
}

int Disc::checkHole(int xHole, int yHole) {
	if(abs(x - xHole) < 5 && abs(y - yHole) < 5) {
		return 1;
	}
	return 0;
}

void Disc::distFromHole(int holex, int holey) {
	cout << "The disc is " << abs(x - holex) << " meters from the hole in the x-dir and " << abs(y - holey) << " in the y-dir." << endl;
}
