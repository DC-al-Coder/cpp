#include <iostream>
#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "More or less arguments" << std::endl;
		return (1);
	}
	Sed sed(argv[1], argv[2], argv[3]);
	if (sed.isvalid())
		sed.doSed();
	else
		return (1);
	return (0);
}
