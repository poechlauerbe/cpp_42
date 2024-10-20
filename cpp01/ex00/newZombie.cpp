#include "./Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie *newZombie;
	
	if (name == "")
		name = "John Doe";
	newZombie = new Zombie(name);
	return newZombie;
}