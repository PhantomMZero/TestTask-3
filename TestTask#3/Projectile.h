#pragma once

#include <cmath>
#include <vector>

class Projectile {
public:
	Projectile();
	//double getSpeedOfProjectile(int t);//Определение скорости тела
	//double getCoordinatesOnTrajectory(int t);//Определение координат тела с секундной точностью
	double getCoordinatesOfDestination();//Определение точки падения
	void exportToXls();
private:
	double x0=0;//x start coordinate
	double y0=0;//y start coordinate
	double xOfDestination=0;
	double yOfDestination=0;
	double gr = 45; //degree
	double rad = gr * 3.14 / 180;
	double dt = 0.1;
	double V0 = 700; // m/s initial velocity
	double VX = V0 * cos(rad);//start speed
	double VY = V0 * sin(rad);//start speed
	double fThrust = 500;//Thrust impulse H*c
	double fLift = 50;//Wing force that lift projectile
	
	// double z=0;//z coordinate
	double g = 9.8; //settled average value acceleration of free fall
	double d = 120; //diameter in millimeters
	double l = 600; //length in millimeters
	double lk = 120; //length of conical part in millimeters
	double PAir = 1.29; //average air density 
	
	double R = 0;// air resistance R=c*s(pV^2/2) not using
	//k=cSp/2m coef Air resistance in acceleration с=0,05
	double c = 0.05;
	double mass = 59.96; //kg mass of projectile mass of conical 14.11+14.11 + mass of cylinder 31,74 !hardcode	
	double fuelMass = 0.5; //kg mass of projectile mass of conical 14.11+14.11 + mass of cylinder 31,74 !hardcode	
	double P = 7800; //steel density kg/m3 not using because of hardcode
	std::vector<std::vector<double>> trajectory; //{ x1, y1, V1, t }
	
};