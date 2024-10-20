#include <iostream>
#include "./Zombie.hpp"

int main ()
{
	Zombie	*testZombie = NULL;

	testZombie = newZombie("The ultimate Zombie");
	if (!testZombie)
		return 1;
	testZombie->announce();
	delete testZombie;

	std::cout << "\nNext Zombie (newZombie):" << std::endl;
	testZombie = newZombie("");
	if (!testZombie)
		return 1;
	testZombie->announce();
	delete testZombie;

	std::cout << "\nNext Zombie (randomChump):" << std::endl;
	randomChump("The short Zombie");
	
	std::cout << "\nNext Zombie (randomChump):" << std::endl;
	randomChump("");
}
