/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:10:57 by vvaalant          #+#    #+#             */
/*   Updated: 2024/11/09 23:35:11 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Basic form"), _signed(false), grade_to_sign(150), grade_to_execute(150)
{
	std::cout << "Default form constructor ran\n";
}

AForm::AForm(std::string name, int const to_sign, int const to_execute) : name(name), _signed(false), grade_to_sign(to_sign), grade_to_execute(to_execute)
{
	if (to_sign < 1 || to_execute < 1)
		throw GradeTooHighException();
	else if (to_sign > 150 || to_execute > 150)
		throw GradeTooLowException();
	std::cout << "named form constructor ran\n";
}

AForm::AForm(AForm const &other) : name(other.name), _signed(other._signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	std::cout << "Form copy constructor." << std::endl;
}

// Form &Form::operator=(Form const &other)
// {
// 	this->_signed = other._signed;
// 	std::cout << "Form assignment constructor."<< std::endl;
// 	return *this;
// }

AForm::~AForm()
{
	std::cout << "Form was destroyed!" << std::endl;
}

std::string	AForm::getName() const
{
	return(this->name);
}

bool	AForm::getSigned() const
{
	return(this->_signed);
}

int	AForm::getGradeToSign() const
{
	return(this->grade_to_sign);
}

int	AForm::getGradeToExec() const
{
	return (this->grade_to_execute);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	int	currGrade = bureaucrat.getGrade();

	if (currGrade > this->getGradeToSign())
		throw GradeTooLowException();
	else
	{
		this->_signed = true;
		// std::cout << "AForm " << this->name << " was signed.\n";
	}
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	else if (!this->getSigned())
		throw FormNotSignedException();
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
	out << Aform.getName() << ", form grade to sign: " << Aform.getGradeToSign() << ".";
	return out;
}
