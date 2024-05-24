#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
 : name(name)
{
	std::cout << name << " contructed" << std::endl;
}

Zombie::Zombie( void )
 : name("Unknown")
{
	std::cout << name << " contructed" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " destructed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
