#ifndef SED_HPP
# define SED_HPP

#include <fstream>
#include <string>

class Sed
{
private:
	std::ifstream		in;
	std::ofstream		out;
	std::string			infilename;
	std::string			outfilename;
	const std::string	findstr;
	const std::string	replacestr;
	std::string			str;
public:
	Sed(std::string filename, std::string findstr, std::string replacestr);
	~Sed();
	bool	isvalid();
	void	doSed();
};

#endif
