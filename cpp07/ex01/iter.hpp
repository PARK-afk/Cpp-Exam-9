#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T, typename F>
void    iter(T *array, size_t length, F func)
{
    // (void)array;
    for (size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
    // func(length);
}

template <typename T>
void    printTemplate(const T &arg)
{
    std::cout << arg << std::endl;
}

// template <typename T>
// void    printLength(const T &arg)
// {
//     std::cout << arg << "a" << std::endl;
// }

#endif