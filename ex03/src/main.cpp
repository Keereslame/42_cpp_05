/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:54:07 by alexis            #+#    #+#             */
/*   Updated: 2026/03/19 11:06:37 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void)
{
	srand(time(NULL));
	std::cout << "\033[33m" << std::endl << "Test ex03" << "\033[0m" << std::endl;

	{
		std::cout << "\033[33m" << std::endl << "Test create Shrubbery Creation Form by an intern" << "\033[0m" << std::endl;
		Intern	intern;
		AForm*	form;
		form = intern.makeForm("shrubbery creation", "home");
		if (form)
		{
			std::cout << *form << std::endl;
	
			Bureaucrat chief("Chief", 1);
			chief.signForm(*form);
			chief.executeForm(*form);
			delete form;
		}
		std::cout << "\033[34m" << "End case shrubbery creation form" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test create robotomy request Form by an intern" << "\033[0m" << std::endl;
		Intern	intern;
		AForm*	form;
		form = intern.makeForm("robotomy request", "home");
		if (form)
		{
			std::cout << *form << std::endl;

			Bureaucrat chief("Chief", 1);
			chief.signForm(*form);
			chief.executeForm(*form);
			delete form;
		}
		std::cout << "\033[34m" << "End case robotomy request form" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test create presidential pardon Form by an intern" << "\033[0m" << std::endl;
		Intern	intern;
		AForm*	form;
		form = intern.makeForm("presidential pardon", "home");
		if (form)
		{
			std::cout << *form << std::endl;

			Bureaucrat chief("Chief", 1);
			chief.signForm(*form);
			chief.executeForm(*form);
			delete form;
		}
		std::cout << "\033[34m" << "End case presidential pardon form" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test create unknown Form by an intern" << "\033[0m" << std::endl;
		Intern	intern;
		AForm*	form;
		form = intern.makeForm("unknown", "home");
		if (form)
		{
			std::cout << *form << std::endl;

			Bureaucrat chief("Chief", 1);
			chief.signForm(*form);
			chief.executeForm(*form);
			delete form;
		}
		std::cout << "\033[34m" << "End case presidential pardon form" << "\033[0m" << std::endl;
	}
	return (0);
}