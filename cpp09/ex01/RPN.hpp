#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <exception>

enum Oprtr
{
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE,
	UNKNOWN
};

class Rpn
{
public:
	Rpn();
	Rpn(Rpn& ref);
	~Rpn();
	Rpn& operator=(Rpn& ref);

	void	run(int argc, char* argv[]);
	bool	isOprtr(std::string& str);

	class	RpnException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	std::stack<int>		stck;
	enum Oprtr			oprtr;
};

#endif
