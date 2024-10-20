#include <iostream>

#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat class: Default constructor called!" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
}

Cat::Cat(const Cat& other) : Animal() {
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
	if (this == &other)
		return *this;
	Animal::operator=(other);

	delete(this->_brain);
	this->_brain = new Brain(*other._brain);

	return *this;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat class: Destructor called!" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Miau, miau!" << std::endl;
}

void	Cat::setIdea(const std::string newIdea, unsigned int ideaNr) {
	if (ideaNr > 99) {
		std::cerr << "\t!!! Error: Wrong ideaNr!!!" << std::endl;
		return;
	}
	this->_brain->setIdea(newIdea, ideaNr);
}

std::string	Cat::getIdea(unsigned int ideaNr) const {
	if (ideaNr > 99) {
		std::cerr << "\t!!! Error: Wrong ideaNr!!!" << std::endl;
		return "";
	}
	return this->_brain->getIdea(ideaNr);
}
