#include "iter.hpp"

int main( void ) {
    int a[10];
    std::string str[10];
    char b[5];
    
    for (int i = 0; i < 10; i++){
        a[i] = i;
    }
    str[0] = "ecole";
    str[1] = "gago";
    str[2] = "ship";
    str[3] = "da";
    str[4] = "jogeum";
    str[5] = "man";
    str[6] = "gida";
    str[7] = "ryura";
    str[8] = "ne ga";
    str[9] = "ganda";

    b[0] = 'H';
    b[1] = 'E';
    b[2] = 'L';
    b[3] = 'L';
    b[4] = 'O';

    ::iter(a, 10, printTemplate<int>);
    std::cout << std::endl;
    ::iter(str, 10, printTemplate<std::string>);
    std::cout << std::endl;
    ::iter(b, 5, printTemplate<char>);
    std::cout << std::endl;
    // ::iter(a, 10, printLength<size_t>);
    // std::cout << std::endl;
    // ::iter(str, 10, printLength<size_t>);
    // std::cout << std::endl;
    // ::iter(b, 5, printLength<size_t>);
    return 0;
}