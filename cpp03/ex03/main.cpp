// #include <iostream>
#include <climits>
#include <iostream>
#include "./DiamondTrap.hpp"

int main () {

	DiamondTrap one("The tiny Winnie");
	DiamondTrap two;

	std::cout << "\nTest1 (copy assignment operator on two):" << std::endl;
	one.attack("someone");
	one.whoAmI();
	std::cout << "one Energy points: " << one.getEnergyPoints() << std::endl;
	two = one;
	std::cout << "two Energy points: " << two.getEnergyPoints() << std::endl;

	std::cout << "\nTest2 (test not the same energy storage):" << std::endl;
	two.attack("you");
	two.highFivesGuys();
	two.whoAmI();
	std::cout << "one Energy points: " << one.getEnergyPoints() << std::endl;
	std::cout << "two Energy points: " << two.getEnergyPoints() << std::endl;

	std::cout << "\nTest3:" << std::endl;
	for (int i = 0; i < 100; i++)
		one.beRepaired(1);
	one.whoAmI();
	std::cout << "one Energy points: " << one.getEnergyPoints() << std::endl;
	std::cout << "two Energy points: " << two.getEnergyPoints() << std::endl;
	std::cout << "one hit points: " << one.getHitPoints() << std::endl;
	std::cout << "two hit points: " << two.getHitPoints() << std::endl;

	std::cout << "\nTest4(not same hitpoints storage):" << std::endl;
	one = two;
	std::cout << "one Energy points: " << one.getEnergyPoints() << std::endl;
	std::cout << "two Energy points: " << two.getEnergyPoints() << std::endl;
	std::cout << "one hit points: " << one.getHitPoints() << std::endl;
	std::cout << "two hit points: " << two.getHitPoints() << std::endl;
	std::cout << "\none" << std::endl;
	one.attack("somebody");
	one.highFivesGuys();
	one.takeDamage(1000);

	one.highFivesGuys();
	one.highFivesGuys();
	one.highFivesGuys();
	std::cout << "\ntwo" << std::endl;
	two.highFivesGuys();
	two.highFivesGuys();
	two.highFivesGuys();
	two.highFivesGuys();
	two.highFivesGuys();
	std::cout << "one Energy points: " << one.getEnergyPoints() << std::endl;
	std::cout << "two Energy points: " << two.getEnergyPoints() << std::endl;
	std::cout << "one hit points: " << one.getHitPoints() << std::endl;
	std::cout << "two hit points: " << two.getHitPoints() << std::endl;

	std::cout << "\nDestructors:" << std::endl;

}
