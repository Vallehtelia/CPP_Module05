/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:37:57 by vvaalant          #+#    #+#             */
/*   Updated: 2024/11/09 23:40:02 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " << name << " was created." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : name(bureaucrat.name), grade(bureaucrat.grade)
{
	std::cout << "Bureaucrat copy constructor." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->name << " is dead." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
	std::cout << "Bureaucrat assignment constructor."<< std::endl;
	this->grade = bureaucrat.grade;
	return *this;
}

std::string const &Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade <= 1)
		throw GradeTooHighException();
	this->grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade >= 150)
		throw GradeTooLowException();
	this->grade += 1;
}

void Bureaucrat::signForm(AForm &formToSign)
{
	try
	{
		formToSign.beSigned(*this);
		std::cout << GREEN << this->name << " signed " << formToSign.getName() << DEFAULT << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << this->name << " could not sign " << formToSign.getName() << " because " << e.what() << DEFAULT << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &formToExecute)
{
	try
	{
		formToExecute.execute(*this);
		std::cout << GREEN << this->name << " executed " << formToExecute.getName() << DEFAULT << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << this->name << " could not execute " << formToExecute.getName() << " because " << e.what() << DEFAULT << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
