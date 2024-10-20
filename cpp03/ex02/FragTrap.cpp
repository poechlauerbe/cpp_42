#include <iostream>
#include "./FragTrap.hpp"
#include "./ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap " << this->_name << " is created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap " << this->_name << " is created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap(copy constructor) for " << this->_name << " called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);
	std::cout << "ScavTrap(copy assignment operator) for " << this->_name << " called." << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " was destroyed" << std::endl;
}


void FragTrap::highFivesGuys(void) {
	if (!this->checkHitPointsOk("highFiveGuys") || !this->useEnergy("highFiveGuys"))
		return;
	std::cout << this->_name << " gives you: 'High-five, guys!'" << std::endl;
}
