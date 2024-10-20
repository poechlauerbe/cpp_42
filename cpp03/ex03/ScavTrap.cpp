#include <iostream>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << "Scavtrap " << this->_name << " is created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << "Scavtrap " << this->_name << " is created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap(copy constructor) for " << this->_name << " called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);
	std::cout << "ScavTrap(copy assignment operator) for " << this->_name << " called." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " was destroyed" << std::endl;
}

void	ScavTrap::attack(std::string target) {
	if (!this->checkHitPointsOk("attack") || !this->useEnergy("attack"))
		return;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage." << std::endl;
}

void ScavTrap::guardGate() {
	if (!checkHitPointsOk("guardGate") || !useEnergy("guardGate"))
		return;
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
