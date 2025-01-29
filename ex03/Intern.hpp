/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:48:35 by vvaalant          #+#    #+#             */
/*   Updated: 2025/01/29 14:19:10 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm *createShrubberyCreationForm(std::string const & target);
		AForm *createRobotomyRequestForm(std::string const & target);
		AForm *createPresidentialPardonForm(std::string const & target);
		AForm *(Intern::*_formCreators[3])(std::string const & target);
		std::string _formNames[3];
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();

		Intern & operator=(Intern const & src);

		AForm * makeForm(std::string const & formName, std::string const & target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char * what() const throw()
				{
					return ("Form not found!");
				}
		};
};

#endif
