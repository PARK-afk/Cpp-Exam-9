#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <exception>

class ScalarConverter
{
private:
    /* data */
public:
    static void    convert(std::string const &input);
    static bool    checkInfNan(std::string const &input);
    static bool    convertChar(std::string const &input, char &charValue);
    static bool    convertInt(std::string const &input, int &charValue);
    static bool    convertFloat(std::string const &input, float &charValue);
    static bool    convertDouble(std::string const &input, double &charValue);
};

bool    isNumeric(std::string const &str);
bool    isValid(std::string const &input);

#endif