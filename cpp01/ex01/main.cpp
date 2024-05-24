#include "Zombie.hpp"

// void l(){system("leaks $PPID");}

int	main( void )
{
	// atexit(l);
	int i = 2;
	Zombie *horde = zombieHorde(i, "zombies");
	for (int j = 0 ; j < i; ++j)
		horde[j].announce();
	delete[] horde;
}
