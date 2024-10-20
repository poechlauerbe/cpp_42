#include <iostream>
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "WrongCat class: Default constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
	this->_type = other._type;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat class: Destructor called!" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Miau, miau!" << std::endl;
}