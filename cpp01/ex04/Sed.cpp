#include "Sed.hpp"
#include <iostream>

Sed::Sed(std::string filename, std::string findstr, std::string replacestr)
: infilename(filename), outfilename(filename + ".replace"), findstr(findstr), replacestr(replacestr) {}

Sed::~Sed()
{
	in.close();
	out.close();
}

bool	Sed::isvalid()
{
	if (findstr.size() == 0)
	{
		std::cerr << "Input is not valid" << std::endl;
		return (false);
	}
	in.open(infilename.c_str());
	if (!in.is_open())
	{
		std::cerr << "Cannot open infile" << std::endl;
		return (false);
	}
	out.open(outfilename.c_str(), std::ofstream::out);
	if (!out.is_open())
	{
		std::cout << "Cannot open outfile" <<std::endl;
		return (false);
	}
	return (true);
}

void	Sed::doSed()
{
	in.seekg(0, std::ios::end);
	size_t	size = in.tellg();
	in.seekg(std::ios::beg);
	str.resize(size);
	in.read(&str[0], size);
	if (!in)
	{
		std::cerr << "read error" << std::endl;
		return ;
	}
	size_t	pos = 0;
	size_t	findpos = pos;
	while (true)
	{
		findpos = str.find(findstr, pos);
		if (findpos == std::string::npos)
			break;
		out << str.substr(pos, findpos - pos);
		out << replacestr;
		pos = findpos + findstr.size();
	}
	out << str.substr(pos) << std::flush;
}
