#include "ScalarConverter.hpp"

void    ScalarConverter::convert(std::string const &input)
{
    std::string tmp = input;

    if (input.length() == 0)
        std::cout << "Invalid ARG" << std::endl;
    char    charValue;
    int     intValue;
    float   floatValue;
    double  doubleValue;

    if (checkInfNan(input) == true)
        return ;
    if (convertChar(input, charValue) == true)
    {
        if (isprint(charValue) && charValue != '0')
            std::cout << "char: '" << charValue << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    } else
        std::cout << "char: impossible" << std::endl;

    if (convertInt(input, intValue) == true)
        std::cout << "int: " << static_cast<int>(intValue) << std::endl;
    else 
        std::cout << "int: impossible" << std::endl;
    if (convertFloat(input, floatValue) == true)
    {
        std::cout << "float: " << static_cast<float>(floatValue);
        // if (input.find(".") == std::string::npos)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;
    if (convertDouble(input, doubleValue) == true)
    {
        std::cout << "double: " << static_cast<double>(doubleValue);
        // if (input.find(".") == std::string::npos)
            std::cout << ".0";
        std::cout << std::endl;
    }
    else
        std::cout << "double: impossible" << std::endl;
}

bool    ScalarConverter::convertChar(std::string const &input, char &ret)
{
    if (isascii(input.front()) && input.length() == 1)
    {
        ret = input.front();
        return true;
    } else if (!isnumber(input.front()) && input.front() != '-' && input.front() != '+')
    { 
        return false ;
    }
    if (isValid(input) == false)
        return false ;
    std::stringstream str(input);
    int n;
    str >> n;
    ret = static_cast<char>(n);
    if (str.fail())
    {
        str.clear();
        return false ;
    } else
    {
        if (n < 1 || n > 126)
            return false ;
        else
            return true ;
        str.clear();
    }
}

bool    ScalarConverter::convertInt(std::string const &input, int &ret)
{
    int n;
    std::stringstream str(input);
    str >> n;
    ret = static_cast<int>(n);

    if (str.fail())
    {
        str.clear();
        return false ;
    }
    else
    {
        if (isValid(input) == true) return true ;
        else return false ;
    }
    str.clear();
}

bool    ScalarConverter::convertFloat(std::string const &input, float &ret)
{
    float   n;
    std::stringstream str;
	if (input.find_last_of('f') != std::string::npos) {
		str.str(input.substr(0, input.length() - 1));
	} else {
		str.str(input);
	}
	str >> n;
    ret = static_cast<float>(n);
	if (str.fail()) {
		str.clear();
		return (false);
	}
    else {
		str.clear();
		if (isValid(input) == true) return (true); // make func
		else return (false);
	}
}

bool    ScalarConverter::convertDouble(std::string const &input, double &ret)
{
    double  n;
    std::stringstream str;
    if (input.find_last_of('f') != std::string::npos)
    {
        str.str(input.substr(0, input.length() - 1));
    }
    else
        str.str(input);
    str >> n;
    ret = static_cast<double>(n);
    if (str.fail())
    {
        str.clear();
        return false ;
    }
    else
    {
        str.clear();
        if (isValid(input) == true) return true ;
        else return false ;
    }
}

bool    isValid(std::string const &input)
{
    size_t pos = input.find(".");
    if (isNumeric(input) == false && pos == std::string::npos)
        return false ;
    if (pos != std::string::npos && isNumeric(input.substr(pos + 1)) == false)
    {
        return false ;   
    }
    if (pos != std::string::npos && isNumeric(input.substr(pos + 1)) == false)
    {
        return false ;
    }
    return true ;
}

bool isNumeric(std::string const &str) {
	size_t pos;

	if (str.length() == 0)
		return (false);
	if ((pos = str.find('-')) == std::string::npos) {
		pos = str.find('+');
	}
    for (size_t i = pos + 1; i < str.length(); i++) {
        if (!isdigit(str[i])) {
			if (i == str.length() - 1 && str[i] == 'f')
				return (true);
            return false;
        }
    }
    return true;
}

bool    ScalarConverter::checkInfNan(std::string const &input)
{
    if (input == "nan" || input == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "float: nan" << std::endl;
		return true;
    }
    if (input == "+inff" || input == "inff" || input == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << "inf" << std::endl;
		std::cout << "float: " << "inf" << std::endl;
		std::cout << "double: " << "inf" << std::endl;
		return true;
    }
    if (input == "-inff" || input == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << "-inf" << std::endl;
		std::cout << "float: " << "-inf" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
		return true;
    }
    return false;
}
