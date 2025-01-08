/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:10:54 by vvaalant          #+#    #+#             */
/*   Updated: 2024/11/10 00:07:32 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;
class AForm
{
	private:
		std::string const	name;
		bool				_signed;
		int	const			grade_to_sign;
		int	const			grade_to_execute;
	public:
		AForm();
		AForm(std::string name, int const to_sign, int const to_execute);
		AForm(AForm const &other);
		AForm &operator=(AForm const &other) = delete;
		virtual ~AForm();

		std::string		getName() const;
		bool			getSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExec() const;

		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;


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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return("Form is not signed!");
				}
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
