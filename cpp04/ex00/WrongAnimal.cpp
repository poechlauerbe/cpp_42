#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("undefined") {
	std::cout << "WrongAnimal class: Default constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal class: Destructor called!" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return this->_type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal class doesn't have a sound" << std::endl;
}