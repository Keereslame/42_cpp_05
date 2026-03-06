/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:54:07 by alexis            #+#    #+#             */
/*   Updated: 2026/03/06 13:26:46 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main(void)
{
	std::cout << "\033[33m" << std::endl << "Test ex01" << "\033[0m" << std::endl;

	{
		std::cout << "\033[33m" << std::endl << "Test create Form" << "\033[0m" << std::endl;
		Form f("Base", 120, 20);
		std::cout << f << std::endl;

		std::cout << "\033[34m" << "End normal case" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test create Form with nok value" << "\033[0m" << std::endl;
		try
		{
			Form f1("Base", 0, 20);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			Form f2("Base", 2, 160);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\033[34m" << "End case with nok value" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test create Form and sign it" << "\033[0m" << std::endl;
		Bureaucrat b("Chief", 1);
		Form f("Base", 2, 120);
		std::cout << b;
		std::cout << f << std::endl;

		b.signForm(f);
		std::cout << f << std::endl;

		std::cout << "\033[34m" << "End case form signed" << "\033[0m" << std::endl;
	}

	{
		std::cout << "\033[33m" << std::endl << "Test create Form and can't sign it" << "\033[0m" << std::endl;
		Bureaucrat b("Lambda", 120);
		Form f("Base", 10, 10);
		std::cout << b;
		std::cout << f << std::endl;

		try
		{
			b.signForm(f);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "\033[34m" << "End case form can't be signed" << "\033[0m" << std::endl;
	}
	
	return (0);
}