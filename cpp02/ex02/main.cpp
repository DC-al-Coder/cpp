#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c(10.5f);
	Fixed d(10.78f);
	Fixed e = c - d;
	std::cout << e << std::endl;
	std::cout << ++(++e) << std::endl;
	std::cout << e << std::endl;
	return 0;
}
