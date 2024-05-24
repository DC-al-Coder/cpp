#include "Zombie.hpp"

int	main( void )
{
	Zombie	*z = newZombie("zombie 1");
	z->announce();
	randomChump("zombie 2");
	delete z;
}
