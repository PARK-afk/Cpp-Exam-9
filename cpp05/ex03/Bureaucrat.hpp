#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class  Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	
		Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &other);
	public:
		Bureaucrat(std::string const &name, int const &grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				char const *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				char const * what() const throw();
		};

		void incrementGrade();
		void decrementGrade();
		void setGrade(int const &grade);
		std::string const &getName() const;
		int const &getGrade() const;
		void signForm(AForm &form);
		void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream& out, Bureaucrat const &other);

#endif