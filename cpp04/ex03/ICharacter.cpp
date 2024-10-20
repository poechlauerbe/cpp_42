#include "ICharacter.hpp"
#include "AMateria.hpp"


ICharacter::ICharacter() : _name("Defaulty") {}

ICharacter::ICharacter(std::string name) : _name(name) {}

ICharacter::ICharacter(const ICharacter& other) {
	this->_name = other._name;
}

ICharacter& ICharacter::operator=(const ICharacter& other) {
	if (this == &other)
		return *this;
	this->_name = other._name;

	return *this;
}

ICharacter::~ICharacter() {}
