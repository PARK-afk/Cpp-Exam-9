#ifndef INTERN
#define INTERN

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
	private:
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	
	public:
	Intern();
	~Intern();

	AForm *makeForm(std::string const &name, std::string const &target);

	class UnknownForm : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
};

#endif
