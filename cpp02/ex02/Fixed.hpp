#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					rawbits;
	const static int	integer2 = 8;
public:
	Fixed();
	Fixed( const int n );
	Fixed( const float f );
	Fixed( const Fixed &fixed );
	~Fixed();
	Fixed&			operator=( const Fixed &fixed );
	bool			operator>( const Fixed &fixed );
	bool			operator<( const Fixed &fixed );
	bool			operator>=( const Fixed &fixed );
	bool			operator<=( const Fixed &fixed );
	bool			operator==( const Fixed &fixed );
	bool			operator!=( const Fixed &fixed );
	Fixed			operator+( const Fixed &fixed );
	Fixed			operator-( const Fixed &fixed );
	Fixed			operator*( const Fixed &fixed );
	Fixed			operator/( const Fixed &fixed );
	Fixed&			operator++();
	const Fixed		operator++( int );
	Fixed&			operator--();
	const Fixed		operator--( int );
	int				getRawBits( void ) const;
	void			setRawBits( int const raw );
	float			toFloat( void ) const;
	int				toInt( void ) const;
};

std::ostream &operator<<( std::ostream &os, const Fixed &fixed );

#endif
