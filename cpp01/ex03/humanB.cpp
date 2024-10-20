#include "./humanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {
	this->_weapon = NULL;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack() {
	if (!_weapon)
	{
		std::cout << _name << " can not attack - no weapon available!" << std::endl;
		return;
	}
	std::cout << _name << " attacks with " <<  _weapon->getType() << std::endl;
}
