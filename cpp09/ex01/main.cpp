#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error: ./RPN [Argument]" << std::endl;
        return 1;
    }
    try {
        std::string a = av[1];
        int result = RPN::calculateRPN(a);
        std::cout << result << std::endl; 
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}