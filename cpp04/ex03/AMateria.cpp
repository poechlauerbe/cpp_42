#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("default") {}
AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this == &other)
		return *this;

	this->_type = other._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	std::cout << target.getName() << " not known." << std::endl;
}
