/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intrern.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:50:49 by vvaalant          #+#    #+#             */
/*   Updated: 2024/11/09 23:59:57 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern is born" << std::endl;
	_formNames[0] = "shrubbery creation";
	_formNames[1] = "robotomy request";
	_formNames[2] = "presidential pardon";
	_formCreators[0] = &Intern::createShrubberyCreationForm;
	_formCreators[1] = &Intern::createRobotomyRequestForm;
	_formCreators[2] = &Intern::createPresidentialPardonForm;
}

Intern::Intern(Intern const & src)
{
	(void)src;
	std::cout << "Intern is born by copy" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern is dead" << std::endl;
}

Intern & Intern::operator=(Intern const & src)
{
	(void)src;
	std::cout << "Intern is assigned" << std::endl;
	return *this;
}

AForm * Intern::makeForm(std::string const & formName, std::string const & target)
{
	for (int i = 0; i < 3; i++)
	{
		if (formName == _formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*_formCreators[i])(target);
		}
	}
	throw FormNotFoundException();
}

AForm *Intern::createShrubberyCreationForm(std::string const & target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string const & target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string const & target)
{
	return new PresidentialPardonForm(target);
}
