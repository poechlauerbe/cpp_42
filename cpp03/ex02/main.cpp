#include <iostream>
#include <climits>
#include "FragTrap.hpp"

int main () {
	FragTrap two("Zero");
	FragTrap one;

	one = two;

	std::cout << "\nTest1:" << std::endl;
	two.attack("you");
	two.highFivesGuys();

	std::cout << "\nTest2(loop):" << std::endl;
	for (int i = 0; i < 98; i++)
		two.beRepaired(1);

	std::cout << "\nTest3(no energy):" << std::endl;
	two.attack("somebody");
	two.highFivesGuys();
	two.takeDamage(1000);

	std::cout << "\nTest4(no energy and dead):" << std::endl;
	two.highFivesGuys();

	std::cout << "\nDestructors:" << std::endl;
}
