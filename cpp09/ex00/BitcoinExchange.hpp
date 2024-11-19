#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, double> data_;
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &rhs);
	double  GetExchangeRate(std::string const &date);
	bool    dateCheck(std::string const &date);

public:
	BitcoinExchange(std::string const &filename);
	void    ProcessInput(std::string const &filename);
};

#endif
