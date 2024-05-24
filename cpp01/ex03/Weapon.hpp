#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon();
	Weapon(std::string name);
	~Weapon();
	const std::string&	getType();
	void	setType(std::string str);
};

#endif
