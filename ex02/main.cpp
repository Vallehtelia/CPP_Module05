/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:37:53 by vvaalant          #+#    #+#             */
/*   Updated: 2024/11/09 23:42:24 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	{
		try
		{
			std::cout << CYAN << "\n------------------------------------------------------" << std::endl;
			Bureaucrat b1("Bureaucrat 1", 1);
			std::cout << b1 << "tries to sign forms" << DEFAULT << std::endl;

			PresidentialPardonForm f1("target1");
			RobotomyRequestForm f2("target2");
			ShrubberyCreationForm f3("target3");

			b1.executeForm(f1);
			b1.executeForm(f2);
			b1.executeForm(f3);

			b1.signForm(f1);
			b1.signForm(f2);
			b1.signForm(f3);

			b1.executeForm(f1);
			b1.executeForm(f2);
			b1.executeForm(f3);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << DEFAULT << '\n';
		}
	}
	{
		try
		{
			std::cout << CYAN << "\n------------------------------------------------------" << std::endl;
			Bureaucrat b2("Bureaucrat 2", 150);
			std::cout << b2 << "tries to sign forms" << DEFAULT << std::endl;

			PresidentialPardonForm f1("target1");
			RobotomyRequestForm f2("target2");
			ShrubberyCreationForm f3("target3");


			b2.signForm(f1);
			b2.signForm(f2);
			b2.signForm(f3);

			b2.executeForm(f1);
			b2.executeForm(f2);
			b2.executeForm(f3);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << DEFAULT << '\n';
		}
	}
	{
		try
		{
			std::cout << CYAN << "\n------------------------------------------------------" << std::endl;
			Bureaucrat b3("Bureaucrat 3", 25);
			Bureaucrat b4("Bureaucrat 4", 5);
			std::cout << b3 << "tries to sign forms" << DEFAULT << std::endl;

			PresidentialPardonForm f1("target1");
			RobotomyRequestForm f2("target2");
			ShrubberyCreationForm f3("target3");

			b3.signForm(f1);
			b3.signForm(f2);
			b3.signForm(f3);

			b3.executeForm(f1);
			b3.executeForm(f2);
			b3.executeForm(f3);

			std::cout << CYAN << b4 << "tries to execute forms" << DEFAULT << std::endl;

			b4.executeForm(f1);
			b4.executeForm(f2);
			b4.executeForm(f3);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << DEFAULT << '\n';
		}

	}

}
