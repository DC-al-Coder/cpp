#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char* argv[])
{
	PmergeMe	pm;
	try
	{
		pm.run(argc, argv);
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}
}
