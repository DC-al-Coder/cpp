#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange& ref) : map(ref.map) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& ref)
{
	map = ref.map;
	return *this;
}

void	BitcoinExchange::run(int argc, char* argv[])
{
	std::ifstream	inputstream;
	std::string		string;
	std::string		key;
	std::string		val;
	size_t			pos;
	double			d;

	if (argc != 2)
		throw BtcOpenException();

	recvData();

	inputstream.open(argv[1]);
	if (!inputstream.is_open())
		throw BtcOpenException();
	if (!std::getline(inputstream, string))
		throw BtcBadInputException(string);
	if (string != "date | value")
		throw BtcBadInputException(string);
	while (std::getline(inputstream, string))
	{
		try
		{
			pos = string.find(" | ");
			if (pos == std::string::npos)
				throw BtcBadInputException(string);
			key = string.substr(0, pos);
			if (!isDateValid(key))
				throw BtcBadInputException(string);
			val = string.substr(pos + 3, std::string::npos);
			std::stringstream	ss(val);
			ss >> d;
			if (ss.fail() || !ss.eof())
				throw BtcInvalidNumberException();
			if (d <= 0)
				throw BtcTooSmallNumberException();
			else if (d >= 1000)
				throw BtcTooLargeNumberException();
			std::map<std::string, double>::iterator it = map.lower_bound(key);
			if (it == map.begin() && key != it->first)
				throw BtcInvalidDateException();
			else if (it == map.end() || it->first != key)
				it--;
			std::cout << key << " => " << val << " = " << it->second * d << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	if (!inputstream.fail())
		throw BtcBadInputException(string);
}

void	BitcoinExchange::recvData()
{
	std::stringstream	ss;
	std::ifstream		ifstream;
	std::string			string;
	float				f;
	size_t				i = 0;

	ifstream.open("data.csv");
	if (!ifstream.is_open())
		throw BtcOpenException();
	while (std::getline(ifstream, string, '\n'))
	{
		if (i == 0)
		{
			if(string != "date,exchange_rate")
				throw BtcInvalidDataException();
			i++;
			continue;
		}
		size_t pos = string.find(',');
		if (pos == std::string::npos)
			throw BtcInvalidDataException();
		std::string key = string.substr(0, pos);
		std::string val = string.substr(pos + 1, std::string::npos);
		std::stringstream ss(val);
		ss >> f;
		if (ss.fail() || !ss.eof())
			throw BtcInvalidDataException();
		map[key] = f;
		i++;
	}
}

bool	BitcoinExchange::isDateValid(std::string& date)
{
	std::stringstream	ss(date);
	int					year;
	int					month;
	int					day;
	char				dash1;
	char				dash2;
	int					maxday = 30;
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	ss >> year >> dash1 >> month >> dash2 >> day;
	if (ss.fail() || dash1 != '-' || dash2 != '-' || !ss.eof())
		return false;
	if (month < 1 || month > 12)
		return false;
	if (month % 2 == 1)
		maxday = 31;
	else if (month == 2)
	{
		if (isLeapYear(year))
			maxday = 29;
		else
			maxday = 28;
	}
	if (day < 1 || day > maxday)
		return false;
	return true;
}

bool	BitcoinExchange::isLeapYear(int year)
{
	if (year % 4)
		return false;
	if (year % 100 == 0 && year % 400)
		return false;
	return true;
}

const char*	BitcoinExchange::BtcOpenException::what() const throw()
{
	return "Error: could not open file.";
}

const char*	BitcoinExchange::BtcInvalidDataException::what() const throw()
{
	return "Error: data is invalid.";
}

BitcoinExchange::BtcBadInputException::BtcBadInputException(std::string& str)
: msg("Error: bad input => " + str) {}

const char*	BitcoinExchange::BtcBadInputException::what() const throw()
{
	return msg.c_str();
}

BitcoinExchange::BtcBadInputException::~BtcBadInputException() throw(){}


const char*	BitcoinExchange::BtcInvalidDateException::what() const throw()
{
	return "Error: not a valid date.";
}

const char*	BitcoinExchange::BtcInvalidNumberException::what() const throw()
{
	return "Error: not a valid number.";
}

const char*	BitcoinExchange::BtcTooLargeNumberException::what() const throw()
{
	return "Error: too large a number.";
}

const char*	BitcoinExchange::BtcTooSmallNumberException::what() const throw()
{
	return "Error: not a positive number.";
}
