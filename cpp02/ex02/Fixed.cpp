#include <iostream>
#include <cmath>
#include <climits>
#include "./Fixed.hpp"

Fixed::Fixed() : _fixPointNumber(0) {}

Fixed::Fixed(int num) : _fixPointNumber(num << _fractionalBits)
{
	if ((num > 0 && _fixPointNumber < 0 ) || (num < 0 && _fixPointNumber > 0))
		std::cerr << "\n\t!!!WARNING: Overflow/Underflow detected!!! num: " << num << "\n" << std::endl;
}

Fixed::Fixed(float num)
{
	this->_fixPointNumber = static_cast<int>(roundf(num * (1 << this->_fractionalBits)));
	if ((num > 0 && _fixPointNumber < 0 ) || (num < 0 && _fixPointNumber > 0))
		std::cerr << "\n\t!!!WARNING: Overflow/Underflow detected!!! num: " << num << "\n" << std::endl;
}

// Copy constructor:
Fixed::Fixed(const Fixed& other) : _fixPointNumber(other._fixPointNumber) {}

// Copy assignment constructor:
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)
		return *this;
	this->_fixPointNumber = other._fixPointNumber;
	return *this;
}

Fixed::~Fixed() {}

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

// pre increment
Fixed& Fixed::operator++()
{
	if ((_fixPointNumber > 0 && (_fixPointNumber + 1) < 0 ))
		std::cerr << "\n\t!!!WARNING: Overflow detected!!! ++operator" << "\n" << std::endl;
	this->_fixPointNumber++;
	return *this;
}

// post increment
Fixed Fixed::operator++(int)
{
	if ((_fixPointNumber > 0 && (_fixPointNumber + 1) < 0 ))
		std::cerr << "\n\t!!!WARNING: Overflow detected!!! operator++" << "\n" << std::endl;
	Fixed temp(*this);
	_fixPointNumber++;
	return temp;
}

// pre decrement
Fixed& Fixed::operator--()
{
	if ((_fixPointNumber < 0 && (_fixPointNumber - 1) > 0 ))
		std::cerr << "\n\t!!!WARNING: Underflow detected!!! --operator" << "\n" << std::endl;
	this->_fixPointNumber--;
	return *this;
}

// post decrement
Fixed Fixed::operator--(int)
{
	if ((_fixPointNumber < 0 && (_fixPointNumber - 1) > 0 ))
		std::cerr << "\n\t!!!WARNING: Underflow detected!!! operator--" << "\n" << std::endl;
	Fixed temp(*this);
	this->_fixPointNumber--;
	return temp;
}

// Arithmetic operators:
Fixed Fixed::operator+(const Fixed& other) const
{
	long num = this->_fixPointNumber + other._fixPointNumber;
	if ((num > INT_MAX ) || (num < INT_MIN))
		std::cerr << "\n\t!!!WARNING: Overflow/Underflow detected!!! operator: '+'\n" << std::endl;
	return Fixed(static_cast<float>(num) / (1 << this->_fractionalBits));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	long num = this->_fixPointNumber - other._fixPointNumber;
	if ((num > INT_MAX ) || (num < INT_MIN))
		std::cerr << "\n\t!!!WARNING: Overflow/Underflow detected!!! operator: '-'\n" << std::endl;
	return Fixed(static_cast<float>(num) / (1 << this->_fractionalBits));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	long long sum;
	sum = static_cast<long long>(this->_fixPointNumber) * other._fixPointNumber / (1 << this->_fractionalBits);
	if ((sum > INT_MAX ) || (sum < INT_MIN))
		std::cerr << "\n\t!!!WARNING: Overflow/Underflow detected!!! operator: '*'\n" << std::endl;
	return  Fixed(static_cast<float>(sum) / (1 << this->_fractionalBits));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	long long sum;
	sum = static_cast<long long>(this->getRawBits()) * (1 << this->_fractionalBits) / other.getRawBits();
	if ((sum > INT_MAX ) || (sum < INT_MIN))
		std::cerr << "\n\t!!!WARNING: Overflow/Underflow detected!!! operator: '/'\n" << std::endl;
	return Fixed(static_cast<float>(sum) / (1 << this->_fractionalBits));
}

// Comparison operator:
bool Fixed::operator>(const Fixed& other) const
{
	if (this->getRawBits() > other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed& other) const
{
	if (this->getRawBits() >= other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed& other) const
{
	if (this->getRawBits() < other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed& other) const
{
	if (this->getRawBits() <= other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed& other) const
{
	if (this->getRawBits() == other.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed& other) const
{
	if (this->getRawBits() != other.getRawBits())
		return true;
	return false;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return a;
	return b;
}
