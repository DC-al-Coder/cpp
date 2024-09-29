#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <cctype>

Rpn::Rpn() : oprtr(UNKNOWN) {}

Rpn::Rpn(Rpn& ref) : stck(ref.stck), oprtr(ref.oprtr) {}

Rpn::~Rpn() {}

Rpn& Rpn::operator=(Rpn& ref)
{
	stck = ref.stck;
	oprtr = ref.oprtr;
	return *this;
}

void	Rpn::run(int argc, char* argv[])
{
	if (argc != 2)
		throw RpnException();
	std::stringstream	ss(argv[1]);
	std::string			str;
	while (1)
	{
		if (ss.eof())
			break ;
		ss >> str;
		if (str.size() != 1)
			throw RpnException();
		if (isOprtr(str))
		{
			if (stck.size() < 2)
				throw RpnException();
			int second = stck.top();
			stck.pop();
			int first = stck.top();
			stck.pop();
			switch (oprtr)
			{
				case PLUS:
				{
					stck.push(first + second);
					break ;
				}
				case MINUS:
				{
					stck.push(first - second);
					break ;
				}
				case MULTIPLY:
				{
					stck.push(first * second);
					break ;
				}
				case DIVIDE:
				{
					if (second == 0)
						throw RpnException();
					stck.push(first / second);
					break ;
				}
				case UNKNOWN:
					throw RpnException();
			}
		}
		else if (std::isdigit(str[0]))
		{
			std::stringstream tmp(str);
			int i;
			tmp >> i;
			stck.push(i);
		}
		else
			throw RpnException();
	}
	if (stck.size() != 1)
		throw RpnException();
	std::cout << stck.top() << std::endl;
	return ;
}

bool	Rpn::isOprtr(std::string& str)
{
	if (str[0] == '+')
		oprtr = PLUS;
	else if (str[0] == '-')
		oprtr = MINUS;
	else if (str[0] == '*')
		oprtr = MULTIPLY;
	else if (str[0] == '/')
		oprtr = DIVIDE;
	else
		oprtr = UNKNOWN;
	if (oprtr == UNKNOWN)
		return false;
	return true;
}

const char*	Rpn::RpnException::what() const throw()
{
	return "Error";
}
