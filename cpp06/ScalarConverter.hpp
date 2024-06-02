#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(ScalarConverter& ref);
    ScalarConverter& operator=(ScalarConverter& ref);
public:
    static void convert(std::string str);
}

#endif
