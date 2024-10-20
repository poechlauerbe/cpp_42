#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->_type = "Dog";
	std::cout << "Dog class: Default constructor called!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal() {
	this->_type = other._type;
}

Dog& Dog::operator=(const Dog& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog class: Destructor called!" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Wuff, wuff!" << std::endl;
}
