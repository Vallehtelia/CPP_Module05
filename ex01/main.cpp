/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:37:53 by vvaalant          #+#    #+#             */
/*   Updated: 2024/11/09 22:12:50 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	{
		Bureaucrat	Burry1("Burry1", 10);
		Bureaucrat	Burry2("Burry2", 1);
		Bureaucrat	Burry3("Burry3", 150);
		Bureaucrat	Burry4("Burry4", 75);
		std::cout << std::endl;
		Form		Form1;
		std::cout << Form1 << std::endl;
		Form		Form2("Marriage licence", 50, 50);
		std::cout << Form2 << std::endl;
		Form		Form3("Constitution law", 1, 1);
		std::cout << Form3 << std::endl;
		Form		Form4("Fast loan application", 140, 140);
		std::cout << Form4 << std::endl;

		std::cout << GREEN << "\n" << Burry1 << " tries to sign all 4 forms\n" << DEFAULT;
		Burry1.signForm(Form1);
		Burry1.signForm(Form2);
		Burry1.signForm(Form3);
		Burry1.signForm(Form4);

		std::cout << GREEN << "\n" << Burry2 << " tries to sign all 4 forms\n" << DEFAULT;
		Burry2.signForm(Form1);
		Burry2.signForm(Form2);
		Burry2.signForm(Form3);
		Burry2.signForm(Form4);

		std::cout << GREEN << "\n" << Burry3 << " tries to sign all 4 forms\n" << DEFAULT;
		Burry3.signForm(Form1);
		Burry3.signForm(Form2);
		Burry3.signForm(Form3);
		Burry3.signForm(Form4);

		std::cout << GREEN << "\n" << Burry4 << " tries to sign all 4 forms\n" << DEFAULT;
		Burry4.signForm(Form1);
		Burry4.signForm(Form2);
		Burry4.signForm(Form3);
		Burry4.signForm(Form4);
	}
	return 0;
}
