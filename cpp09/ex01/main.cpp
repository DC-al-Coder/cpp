#include "RPN.hpp"
#include <iostream>

int	main(int argc, char* argv[])
{
	try
	{
		Rpn rpn;
		rpn.run(argc, argv);
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
		return 1;
	}
}
