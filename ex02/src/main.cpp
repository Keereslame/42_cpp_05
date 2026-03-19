/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:54:07 by alexis            #+#    #+#             */
/*   Updated: 2026/03/19 09:20:04 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(void)
{
	srand(time(NULL)); //to initialize the seed
	std::cout << "\033[33m" << std::endl << "Test ex02" << "\033[0m" << std::endl;

	//Test creation a Form
	/*{
		//Not possible because it's an abstract class
		std::cout << "\033[33m" << std::endl << "Test create AForm" << "\033[0m" << std::endl;
		AForm f("Base", 120, 20);
		std::cout << f << std::endl;

		std::cout << "\033[34m" << "End normal case" << "\033[0m" << std::endl;
	}*/

	//Test creation -> no exception so no try/catch
	{
		std::cout << "\033[33m" << std::endl << "Test create different Form" << "\033[0m" << std::endl;
		PresidentialPardonForm p("home");
		std::cout << "Status of presidential pardon form : " << p << std::endl;
		RobotomyRequestForm r("home");
		std::cout << "Status of robotomy request form : " << r << std::endl;
		ShrubberyCreationForm s("home");
		std::cout << "Status of shrubbery creation form : " << s << std::endl;
		std::cout << "\033[34m" << "End case create form" << "\033[0m" << std::endl;
	}

	/**************************************************************************************************/
	/*                                     Presidential Pardon Form                                   */
	/**************************************************************************************************/

	std::cout << "\033[33m" << std::endl << "Test Presidential Pardon Form" << "\033[0m" << std::endl;
	{
		std::cout << "\033[33m" << std::endl << "Test normal case" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Chief", 1);
			PresidentialPardonForm p("home");
			std::cout << b;
			std::cout << p;
			b.signForm(p);
			b.executeForm(p);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\033[34m" << "End case normal case" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test can't sign" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Chief", 149);
			PresidentialPardonForm p("home");
			std::cout << b;
			std::cout << p;
			b.signForm(p);
			b.executeForm(p);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\033[34m" << "End case can't sign" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test can sign but not execute" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Chief", 20);
			PresidentialPardonForm p("home");
			std::cout << b;
			std::cout << p;
			b.signForm(p);
			b.executeForm(p);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\033[34m" << "End case can sign but not execute" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test not signed" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Chief", 1);
			PresidentialPardonForm p("home");
			std::cout << b;
			std::cout << p;
			//b.signForm(p);
			b.executeForm(p);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\033[34m" << "End case not signed" << "\033[0m" << std::endl;
	}

	/**************************************************************************************************/
	/*                                     Robotomy Request Form                                      */
	/**************************************************************************************************/

	std::cout << "\033[33m" << std::endl << "Test Robotomy Request Form" << "\033[0m" << std::endl;
	{
		std::cout << "\033[33m" << std::endl << "Test normal case" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Chief", 1);
			RobotomyRequestForm r("home");
			std::cout << b;
			std::cout << r;
			b.signForm(r);
			b.executeForm(r);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\033[34m" << "End case normal case" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test can't sign" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Chief", 149);
			RobotomyRequestForm r("home");
			std::cout << b;
			std::cout << r;
			b.signForm(r);
			b.executeForm(r);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\033[34m" << "End case can't sign" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test can sign but not execute" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Chief", 50);
			RobotomyRequestForm r("home");
			std::cout << b;
			std::cout << r;
			b.signForm(r);
			b.executeForm(r);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\033[34m" << "End case can sign but not execute" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test not signed" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Chief", 1);
			RobotomyRequestForm r("home");
			std::cout << b;
			std::cout << r;
			//b.signForm(p);
			b.executeForm(r);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\033[34m" << "End case not signed" << "\033[0m" << std::endl;
	}

	/**************************************************************************************************/
	/*                                     Shrubbery Creation Form                                    */
	/**************************************************************************************************/

	std::cout << "\033[33m" << std::endl << "Test Shrubbery Creation Form" << "\033[0m" << std::endl;
	{
		std::cout << "\033[33m" << std::endl << "Test normal case" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Chief", 1);
			ShrubberyCreationForm s("home");
			std::cout << b;
			std::cout << s;
			b.signForm(s);
			b.executeForm(s);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\033[34m" << "End case normal case" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test can't sign" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Chief", 149);
			ShrubberyCreationForm s("home");
			std::cout << b;
			std::cout << s;
			b.signForm(s);
			b.executeForm(s);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\033[34m" << "End case can't sign" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test can sign but not execute" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Chief", 140);
			ShrubberyCreationForm s("home");
			std::cout << b;
			std::cout << s;
			b.signForm(s);
			b.executeForm(s);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\033[34m" << "End case can sign but not execute" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test not signed" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Chief", 1);
			ShrubberyCreationForm s("home");
			std::cout << b;
			std::cout << s;
			//b.signForm(p);
			b.executeForm(s);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\033[34m" << "End case not signed" << "\033[0m" << std::endl;
	}

	return (0);
}