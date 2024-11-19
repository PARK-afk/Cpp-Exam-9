#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	private :
	std::string	target;
	PresidentialPardonForm &operator=(PresidentialPardonForm const &ppf);
	
	public :
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm(std::string target);

	void	setTarget(std::string newTarget);
	std::string	getTarget() const;
	virtual void	execute(Bureaucrat &Bureaucrat) const;
};

#endif