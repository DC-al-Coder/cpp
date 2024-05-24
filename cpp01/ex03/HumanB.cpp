#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
	std::cout << name << " contructed" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << name << " destructed" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
	std::cout << name << " equiped " << weapon.getType() << std::endl;
}

void	HumanB::attack()
{
	if (weapon == NULL)
		std::cout << name << " has no weapon" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
