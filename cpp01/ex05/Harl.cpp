#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
	lst[0].level = "DEBUG";
	lst[0].funcptr = &Harl::debug;
	lst[1].level = "INFO";
	lst[1].funcptr = &Harl::info;
	lst[2].level = "WARNING";
	lst[2].funcptr = &Harl::warning;
	lst[3].level = "ERROR";
	lst[3].funcptr = &Harl::error;
}

void	Harl::debug(void)
{
	std::cout << "debug function called" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "info function called" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "warning function called" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "error function called" << std::endl;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; ++i)
	{
		if (level == lst[i].level)
		{
			(this->*(lst[i].funcptr))();
			return ;
		}
	}
	std::cout << "complain anyway" << std::endl;
}
