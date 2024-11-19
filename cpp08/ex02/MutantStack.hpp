#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {};
		~MutantStack() {};
		MutantStack(MutantStack const &other) : std::stack<T>(other) {}
		MutantStack &operator=(MutantStack const &other) {
			this->c = other.c;
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }
		
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin(void) {return this->c.rbegin();}
		reverse_iterator rend(void) {return this->c.rend();}
};

#endif