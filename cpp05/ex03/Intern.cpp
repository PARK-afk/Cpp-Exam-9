#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
	AForm *form[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};
	for (int i = 0; i < 3; i++)
	{
		if (name == form[i]->getName())
		{
			AForm *newform = form[i]->clone(target);
			for (int i = 0; i < 3; i++)
			{
				delete form[i];
			}
			return (newform);
		}
	}
	throw UnknownForm();
}

const char *Intern::UnknownForm::what() const throw()
{
	return ("It's an unknown format name.");
}
