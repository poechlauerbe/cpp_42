#include <iostream>
#include "./DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap " << this->_name << " is created." << std::endl;
	this->_name = "Defaulty";
	ClapTrap::_name  = this->_name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap " << this->_name << " is created." << std::endl;
	this->_name = name;
	ClapTrap::_name  = this->_name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	*this = other;
	std::cout << "DiamondTrap(copy constructor) for " << this->_name << " called." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	if (this == &other)
		return *this;
	this->_name = other._name;
	ClapTrap::_name = other.ClapTrap::_name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;

	std::cout << "DiamondTrap(copy assignment operator) for " << this->_name << " called." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " was destroyed" << std::endl;
}

void DiamondTrap::attack(std::string target) {
	ScavTrap::attack(target);
}


void DiamondTrap::whoAmI() {
	if (!checkHitPointsOk("whoAmI") || !useEnergy("whoAmI"))
		return;
	std::cout << "WhoAmI? Name: " << this->_name << " & ClapTrap name: " << ClapTrap::_name << std::endl;
}