#ifndef Form_HPP
# define Form_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
	private:
		std::string const name;
		bool sign;
		int const signGrade;
		int const executeGrade;
	
		Form();
		Form &operator=(Form const &other);
	public:
		Form(std::string const &name, int const signGrade, int const executeGrade);
		Form(Form const &other);
		~Form();

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

		void setSign(bool sign);
		std::string const &getName() const;
		int const &getSignGrade() const;
		int const &getExecuteGrade() const;
		void beSigned(Bureaucrat &Bureaucrat);
		bool getSign() const;
};

std::ostream &operator<<(std::ostream& out, Form const &obj);

#endif