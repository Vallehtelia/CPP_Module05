/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:37:53 by vvaalant          #+#    #+#             */
/*   Updated: 2024/09/25 17:32:24 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		try
		{
			Bureaucrat	lawyer1("Burre1", 1);
			std::cout << lawyer1 << std::endl;
			Bureaucrat	lawyer2("Burre2", 149);
			std::cout << lawyer2 << std::endl;
			Bureaucrat	lawyer3("Burre3", 75);
			std::cout << lawyer3 << std::endl;
			Bureaucrat	lawyer4("Burre4", 0);
			std::cout << lawyer4 << std::endl;
			Bureaucrat	lawyer5("Burre5", 150);
			std::cout << lawyer5 << std::endl;
		}
		catch (const GradeTooHighException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (const GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n" << std::endl;
	{
		try
		{
			Bureaucrat lawyer1("Burre1", 1);
			std::cout << lawyer1 << std::endl;
			lawyer1.incrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Bureaucrat lawyer2("Burre2", 150);
			std::cout << lawyer2 << std::endl;
			lawyer2.decrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Bureaucrat lawyer3("Burre3", 75);
			std::cout << lawyer3 << std::endl;
			lawyer3.decrementGrade();
			std::cout << lawyer3 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Bureaucrat lawyer4("Burre4", -1);
			std::cout << lawyer4 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Bureaucrat lawyer5("Burre5", 151);
			std::cout << lawyer5 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
