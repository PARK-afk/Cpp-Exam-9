#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>

template<typename T>
void    swap(T &a, T&b)
{
    T   tmp;
    
    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T   min(T const &a, T const &b)
{
    if (a < b) return a;
    else        return b;
}

template<typename T>
T   max(T const &a, T const &b)
{
    if (a > b) return a;
    else        return b;
}

#endif
