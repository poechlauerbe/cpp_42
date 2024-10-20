#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->_type = "Cat";
	std::cout << "Cat class: Default constructor called!" << std::endl;
}

Cat::Cat(const Cat& other)  : Animal() {
	this->_type = other._type;
}

Cat& Cat::operator=(const Cat& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat class: Destructor called!" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Miau, miau!" << std::endl;
}