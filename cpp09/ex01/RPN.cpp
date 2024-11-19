#include "RPN.hpp"

int RPN::calculateRPN(std::string const & arg) {
	std::stack<int> stack;

	if (arg.length() <= 2) {
		throw std::invalid_argument("Error: Invalid Argument");
	}

	for (std::string::const_iterator it = arg.begin(); it != arg.end(); it++) {
		if (isdigit(*it)) {
			int ret = *it - '0';
			stack.push(ret);
		} else if (*it == ' ' ) {
			continue;
		} else {
			if (stack.size() < 1) {
				throw std::invalid_argument("Error: Invalid Argument");
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();

            if (*it == '+')
                stack.push(a + b);
            else if (*it == '-')
                stack.push(a - b);
            else if (*it == '*')
                stack.push(a * b);
            else if (*it == '/') {
                if (b == 0)
                    throw std::invalid_argument("Error");
                stack.push(a / b);
            }
            else if (*it == ' ')
                break ;
            else 
                throw std::invalid_argument("Error: invalid operator");
		}
	}
	
	if (stack.size() != 1) {
        throw std::invalid_argument("Invalid Argument");
    }
    return stack.top();
}