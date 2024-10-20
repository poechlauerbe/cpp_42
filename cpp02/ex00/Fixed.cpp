#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor:
Fixed::Fixed(const Fixed& other) : _fixPointNumber(other._fixPointNumber)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment constructor:
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	if (this == &other)
		return *this;
	_fixPointNumber = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits function called" << std::endl;
	return this->_fixPointNumber;
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixPointNumber = raw << this->_fractionalBits;
}