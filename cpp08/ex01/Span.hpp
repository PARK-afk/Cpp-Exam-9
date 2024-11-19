#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

class Span
{
    private:
    unsigned int        size;
    std::vector<int>    arr;

    public:
    // condis
    Span();
    Span(unsigned int size);
    Span(Span const &other);
    ~Span();

    Span            &operator=(Span const &other);
    void            addNumber(int num);
    unsigned int    getSize() const;
    int             shortestSpan();
    int             longestSpan();
    
    template <typename ITER>
    void easyAdd(ITER start, ITER end) {
        for (ITER it = start; it != end; ++it) {
            if (arr.size() >= this->size)
                throw std::out_of_range("Index out of range ");
            arr.push_back(*it);
        }
    }

    // template <typename ITER>
    void printArr() const {
        for (std::vector<int>::const_iterator it = arr.begin(); it != arr.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};

#endif
