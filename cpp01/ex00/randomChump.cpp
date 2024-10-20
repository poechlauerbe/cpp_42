#include "./Zombie.hpp"

void	randomChump(std::string name)
{
	if (name == "")
		name = "John Doe";
	Zombie newZombie(name);
	newZombie.announce();
}
