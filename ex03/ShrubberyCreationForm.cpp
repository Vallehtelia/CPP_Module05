/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:30:54 by vvaalant          #+#    #+#             */
/*   Updated: 2024/11/09 23:31:18 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor ran." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExec()), target(other.target)
{
	std::cout << "ShrubberyCreationForm copy constructor ran." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor ran." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	else if (!this->getSigned())
		throw AForm::FormNotSignedException();
	std::ofstream file;
	file.open(this->target + "_shrubbery");
	if (file.is_open())
	{
		file << "              _{\\ _{\\{\\/}/}/}__\n             {/{/\\}{/{/\\}(\\}{/\\} _\n            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n             {/{\\{\\{\\/}/}{\\{\\}/}\n              {){/ {\\/}{\\/} \\}\\}\n              (_)  \\.-'.-/\n          __...--- |'-.-'| --...__\n   _...--'   .-'   |'-.-'|  ' -.  ''--..__\n -'    ' .  . '    |.'-._| '  . .  '   jro\n .  '-  '    .--'  | '-.'|    .  '  . '\n          ' ..     |'-_.-|\n  .  '  .       _.-|-._ -|-._  .  '  .\n              .'   |'- .-|   '.\n  ..-'   ' .  '.   `-._.-�   .'  '  - .\n   .-' '        '-._______.-'     '  .\n        .      ~,\n    .       .   |\\   .    ' '-.\n    ___________/  \\____________\n   /  Why is it, when you want \\\n  |  something, it is so damn   |\n  |    much work to get it?     |\n   \\___________________________/";
		file.close();
	}
	else
		std::cerr << RED << "Error opening file." << DEFAULT << std::endl;
}
