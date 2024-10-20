#include "./weapon.hpp"

Weapon::Weapon() : _type("nothing") {}

Weapon::Weapon(std::string typeName) : _type(typeName)
{
	if (this->_type == "")
		this->_type = "nothing";
}

Weapon::~Weapon() {}

const std::string&	Weapon::getType()
{
	const std::string &refWeapon = this->_type;
	return refWeapon;
}

void	Weapon::setType(std::string weaponType)
{
	this->_type = weaponType;
	if (this->_type == "")
		this->_type = "nothing";
}
