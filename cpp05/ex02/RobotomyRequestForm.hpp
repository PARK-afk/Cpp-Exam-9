#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
	std::string target;
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rrf);
	public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &other);

	void	setTarget(std::string tg);
	std::string getTarget() const;
	virtual void execute(Bureaucrat &Bureaucrat) const;
};

#endif