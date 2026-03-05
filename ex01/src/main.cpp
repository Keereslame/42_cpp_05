/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:54:07 by alexis            #+#    #+#             */
/*   Updated: 2026/03/05 18:32:30 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "../include/Bureaucrat.hpp"

int main(void)
{
	std::cout << "\033[33m" << std::endl << "Test ex00" << "\033[0m" << std::endl;

	{
		std::cout << "\033[33m" << std::endl << "Test normal case" << "\033[0m" << std::endl;
		Bureaucrat b("Chief", 1);
		std::cout << b << std::endl;

		std::cout << "Chief is retrograded..." << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;

		std::cout << "Chief take back his post" << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;

		std::cout << "\033[34m" << "End normal case" << "\033[0m" << std::endl;
	}
	
	{
		std::cout << "\033[33m" << std::endl << "Test too low creation" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Alexander", 1500);
			std::cout << b << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << "\033[34m" << std::endl << "End too low creation" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test too high creation" << "\033[0m" << std::endl;
		try
		{
			Bureaucrat b("Olaf", -10);
			std::cout << b << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << "\033[34m" << std::endl << "End too high creation" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test increasing" << "\033[0m" << std::endl;
		Bureaucrat b("Paul", 2);
		std::cout << b;
		try
		{
			b.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << b;	
		try
		{
			b.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << b;
		std::cout << "\033[34m" << std::endl << "End increasing test" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test decreasing" << "\033[0m" << std::endl;
		Bureaucrat b("Tim", 149);
		std::cout << b;
		try
		{
			b.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << b;
	
		try
		{
			b.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << b;
		std::cout << "\033[34m" << std::endl << "End decreasing test" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test copy and assignement" << "\033[0m" << std::endl;
		Bureaucrat a("Chief", 1);
		Bureaucrat b(a);
		Bureaucrat c("Third", 5);

		std::cout << a;
		std::cout << b;
		std::cout << c << std::endl;
		try
		{
			b.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		c = b;
		std::cout << a;
		std::cout << b;
		std::cout << c << std::endl;
		try
		{
			c.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << a;
		std::cout << b;
		std::cout << c << std::endl;
		std::cout << "\033[34m" << std::endl << "End copy and assignement test" << "\033[0m" << std::endl;
	}
	
	return (0);
}