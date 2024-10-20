// #include <iostream>

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : ICharacter() {
	for (int i = 0; i < this->_size; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(std::string name) : ICharacter(name) {
	for (int i = 0; i < this->_size; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(const Character& other) : ICharacter(other) {
	for (int i = 0; i < this->_size; i++) {
		if (other._inventory[i]) {
			this->_inventory[i] = (other.getAMateria(i))->clone();
		} else {
			this->_inventory[i] = NULL;
		}
	}
}

Character& Character::operator=(const Character& other) {
	if (this == &other)
		return *this;
	ICharacter::operator=(other);

	// delete it if something is stored
	for (int i = 0; i < this->_size; i++) {
		if (this->_inventory[i]) {
			delete (this->_inventory[i]);
		}
	}

	// fill it with the values of other
	for (int i = 0; i < this->_size; i++) {
		if (other._inventory[i]) {
			this->_inventory[i] = other._inventory[i]->clone();
		} else {
			this->_inventory[i] = NULL;
		}
	}
	return *this;
}
Character::~Character() {
	// delete it if something is stored
	for (int i = 0; i < this->_size; i++) {
		if (this->_inventory[i]) {
			delete (this->_inventory[i]);
			(this->_inventory[i]) = NULL;
		}
	}
}

AMateria*	Character::getAMateria(int idx) const {
	if (idx < 0 || idx >= this->_size)
		return NULL;
	return this->_inventory[idx];
}


std::string const & Character::getName() const {
	return this->_name;
}
void Character::equip(AMateria* m) {
	if (!m)
		return ;
	for (int i = 0; i < this->_size; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= this->_size)
		return;
	if (!this->_inventory[idx])
		return;
	else {
		this->_inventory[idx] = NULL; // store before (in main)
	}
}

// The use(int, ICharacter&) member function will have to use the Materia at the
// slot[idx], and pass the target parameter to the AMateria::use function.

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= this->_size)
		return;
	if (!this->_inventory[idx]) {
		return;
	}
	this->_inventory[idx]->use(target);
}
