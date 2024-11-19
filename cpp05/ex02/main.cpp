#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
	Bureaucrat bureaucrat("John", 2);
	// AForm *form = new RobotomyRequestForm("home");
	// AForm *form = new PresidentialPardonForm("home");
    AForm *form = new ShrubberyCreationForm("home");
	std::cout << "---------- 1 TRY -------------" << std::endl;
    try {
        bureaucrat.executeForm(*form);
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
	std::cout << "---------- 2 TRY -------------" << std::endl;
    try {
        bureaucrat.setGrade(160);
        bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
    } catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
    }
	std::cout << "---------- 3 TRY -------------" << std::endl;
    try {
        bureaucrat.setGrade(1);
		bureaucrat.signForm(*form);
        bureaucrat.executeForm(*form);
    } catch (const std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
    }
    delete form;
    return 0;
}