#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange& ref);
	~BitcoinExchange();
	BitcoinExchange& operator=(BitcoinExchange& ref);

	void	run(int argc, char* argv[]);
	void	recvData();
	bool	isDateValid(std::string& date);
	bool	isLeapYear(int year);

	class BtcOpenException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	class BtcInvalidDataException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	class BtcBadInputException : public std::exception
	{
	public:
		BtcBadInputException(std::string& str);
        virtual ~BtcBadInputException() throw();
		virtual const char*	what() const throw();
	private:
		std::string	msg;
	};

	class BtcInvalidDateException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	class BtcInvalidNumberException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	class BtcTooLargeNumberException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	class BtcTooSmallNumberException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

private:
	std::map<std::string, double>	map;

};

#endif
