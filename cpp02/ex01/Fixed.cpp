#include "./Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int num) : _fixPointNumber(num << _fractionalBits)
{
	if ((num > 0 && _fixPointNumber < 0 ) || (num < 0 && _fixPointNumber > 0))
		std::cerr << "\n\t!!!WARNING: Overflow/Underflow detected!!! num: " << num << "\n" << std::endl;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float num)
{
	this->_fixPointNumber = static_cast<int>(roundf(num * (1 << this->_fractionalBits)));
	if ((num > 0 && _fixPointNumber < 0 ) || (num < 0 && _fixPointNumber > 0))
		std::cerr << "\n\t!!!WARNING: Overflow/Underflow detected!!! num: " << num << "\n" << std::endl;
	std::cout << "Float constructor called" << std::endl;
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
	this->_fixPointNumber = other._fixPointNumber;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	return this->_fixPointNumber;
}

void	Fixed::setRawBits( int const raw ) {
	this->_fixPointNumber = raw << this->_fractionalBits;
}

float	Fixed::toFloat() const
{
	return static_cast<float>(this->getRawBits()) / (1 << this->_fractionalBits);
}

int		Fixed::toInt() const
{
	return this->getRawBits() >> this->_fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& num)
{
	out << num.toFloat();
	return out;
}
