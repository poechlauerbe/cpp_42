#include <iostream>

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other._type) {}

Cure& Cure::operator=(const Cure& other) {
	if (this == &other)
		return *this;

	*this = other;
	return *this;
}

Cure::~Cure() {

}

AMateria* Cure::clone() const {
	AMateria* ptr;

	ptr = new Cure();
	return ptr;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
