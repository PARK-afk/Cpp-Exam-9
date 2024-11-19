#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int Value) {
    return std::find(container.begin(), container.end(), Value);
}


#endif