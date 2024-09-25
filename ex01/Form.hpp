/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:10:54 by vvaalant          #+#    #+#             */
/*   Updated: 2024/09/25 20:03:28 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		bool				_signed;
		int	const			grade_to_sign;
		int	const			grade_to_execute;
	public:
		Form();
		Form(std::string name, int const to_sign, int const to_execute);
		Form(Form const &other);
		Form &operator=(Form const &other) = delete;
		~Form();

		std::string getName() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;

		void		beSigned(Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
