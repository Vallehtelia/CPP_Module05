/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:30:49 by vvaalant          #+#    #+#             */
/*   Updated: 2024/11/09 23:20:16 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm constructor ran." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()), target(other.target)
{
	std::cout << "RobotomyRequestForm copy constructor ran." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor ran." << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	else if (!this->getSigned())
		throw AForm::FormNotSignedException();
	std::cout << "Drilling noises..." << std::endl;
	srand(time(NULL));
	int randomNumber = std::rand() % 100;
	if (randomNumber < 50)
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomization of " << this->target << " failed." << std::endl;
}
