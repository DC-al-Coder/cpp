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

bool	Fixed::operator>( const Fixed &fixed )
{
	return (rawbits > fixed.getRawBits());
}

bool	Fixed::operator<( const Fixed &fixed )
{
	return (rawbits < fixed.getRawBits());
}

bool	Fixed::operator>=( const Fixed &fixed )
{
	return (rawbits >= fixed.getRawBits());
}

bool	Fixed::operator<=( const Fixed &fixed )
{
	return (rawbits <= fixed.getRawBits());
}
bool	Fixed::operator==( const Fixed &fixed )
{
	return (rawbits == fixed.getRawBits());
}

bool	Fixed::operator!=( const Fixed &fixed )
{
	return (rawbits != fixed.getRawBits());
}

Fixed	Fixed::operator+( const Fixed &fixed )
{
	Fixed	ret;
	ret.setRawBits((float)this->getRawBits() + (float)fixed.getRawBits());
	return (ret);
}

Fixed	Fixed::operator-( const Fixed &fixed )
{
	Fixed	ret;
	ret.setRawBits((float)this->getRawBits() - (float)fixed.getRawBits());
	return (ret);
}

Fixed	Fixed::operator*( const Fixed &fixed )
{
	Fixed	ret;
	ret.setRawBits((float)this->getRawBits() * (float)fixed.getRawBits() / (float)(1 << integer2));
	return (ret);
}

Fixed	Fixed::operator/( const Fixed &fixed )
{
	Fixed	ret;
	ret.setRawBits((float)this->getRawBits() / (float)fixed.getRawBits() * (float)(1 << integer2));
	return (ret);
}

Fixed&	Fixed::operator++()
{
	rawbits++;
	return (*this);
}

const Fixed	Fixed::operator++( int )
{
	const Fixed	retobj = *this;
	rawbits++;
	return (retobj);
}

Fixed&	Fixed::operator--()
{
	rawbits--;
	return (*this);
}

const Fixed	Fixed::operator--( int )
{
	const Fixed	retobj = *this;
	rawbits--;
	return (retobj);
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

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	std::cout << fixed.toFloat();
	return (os);
}
