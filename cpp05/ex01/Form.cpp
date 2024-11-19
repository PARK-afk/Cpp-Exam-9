#include "Form.hpp"

// Create

Form::Form(std::string const &name, int const signGrade, int const executeGrade) 
	: name(name), sign(false), signGrade(signGrade), executeGrade(executeGrade) {
	int const i = this->getSignGrade();
	int const j = this->getExecuteGrade();
	if (i > 150 || j > 150)
		throw Form::GradeTooLowException();
	if (i < 1 || j < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form const &other) 
	: name(other.name), sign(other.sign), signGrade(other.signGrade), executeGrade(other.executeGrade) {}

Form::~Form() {}

// exception

char const *Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

char const *Form::GradeTooLowException::what() const throw() {
	return ("Grad is too low!");
}

// member func

void Form::setSign(bool sign) {
	this->sign = sign;
}

std::string const &Form::getName() const {
	return (this->name);
}

int const &Form::getExecuteGrade() const {
	return (this->executeGrade);
}

int const &Form::getSignGrade() const {
	return (this->signGrade);
}

void Form::beSigned(Bureaucrat &Bureaucrat) {
	if (Bureaucrat.getGrade() <= signGrade) {
		this->setSign(true);
	} else {
		throw GradeTooLowException();
	}
}

bool Form::getSign() const {
	return (this->sign);
}

std::ostream &operator<<(std::ostream& out, Form const &other) {
	out << other.getName() << " Form is ";
	if (other.getSign() == true) {
		out << "signed.";
	} else {
		out << "unsigned.";
	}
	out << " sign able to " << other.getSignGrade() << " grade and Execute able to " << other.getExecuteGrade() << "Grade." << std::endl;
	return (out);
}