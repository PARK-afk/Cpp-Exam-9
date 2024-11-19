#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe &operator=(PmergeMe const &other);
	~PmergeMe();

public:
	static void PmergeExecute(int ac, char **av);
};

#endif