#include <iostream>
#include "./ClapTrap.hpp"

int main () {
	ClapTrap	one;
	ClapTrap	two("test");

	one.attack("somebody");
	one.takeDamage(9);
	one.beRepaired(5);
	one.attack("another man");
	one.takeDamage(10);
	one.attack("somebody");
	one.takeDamage(9);
	one.beRepaired(5);
	
	std::cout << "\nTest2:" << std::endl;
	while (two.getEnergyPoints())
		two.beRepaired(1);
	two.attack("the strange man.");
	two.takeDamage(1000);
}
