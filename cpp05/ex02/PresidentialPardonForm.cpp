#include "PresidentialPardonForm.hpp"

// constructor 
PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ppf)
: AForm(ppf), target(ppf.target) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), target(target) {}


// function

void	PresidentialPardonForm::setTarget(std::string newTarget)
{
	this->target = newTarget;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void	PresidentialPardonForm::execute(Bureaucrat &bc) const
{
	if (checkExecute(bc) == true)
	{
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}