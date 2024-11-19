#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string tag)
: AForm("RobotomyRequestForm", 72, 45), target(tag) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
: AForm(other), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::setTarget(std::string target)
{
	this->target = target;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat &Bureaucrat) const {
	if (checkExecute(Bureaucrat) == true) {
		std::srand(std::time(NULL));
			std::cout << "Bzzzzzzzzzzzzzzzz!" << std::endl;
			if (std::rand() % 2 == 0){
				std::cout << this->getTarget() << " has been robotomized successfully " << std::endl;
			}
			else {
				std::cout << this->getTarget() << " that the robotomy failed." << std::endl;
			}
	}
}

AForm *RobotomyRequestForm::clone(std::string target) const
{
	return (new RobotomyRequestForm(target));
}