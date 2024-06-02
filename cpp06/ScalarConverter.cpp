#include "ScalarConverter.hpp"
#include <stringstream>

void ScalarConverter::convert(std::string str)
{
    std::stringstream ss;
    ss << str;
    int i;
    float f;
    double d;
    char c;
    ss >> c;
    if (ss.fail())
        std::cout << "char: " << "impossible" << std::endl;
    else
        std::cout << "char: " << c << std::endl;
    ss.clear();
    ss >> i;
    if (ss.fail())
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    ss.clear();
    ss >> f;
    if (ss.fail())
        std::cout << "float: " << "impossible" << std::endl;
    else
        std::cout << "float: " << f << std::endl;
    ss.clear();
    ss >> d;
    if (ss.fail())
        std::cout << "double: " << "impossible" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}