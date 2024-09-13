#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		std::string const name;
		int 		grade;
	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &bureaucrat);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &bureaucrat);

		std::string const &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		std::ostream &operator<<
};

class GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif