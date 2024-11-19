#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main(void)
{
	try
	{
        Bureaucrat br("jun", 3);
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "home");
		// rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "home");
        // rrf = someRandomIntern.makeForm("PresidentialPardonForm", "home");
		std::cout << rrf->getName() << std::endl;
		std::cout << *rrf << std::endl;
        br.signForm(*rrf);
        br.executeForm(*rrf);
		delete rrf;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		return (0);
	}
	return (0);
}