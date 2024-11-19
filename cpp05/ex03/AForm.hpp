#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const name;
		bool sign;
		int const signGrade;
		int const executeGrade;
	
		AForm();
		AForm &operator=(AForm const &other);
	public:
		AForm(std::string const &name, int const signGrade, int const executeGrade);
		AForm(AForm const &other);
		virtual ~AForm();
		virtual AForm *clone(std::string target) const = 0;

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
		bool checkExecute(Bureaucrat &Bureaucrat) const;
		bool getSign() const;
		void verifyGrade(int grade);
		virtual void execute(Bureaucrat &Bureaucrat) const = 0;
};

std::ostream &operator<<(std::ostream& out, AForm const &obj);

#endif