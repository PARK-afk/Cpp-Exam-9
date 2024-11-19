#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 100);
        Form taxForm("Tax Form", 50, 120);
        
        std::cout << john << std::endl;
        std::cout << taxForm << std::endl;
        
        john.signForm(taxForm);
        std::cout << taxForm << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
