#include <iostream>
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog class: Default constructor called!" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain;
}

Dog::Dog(const Dog& other) : Animal() {
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
	if (this == &other)
		return *this;
	Animal::operator=(other);

	delete(this->_brain);
	this->_brain = new Brain(*other._brain);

	return *this;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog class: Destructor called!" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Wuff, wuff!" << std::endl;
}

void	Dog::setIdea(const std::string newIdea, unsigned int ideaNr) {
	if (ideaNr > 99) {
		std::cerr << "\t!!! Error: Wrong ideaNr!!!" << std::endl;
		return;
	}
	this->_brain->setIdea(newIdea, ideaNr);
}

std::string	Dog::getIdea(unsigned int ideaNr) const {
	if (ideaNr > 99) {
		std::cerr << "\t!!! Error: Wrong ideaNr!!!" << std::endl;
		return "";
	}
	return this->_brain->getIdea(ideaNr);
}
