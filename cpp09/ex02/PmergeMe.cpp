#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
		return *this;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

bool validCheck(int a, int b)
{
	return (a < b);
}

int Insertion(int x, const std::vector<int> &vec)
{
	int low = 0;
	int high = vec.size();
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (validCheck(x, vec[mid]))
			high = mid;
		else if (validCheck(vec[mid], x))
			low = mid + 1;
		else
			return mid;
	}
	return low;
}

void vectorMergeSort(std::vector<int> &vec)
{
	if (vec.size() < 2)
		return;

	std::vector<std::vector<int> > partner;
	int half = vec.size() / 2;
	for (int i = 0; i < half; ++i)
	{
		if (validCheck(vec[i], vec[i + half]))
			std::swap(vec[i], vec[i + half]);
		int idx = vec[i];
		std::cout << vec[i];
		if (idx >= static_cast<int>(partner.size()))
			partner.resize(idx + 1);
		partner[idx].push_back(vec[i + half]);
	}

	std::vector<int> first_half(vec.begin(), vec.begin() + half);
	vectorMergeSort(first_half);
	std::copy(first_half.begin(), first_half.end(), vec.begin());

	for (int i = 0; i < half; ++i)
	{
		int y = partner[vec[2 * i]].back();
		partner[vec[2 * i]].pop_back();

		int idx = Insertion(y, std::vector<int>(vec.begin(), vec.begin() + 2 * i));
		vec.insert(vec.begin() + idx, y);
		vec.erase(vec.begin() + half + i + 1);
	}

	if (vec.size() % 2 > 0)
	{
		int i = vec.size() - 1;
		int idx = Insertion(vec[i], std::vector<int>(vec.begin(), vec.begin() + i));
		vec.insert(vec.begin() + idx, vec[i]);
		vec.pop_back();
	}
}

int Insertion(int x, const std::deque<int> &deque) {
    int low = 0;
    int high = deque.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (validCheck(x, deque[mid]))
            high = mid;
        else if (validCheck(deque[mid], x))
            low = mid + 1;
        else
            return mid;
    }
    return low;
}

void dequeMergeSort(std::deque<int> &deque)
{
    if (deque.size() < 2)
        return;

    std::vector<std::deque<int> > partner;
    int half = deque.size() / 2;
    for (int i = 0; i < half; ++i) {
        if (validCheck(deque[i], deque[i + half]))
            std::swap(deque[i], deque[i + half]);
        int idx = deque[i];
        if (idx >= static_cast<int>(partner.size()))
            partner.resize(idx + 1);
        partner[idx].push_back(deque[i + half]);
    }

    std::deque<int> first_half(deque.begin(), deque.begin() + half);
    dequeMergeSort(first_half);
    std::copy(first_half.begin(), first_half.end(), deque.begin());

    for (int i = 0; i < half; ++i) {
        int y = partner[deque[2 * i]].back();
        partner[deque[2 * i]].pop_back();

        int idx = Insertion(y, std::deque<int>(deque.begin(), deque.begin() + 2 * i));
        deque.insert(deque.begin() + idx, y);
        deque.erase(deque.begin() + half + i + 1);
    }

    if (deque.size() % 2 > 0) {
        int i = deque.size() - 1;
        int idx = Insertion(deque[i], std::deque<int>(deque.begin(), deque.begin() + i));
        deque.insert(deque.begin() + idx, deque[i]);
        deque.pop_back();
    }
}

void PmergeMe::PmergeExecute(int ac, char **av)
{
	std::stringstream ss;
	std::vector<int> vec;
	std::deque<int> deque;
	int num;

	for (int i = 1; i < ac; i++)
	{
		ss << av[i];
		while (!ss.eof())
		{
			ss >> num;
			if (ss.fail() || num < 0)
				throw std::invalid_argument("Error");
			else
			{
				if (std::find(vec.begin(), vec.end(), num) == vec.end())
				{
					vec.push_back(num);
					deque.push_back(num);
				}
			}
		}
		ss.clear();
	}

	std::vector<int> vecBefore = vec;
	clock_t vStart = clock();
	vectorMergeSort(vec);
	clock_t vEnd = clock();

	clock_t dStart = clock();
	dequeMergeSort(deque);
	clock_t dEnd = clock();

	std::cout << "Before: ";
	for (size_t i = 0; i < vecBefore.size(); i++)
	{
		std::cout << vecBefore[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	double vTime = static_cast<double>(vEnd - vStart) / CLOCKS_PER_SEC;
	double dTime = static_cast<double>(dEnd - dStart) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << std::fixed << std::setprecision(6) << vTime << " us" << std::endl;
	std::cout << "Time to process a range of " << std::fixed << std::setprecision(6) << dTime << " us" << std::endl;
}