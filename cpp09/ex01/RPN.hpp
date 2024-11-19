#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>


class RPN 
{
	private:
		RPN();
		~RPN();
		RPN(RPN const & other);
		RPN & operator=(RPN const & other);
	public:
		static int calculateRPN(std::string const & str);
};

#endif