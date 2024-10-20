#include <iostream>
#include <iomanip>
#include "./Fixed.hpp"

int main() {

	{
		std::cout << "Subject request:\n" << std::endl;

		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	std::cout << "\n\nMy tests:" << std::endl;
	{
		Fixed a = 10;

		std::cout << "\nPost- and pre-increment:" << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;

		std::cout << "\nPost- and pre-decrement:" << std::endl;
		std::cout << a << std::endl;
		std::cout << a-- << std::endl;
		std::cout << a << std::endl;
		std::cout << --a << std::endl;
	}

	{
		std::cout << "\nArithmetic:" << std::endl;

		Fixed a = 10;
		Fixed b = 1.2f;
		Fixed e(-8370000);

		std::cout << a << std::endl;
		std::cout << a + b << std::endl;
		std::cout << a - b << std::endl;
		std::cout << a * b << std::endl;
		std::cout << a / b << std::endl;
		std::cout << std::fixed << std::setprecision(2)  <<  e << std::endl;
	}

		// while ( e < 0)
		// 	e--;

	{
		std::cout << "\nComparison:" << std::endl;

		Fixed a = 10.2f;
		Fixed b = 10.3f;
		const Fixed c = 3.0f;
		const Fixed d = 13.0f;

		std::cout << std::boolalpha;
		std::cout << "a < b: " << (a < b) << std::endl;
		std::cout << "a <= b: " << (a <= b) << std::endl;
		std::cout << "a > b: " << (a > b) << std::endl;
		std::cout << "a >= b: " << (a >= b) << std::endl;
		std::cout << "a == b: " << (a == b) << std::endl;
		std::cout << "a != b: " << (a != b) << "\n" << std::endl;

		std::cout << "min (a, b): " << Fixed::min(a, b) << std::endl;
		std::cout << "max (a, b): " << Fixed::max(a, b) << std::endl;
		std::cout << "min (c, d): " << Fixed::min(c, d) << std::endl;
		std::cout << "max (c, d): " << Fixed::max(c, d) << std::endl;
		std::cout << "c != d: " << (c != d) << std::endl;
	}

	return 0;
}
	// std::cout << std::fixed << std::setprecision(2);
