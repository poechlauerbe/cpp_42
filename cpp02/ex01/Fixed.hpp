#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>
class Fixed {
private:
	int	_fixPointNumber;
	static const int _fractionalBits = 8;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);

	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& num);

#endif
