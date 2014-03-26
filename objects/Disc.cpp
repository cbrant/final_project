/*
Disc.cpp
Patrick Hansen
3/18/14
implemenation of Disc object
*/

#include "Disc.h"
#include <cmath>
#include <iostream>

using namespace std;

Disc::Disc() {
	x = 0;
	y = 0;
	vx = 0;
	vy = 0;
}

void Disc::letFly(double power, double uAlpha) {

	x = 0; //x position (m)
	y = 1; //y position (m)
	vx = cos(uAlpha*M_PI/180)*power; //x velocity (m/s)
	vy = sin(uAlpha*M_PI/180)*power; //y velocity (m/s)
	float g = -9.81; //acceleration due to gravity 
	float m = 0.175; //mass of disc (kg)
	float rho = 1.23; //density of fluid--air (kg/m^3)
	float area = 0.0568; //area of disc (m^2)
	float cl0 = 0.1; //lift coefficient at alpha = 0
	float clA = 1.4; //lift coefficient dependent on alpha
	float cd0 = 0.08; //drag coefficient at alpha = 0
	float cdA = 2.72; //drag coefficient dependent on alpha
	int alpha0 = -4;
	double deltavx;
	double deltavy;
	double alpha = uAlpha;
	double pi = M_PI;

	double cl = cl0 + clA*alpha*pi/180; 
	double cd = pow(cd0 + cdA*((alpha + alpha0)*pi/180),2.0);

	float dt = 0.01;

	int count = 0; //loop iteration count

	while (y > 0) {
		
		deltavx = -rho*pow(vx,2.0)*area*cd*dt;
		deltavy = (g + rho*pow(vx,2.0)*area*cl/(2*m))*dt;
		
		vx = vx + deltavx;
		vy = vy + deltavy;
		
		x = x + vx*dt;
		y = y + vy*dt;
		
		count = count + 1;
	}

	cout << "Time was " << count*dt << " seconds." << endl;

}

void Disc::print() {
	cout << "Distance traveled was " << x << " and y should be 0 (" << y << ")" << endl;
	cout << "x-velocity when it hit the ground was " << vx << " and y-velocity was " << vy << endl;
}
