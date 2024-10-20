#include <iostream>
#include "./Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie()
{
	this->_name = "default";
}

Zombie::~Zombie()
{
	std::cout << _name << " is destroyed." << std::endl;
}

void	Zombie::setName(std::string name)
{
	if (name == "")
		name = "John Doe";
	this->_name = name;
}
