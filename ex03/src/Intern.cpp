/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 09:29:20 by alexis            #+#    #+#             */
/*   Updated: 2026/03/19 10:04:17 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& copy)
{
	(void)copy;
}

Intern& Intern::operator=(const Intern& copy)
{
	(void)copy;
	return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeShrubberyCreationForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	AForm* (Intern::*functions[3])(const std::string&) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*functions[i])(target));
		}
	}

	std::cerr << "Error : Form " << name << " doesn't exist." << std::endl;
	return (NULL);
}