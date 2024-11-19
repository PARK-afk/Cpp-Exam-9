#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <deque>

int main(){
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    std::vector<int>::iterator it = easyfind(arr, 1);

    if (it != arr.end()) {
        std::cout << "Value found in <vector> " << *it << std::endl;
    }
    else {
        std::cout << "Value Not found in <vector>" << std::endl;
    }

    std::list<int> l;
    l.push_back(20);
    l.push_back(1);
    l.push_back(-3);
    l.push_back(5);
    l.push_back(18);
    std::list<int>::iterator lit = easyfind(l, 20);

    if (lit != l.end()) {
        std::cout << "Value found in <list> " << *lit << std::endl;
    } else {
        std::cout << "Value not found in <list>" << std::endl;
    }

    std::deque<int> d;
    d.push_back(15);
    d.push_back(-3);
    d.push_back(7);
    d.push_back(64);
    d.push_back(128);

    std::deque<int>::iterator dit = easyfind(d, -5);

    if (dit != d.end()) {
        std::cout << "Value found in <deque> " << *dit << std::endl;
    } else {
        std::cout << "Value not found in <deque>" << std::endl;
    }


}