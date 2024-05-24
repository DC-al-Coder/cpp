#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	rawbits = 0;
}

Fixed::Fixed( const int n )
{
	std::cout << "Int constructor called" << std::endl;
	rawbits = n << integer2;
}

Fixed::Fixed( const float f )
{
	std::cout << "Float constructor called" << std::endl;
	rawbits = roundf(f * (1 << integer2));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment constructor called" << std::endl;
	rawbits = fixed.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	std::cout << fixed.toFloat();
	return (os);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (rawbits);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	rawbits = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)rawbits / (1 << integer2));
}

int Fixed::toInt( void ) const
{
	return (rawbits >> integer2);
}
