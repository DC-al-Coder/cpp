#include "Harl.hpp"

int	main(void)
{
	Harl harl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("extra");
	harl.complain("debug");
	harl.complain("DEBUG1");
	harl.complain("DEBUG ");
	harl.complain("");
	harl.complain(" ");
}
