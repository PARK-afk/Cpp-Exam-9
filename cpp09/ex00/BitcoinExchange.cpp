#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

BitcoinExchange::BitcoinExchange(std::string const &fileName) {
    if (fileName.substr(fileName.find_last_of(".") + 1) != "csv")
        throw std::runtime_error("Error: file must have .csv extension.");
	std::ifstream file(fileName.c_str());
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
	while (std::getline(file, line)) {
		std::string::size_type delimiter_pos = line.find(',');
		if (delimiter_pos == std::string::npos) {
			std::cerr << "Error: Invalid format in database => " << line << '\n';
			continue;
		}

		std::string date = line.substr(0, delimiter_pos);
		std::string rate_str = line.substr(delimiter_pos + 1);

		double rate;
		std::istringstream rate_stream(rate_str);
		if (!(rate_stream >> rate)) {
			std::cerr << "Error: Invalid rate format in database => " << rate_str << '\n';
			continue;
		}

		data_[date] = rate;
	}
}

double BitcoinExchange::GetExchangeRate(std::string const &date) {
	std::map<std::string, double>::iterator it = data_.lower_bound(date);

	if (it->first != date && it != data_.begin()) {
		--it;
	}

	if (it != data_.end()) {
		return it->second;
	} else if (!data_.empty()) {
		return it->second;
	}

	return -1.0;
}

bool BitcoinExchange::dateCheck(std::string const &date) {
	std::string::size_type hyphenFirst = date.find('-');
	std::string::size_type hyphenSecond = date.rfind('-');

	if (hyphenFirst == std::string::npos || hyphenFirst == hyphenSecond)
		return false;

	std::string year_str = date.substr(0, hyphenFirst);
	std::string month_str = date.substr(hyphenFirst + 1, hyphenSecond - hyphenFirst - 1);
	std::string day_str = date.substr(hyphenSecond + 1);
	
    int year, month, day;
	std::istringstream year_ss(year_str), month_ss(month_str), day_ss(day_str);

	if (!(year_ss >> year) || !(month_ss >> month) || !(day_ss >> day))
		return false;

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30)
			return false;
	}

	if (month == 2) {
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) {
			return false;
		}
	}

	return true;
}

void BitcoinExchange::ProcessInput(std::string const &fileName) {
    if (fileName.empty())
    {
        std::cerr << "Error: DATABASE EMPTY" << std::endl;
        return ;
    }
	std::ifstream file(fileName);
    if (file.fail())
    {
        std::cerr << "Error: READ INPUT DATA FAIL" << std::endl;
        return ;
    }
    
	std::string line;
	std::getline(file, line);
    if (file.eof() || line.empty() || line != "date | value")
    {
        std::cerr << "Error: NO DATABASE EXIST" << std::endl;
        return ;
    }

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date;
		double value;
		char sep;

		if (!(ss >> date >> sep >> value)) {
			std::cerr << "Error: bad input => " << line << '\n';
			continue;
		}

		if (sep != '|') {
			std::cerr << "Error: Expected '|' sep in line => " << line << '\n';
			continue;
		}

		if (!dateCheck(date)) {
			std::cerr << "Error: Invalid file format => " << line << '\n';
			continue;
		}

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue ;
        }
        else if (value > 1000)
        {
            std::cerr << "Error: too large number." << std::endl;
            continue ;
        }

		double exchangeRate = GetExchangeRate(date);
		if (exchangeRate == -1.0) {
			std::cerr << "Error: No exchange rate available for date => " << date << '\n';
			continue;
		}

		std::cout << date << " => " << value << " = " << value * exchangeRate << '\n';
	}
}
