#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
	std::string target;
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const &scf);
	public:
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm(std::string target);

	std::string getTarget();
	void	setTarget(std::string target);
	void	makeTree() const;
	virtual void execute(Bureaucrat &br) const;
};

#endif