#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("undefined") {
	std::cout << "Animal class: Default constructor called!" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {}

Animal& Animal::operator=(const Animal& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal class: Destructor called!" << std::endl;
}

std::string	Animal::getType() const {
	return this->_type;
}

void	Animal::makeSound() const {
	std::cout << "Animal class doesn't have a sound" << std::endl;
}