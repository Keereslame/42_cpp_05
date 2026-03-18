/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:59:51 by alexis            #+#    #+#             */
/*   Updated: 2026/03/18 13:31:24 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery Creation Form", 145, 137), _target("Undefined")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
	AForm(target, 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) :
	AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
		AForm::operator=(copy); //juste copy if it signed or not because all others attributes are const
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor)
{
	AForm::checkExecute(executor);
	std::ofstream file((_target + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "      ^            ^      "<< std::endl;
		file << "     /\\          /\\     "<< std::endl;
		file << "    /  \\        /  \\    "<< std::endl;
		file << "   /    \\      /    \\   "<< std::endl;
		file << "  /      \\    /      \\  "<< std::endl;
		file << "  ---------    ---------  "<< std::endl;
		file << "      ||           ||     "<< std::endl;
		file << "      ||           ||     "<< std::endl;
		file << "      ||           ||     "<< std::endl;

		file.close();
	}
}
