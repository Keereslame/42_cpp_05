/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:59:51 by alexis            #+#    #+#             */
/*   Updated: 2026/03/18 12:41:10 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy Request Form", 72, 45), _target("Undefined")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm(target, 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :
	AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
		AForm::operator=(copy); //juste copy if it signed or not because all others attributes are const
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor)
{
	AForm::checkExecute(executor);
	std::cout << " --- Driling noise --- " << std::endl;
	if (rand() % 2 == 0)
		std::cout << _target << " : has been robotomized." << std::endl;
	else
		std::cout << _target << " : Robotomy failed." << std::endl;
}
