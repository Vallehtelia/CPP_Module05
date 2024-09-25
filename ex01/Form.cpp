/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:10:57 by vvaalant          #+#    #+#             */
/*   Updated: 2024/09/25 20:04:51 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Basic form"), _signed(false), grade_to_sign(150), grade_to_execute(150)
{
	std::cout << "Default form constructor ran\n";
}

Form::Form(std::string name, int const to_sign, int const to_execute) : name(name), _signed(false), grade_to_sign(to_sign), grade_to_execute(to_execute)
{
	if (to_sign < 1 || to_execute < 1)
		throw GradeTooHighException();
	else if (to_sign > 150 || to_execute > 150)
		throw GradeTooLowException();
	std::cout << "named form constructor ran\n";
}

Form::Form(Form const &other) : name(other.name), _signed(other._signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	std::cout << "Form copy constructor." << std::endl;
}

// Form &Form::operator=(Form const &other)
// {
// 	this->_signed = other._signed;
// 	std::cout << "Form assignment constructor."<< std::endl;
// 	return *this;
// }

Form::~Form()
{
	std::cout << "Form was destroyed!" << std::endl;
}

std::string	Form::getName() const
{
	return(this->name);
}

bool	Form::getSigned() const
{
	return(this->_signed);
}

int	Form::getGradeToSign() const
{
	return(this->grade_to_sign);
}

int	Form::getGradeToExec() const
{
	return (this->grade_to_execute);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	int	currGrade = bureaucrat.getGrade();

	if (currGrade > this->getGradeToSign())
		throw GradeTooLowException();
	else
	{
		this->_signed = true;
		// std::cout << "Form " << this->name << " was signed.\n";
	}
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", form grade to sign: " << form.getGradeToSign() << ".";
	return out;
}
