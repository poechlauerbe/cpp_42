#include <iostream>
#include <climits>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Defaulty"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << this->_name << " is created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	if (this->_name == "")
		this->_name = "Defaulty";
	std::cout << this->_name << " is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "ClavTrap(copy constructor) for " << this->_name << " called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this == &other)
		return *this;

	this->_name = other.getName();
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackDamage = other.getAttack();

	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << this->_name << " was destroyed." << std::endl;
}

std::string	ClapTrap::getName() const {
	return this->_name;
}

int	ClapTrap::getHitPoints() const {
	return this->_hitPoints;
}

int	ClapTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

int	ClapTrap::getAttack() const {
	return this->_attackDamage;
}

bool	ClapTrap::checkHitPointsOk(std::string actionName) {
	if (this->_hitPoints <= 0) {
		std::cout << this->_name << ": " << actionName << " is not possible. Already dead." << std::endl;
		return false;
	}
	return true;
}

bool	ClapTrap::checkEnergyOk(std::string actionName) {
	if (this->_energyPoints <= 0) {
		std::cout << this->_name << ": " << actionName << " is not possible. No energy left." << std::endl;
		return false;
	}
	return true;
}

bool	ClapTrap::useEnergy(std::string actionName) {
	if (!this->checkEnergyOk(actionName))
		return false;
	this->_energyPoints -= 1;
	return true;
}

void	ClapTrap::attack(const std::string& target) {
	if (!this->checkHitPointsOk("attack") || !this->useEnergy("attack"))
		return;
	std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!this->checkHitPointsOk("taking damage"))
		return;
	this->_hitPoints -= amount;
	std::cout << this->_name << " gets hit and loses " << amount << " of hit points" << std::endl;
	if (this->_hitPoints <= 0 || amount > INT_MAX) {
		this->_hitPoints = 0;
		std::cout << this->_name << " died." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->checkHitPointsOk("be repaired") || !this->useEnergy("be repaired"))
		return;
	if ((static_cast<long>(this->_hitPoints) + amount) > INT_MAX) {
		this->_hitPoints = INT_MAX;
		std::cout << this->_name << " got healed until " << INT_MAX << " hit points. This is the maximum." << std::endl;
		return;
	}
	else {
		this->_hitPoints += amount;
		std::cout << this->_name << " got healed and received " << amount << " hit points" << std::endl;
	}
}
