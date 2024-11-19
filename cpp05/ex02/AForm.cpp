#include "AForm.hpp"

// Create

AForm::AForm(std::string const &name, int const signGrade, int const executeGrade) 
	: name(name), sign(false), signGrade(signGrade), executeGrade(executeGrade) {
	verifyGrade(signGrade);
	verifyGrade(executeGrade);
}

AForm::AForm(AForm const &other) 
	: name(other.name), sign(other.sign), signGrade(other.signGrade), executeGrade(other.executeGrade) {}

AForm::~AForm() {}

// exception

void AForm::verifyGrade(int grade) {
    if (grade < 1) throw Bureaucrat::GradeTooHighException();
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
}

char const *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

char const *AForm::GradeTooLowException::what() const throw() {
	return ("Grad is too low!");
}

// member func

void AForm::setSign(bool sign) {
	this->sign = sign;
}

std::string const &AForm::getName() const {
	return (this->name);
}

int const &AForm::getExecuteGrade() const {
	return (this->executeGrade);
}

int const &AForm::getSignGrade() const {
	return (this->signGrade);
}

void AForm::beSigned(Bureaucrat &Bureaucrat) {
	if (Bureaucrat.getGrade() <= signGrade) {
		this->setSign(true);
	} else {
		throw AForm::GradeTooLowException();
	}
}

bool AForm::checkExecute(Bureaucrat &Bureaucrat) const {
	if (this->getSign() == false) {
		std::cout << this->getName() << " form is not signed." << std::endl;
	} else {
		if (this->getExecuteGrade() < Bureaucrat.getGrade()) {
			throw AForm::GradeTooLowException();
		} else {
			return (true);
		}
	}
	return (false);
}

bool AForm::getSign() const {
	return (this->sign);
}

std::ostream &operator<<(std::ostream& out, AForm const &other) {
	out << other.getName() << " AForm is ";
	if (other.getSign() == true) {
		out << "signed.";
	} else {
		out << "unsigned.";
	}
	out << " sign able to " << other.getSignGrade() << " grade and Execute able to " << other.getExecuteGrade() << "Grade." << std::endl;
	return (out);
}