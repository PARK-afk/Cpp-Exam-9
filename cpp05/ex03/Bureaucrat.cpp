#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) : _name(name), _grade(grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {}

char const *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

char const *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grad is too low!");
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

std::string const &Bureaucrat::getName() const {
	return (this->_name);
}

int const &Bureaucrat::getGrade() const {
	return (this->_grade);
}

std::ostream &operator<<(std::ostream& out, Bureaucrat const &bureaucrat) {
	out << bureaucrat.getName() << " Bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}

void Bureaucrat::setGrade(int const &grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form){
	if (form.getSign() == false)
		std::cout << form.getName() << " form is not signed" << std::endl;
	else {
		if (form.getExecuteGrade() < this->getGrade())
				throw Bureaucrat::GradeTooLowException();
		else{
			std::cout << this->getName() << " executed " << form.getName() << std::endl;
			form.execute(*this);
		}
	}
}