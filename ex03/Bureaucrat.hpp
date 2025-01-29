/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:38:01 by vvaalant          #+#    #+#             */
/*   Updated: 2025/01/29 14:18:26 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RED "\033[31m"
#define DEFAULT "\033[0m"

class Bureaucrat
{
	private:
		std::string const name;
		int 		grade;

		Bureaucrat();
	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &bureaucrat);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const &bureaucrat);

		std::string const &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &formToSign);
		void executeForm(AForm const &formToExecute);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return("Grade is too high!");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return("Grade is too low!");
				}
		};
};


std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
