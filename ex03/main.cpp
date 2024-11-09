/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:37:53 by vvaalant          #+#    #+#             */
/*   Updated: 2024/11/10 00:13:02 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	{
		try
		{
			std::cout << CYAN << "\n------------------------------------------------------" << std::endl;
			Bureaucrat	bureaucrat1("bureaucrat1", 1);
			Intern	intern1;
			AForm	*someForm;
			std::cout << "------------------------------------------------------" << DEFAULT << std::endl;

			someForm = intern1.makeForm("shrubbery creation", "home");
			std::cout << *someForm << std::endl;
			bureaucrat1.signForm(*someForm);
			bureaucrat1.executeForm(*someForm);
			if (someForm)
				delete someForm;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << CYAN << "\n------------------------------------------------------" << std::endl;
			Bureaucrat	bureaucrat2("bureaucrat2", 1);
			Intern	intern2;
			AForm	*someForm;
			std::cout << "------------------------------------------------------" << DEFAULT << std::endl;

			someForm = intern2.makeForm("robotomy request", "home");
			std::cout << *someForm << std::endl;
			bureaucrat2.signForm(*someForm);
			bureaucrat2.executeForm(*someForm);
			if (someForm)
				delete someForm;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << CYAN << "\n------------------------------------------------------" << std::endl;
			Bureaucrat	bureaucrat3("bureaucrat3", 1);
			Intern	intern3;
			AForm	*someForm;
			std::cout << "------------------------------------------------------" << DEFAULT << std::endl;

			someForm = intern3.makeForm("presidential pardon", "home");
			std::cout << *someForm << std::endl;
			bureaucrat3.signForm(*someForm);
			bureaucrat3.executeForm(*someForm);
			if (someForm)
				delete someForm;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << CYAN << "\n------------------------------------------------------" << std::endl;
			Bureaucrat	bureaucrat4("bureaucrat4", 1);
			Intern	intern4;
			AForm	*someForm;
			std::cout << "------------------------------------------------------" << DEFAULT << std::endl;

			someForm = intern4.makeForm("not found", "home");
			std::cout << *someForm << std::endl;
			bureaucrat4.signForm(*someForm);
			bureaucrat4.executeForm(*someForm);
			if (someForm)
				delete someForm;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << DEFAULT << '\n';
		}
	}
}
