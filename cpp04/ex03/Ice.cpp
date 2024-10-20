#include <iostream>

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other._type) {}

Ice& Ice::operator=(const Ice& other) {
	if (this == &other)
		return *this;
	*this = other;
	return *this;
}

Ice::~Ice() {

}

AMateria* Ice::clone() const {
	AMateria* ptr;

	ptr = new Ice();
	return ptr;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
