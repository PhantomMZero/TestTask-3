#include "Projectile.h"

#include <iostream>
#include <fstream>


//���� ��������-���������� ����� ��������� d, ������ 120 ��, 
// ������ l, ������ 600 ��, � ������ ���������� �����, 
// ������ �������� ����, ������������� �� ��������������� �����, 
// ����������� �� �������������� ��������� �� ���������V0, ������ 700 �/���. 
// ����� �������������� ��������� ���������� ��� ����� 45� � ���������.
//���� ����� ���������� ���������.����� ������ ������� ������� � 0, 5 ��.���������� ��������� ���������� ����� 5 ������ ����� ������ �������� ����.����� ������ ��������� � 0, 5 �������.
//��������� ����� ������ ������� ������� � �����������.������� ���� ����������� ��������� � 500 ͷ�.������ ���� ��������� �� ��� ���� � ����������� ��� ��������.
//�� ��, ��� � ������ 2. � ������� ����� ���������� � �� ������� ������� ���� �� ����������� ����� �� ���� ��������� ��������� ���������������� ���� ��������� 50 �.
//��� ��������� ���������� :
//�� ��, ��� � ��� ������� ������ 1.


//��� ��������� ���������� :
//1.	���������� ����������� ��������� ����
// (�������� ����, ���������� ���� �� ���������� � ������������ �������������, 
// �������������� ����������� ������������ ���������� ����� ����������).
//2.	���������� ���������� ����� ������� ���� �� �����



Projectile::Projectile()
{
	//�������-���������� �������������
	double V1, x1, y1, t, V2, x2, y2, teta1, teta2; 
	x1 = 0;
	y1 = 0;
	V1 = V0;
	t = 0;
	teta1 = rad;
	trajectory.push_back({ x1, y1, V1, t });
	mass += fuelMass;
	while (true) {
		double k = ((c * PAir * 3.14 * pow((lk / 2) / 1000, 2)) / (2 * mass)); //coef of resistance
		// Calculate new speed and angle
		V2 = V1 - dt * (k * pow(V1, 2) + g * sin(teta1));
		teta2 = teta1 - dt * g * cos(teta1) / V1;

		//Calculate new coordinates
		x2 = x1 + (V1 * cos(teta1)) * dt;
		y2 = y1 + (V1 * sin(teta1)) * dt;
		t = t + dt;
		

		//Adding points to trajectory
		trajectory.push_back({ x2, y2, V2, t });
		if (y2 <= 0) {
			xOfDestination = x2;
			std::cout << "V= " << V2 << "m/s\n";
			std::cout << "x= " << x2 << "m\n";
			std::cout << "t= " << t << "sec\n";
			break;
		}
		//Engine on
		if (t >= 5 && t < 5.5) {
			V2 += fThrust / mass * dt;
			mass -= (5.5 - 5) / 0.5 * 0.1;
		}
		//need double check
		if (V1 * sin(teta1) > 0 && V2 * sin(teta2) <= 0) {
			V2 += dt * (fLift * cos(teta1));
			teta2 += dt * (fLift * sin(teta1));
			x2 += dt * (fLift * sin(teta1));
			y2 += dt * (fLift * sin(teta1));
		}

		V1 = V2;
		teta1 = teta2;
		x1 = x2;
		y1 = y2;
	}

}

void Projectile::exportToXls()
{
	std::fstream fout;

	// opens an existing csv file or creates a new file. 
	fout.open("results.csv", std::ios::out | std::ios::app);
	fout << "Column0,Column1,Column2,Column3\n";

	for (int i = 0; i < trajectory.size(); ++i) {
		fout << trajectory[i][0] << ','
			<< trajectory[i][1] << ','
			<< trajectory[i][2] << ','
			<< trajectory[i][3] << '\n';
	}
}

//double Projectile::getSpeedOfProjectile(int t)
//{
//	return 0;
//}

//double Projectile::getCoordinatesOnTrajectory(int t)
//{
//	return 0;
//}

double Projectile::getCoordinatesOfDestination()
{
	if (xOfDestination!=0) return xOfDestination;
}
