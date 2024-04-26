#include <iostream>

#include "Projectile.h"

int main() {

	std::cout << "Select an action \n1. Start calculation with default parameters \n2. Change default parameters\n3. Break\n";
	int selectedAction;
	std::cin >> selectedAction;
	Projectile projectile; 
	while (true)
	{
		if (selectedAction == 3) break;
		switch (selectedAction) {
		case 1:
			projectile.calculate();
			projectile.exportToXls();
			break;
		case 2:
			std::cout << "Enter diameter, mm\n";
			int diameter;
			std::cin >> diameter;
			projectile.setDiameter(diameter);

			std::cout << "Enter length, mm\n";
			int length;
			std::cin >> length;
			projectile.setLength(length);

			std::cout << "Enter mass, kg\n";
			int mass;
			std::cin >> mass;
			projectile.setMass(mass);

			std::cout << "Enter degree\n";
			int gr;
			std::cin >> gr;
			projectile.setGr(gr);
								
			std::cout << "Enter initial speed, m/s\n";
			int iSpeed;
			std::cin >> iSpeed;
			projectile.setV0(iSpeed);

			projectile.calculate();
			projectile.exportToXls();

			break;
		default:
			break;
		}
		std::cout<< "Select an action \n1. Start calculation with previous parameters \n2. Change parameters\n3. Break\n";
		std::cin >> selectedAction;

	}
	
	return 0;

}