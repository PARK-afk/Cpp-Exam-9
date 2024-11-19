#include "Span.hpp"
#include <vector>
int main()
{
	try {
		Span a;
		std::cout << &a << std::endl;
		Span sp(5);
		std::vector<int> arr;
		arr.push_back(-1);
		arr.push_back(6);
		arr.push_back(3);
		arr.push_back(17);
		arr.push_back(0);
		sp.easyAdd(arr.begin(), arr.end());
		sp.printArr();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}