#include <iostream>
#include <climits>
#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

int main () {
	ClapTrap	one("one");
	ScavTrap	two;
	ScavTrap	three("Batman");

	std::cout << "\nTest1:" << std::endl;
	one.attack("somebody");
	one.takeDamage(9);
	one.beRepaired(5);
	one.attack("another man");
	one.takeDamage(10);
	one.attack("somebody");
	one.takeDamage(9);
	one.beRepaired(5);

	std::cout << "\nTest2:" << std::endl;
	two.attack("my neighbour");
	two.beRepaired(21);
	two.guardGate();
	two.takeDamage(UINT_MAX);
	two.beRepaired(100);

	std::cout << "\nTest3:" << std::endl;
	ScavTrap	four(two);
	four.beRepaired(100);
	four.guardGate();

	std::cout << "\nTest4:" << std::endl;
	ScavTrap	five;
	five = two;
	five.beRepaired(100);

	std::cout << "\nTest5:" << std::endl;
	ScavTrap	six("The glorious one");
	for(int i = 0; i < 50; i++)
		six.attack("someone else");
	six.beRepaired(10);

	std::cout << "\nDestructors:" << std::endl;
}
