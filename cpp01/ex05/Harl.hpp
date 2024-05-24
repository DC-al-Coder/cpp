#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
private:
	typedef struct s_pair
	{
		std::string	level;
		void 		(Harl::*funcptr)(void);
	}	t_pair;
	t_pair lst[4];
public:
	Harl();
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	complain(std::string level);
};

#endif
