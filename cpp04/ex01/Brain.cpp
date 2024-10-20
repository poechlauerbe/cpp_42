#include <iostream>
#include <sstream>
#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++) {
		std::stringstream ss;
		ss << "idea nr. ";
		ss << i;
		this->_ideas[i] = ss.str();
	}
	std::cout << "Brain class: Default constructor called!" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other) {
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain class: Destructor called!" << std::endl;
}

void	Brain::setIdea(const std::string newIdea, unsigned int ideaNr) {
	if (ideaNr > 99) {
		std::cerr << "Wrong ideaNr" << std::endl;
		return;
	}
	this->_ideas[ideaNr] = newIdea;
}

std::string	Brain::getIdea(unsigned int ideaNr) const {
	if (ideaNr > 99) {
		std::cerr << "Wrong ideaNr" << std::endl;
		return NULL;
	}
	return this->_ideas[ideaNr];
}
