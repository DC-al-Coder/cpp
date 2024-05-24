#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : type(type)
{
	std::cout << type << " contructed" << std::endl;
}

Weapon::Weapon() : type("Unknown")
{
	std::cout << type << " contructed" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << type << " destructed" << std::endl;
}

const std::string&	Weapon::getType()
{
	return (type);
}

void	Weapon::setType(std::string str)
{
	type = str;
}
