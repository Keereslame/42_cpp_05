/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:41:01 by alexis            #+#    #+#             */
/*   Updated: 2026/03/06 10:54:40 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include "../include/Form.hpp"

/******************************************************************************/
/*                          Orthodox canonical form                           */
/******************************************************************************/

Form::Form() : _name("Base"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form :" << _name << " created." << std::endl;
}

Form::Form(const std::string& name, const int gradeToSigne, const int gradeToExecute) :
	_name(name), _signed(false), _gradeToSign(gradeToSigne), _gradeToExecute(gradeToExecute)
{
	std::cout << _name << " created.";
	std::cout << "He has the grade to sign it of " << _gradeToSign;
	std::cout << " and the grade to execute it of " << _gradeToExecute;
	std::cout << ". Actually, he is " << _signed << std::endl;
}

Form::Form(const Form& copy) : _name(copy._name), _gradeToSign(copy._gradeToSign),
	_gradeToExecute(copy._gradeToExecute)
{
	std::cout << _name << " is copied.";
	std::cout << "He has the grade to sign it of " << _gradeToSign;
	std::cout << " and the grade to execute it of " << _gradeToExecute;
	std::cout << ". Actually, he is " << _signed << std::endl;
}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
		_signed = copy._signed;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form : " << _name << " deleted." << std::endl;
}

/******************************************************************************/
/*                                  Getter                                    */
/******************************************************************************/

const std::string&	Form::getName() const
{
	return (_name);
}

int	Form::getGrade() const
{
	return (_grade);
}

/******************************************************************************/
/*                               Exception                                    */
/******************************************************************************/

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

/******************************************************************************/
/*                            Override function                               */
/******************************************************************************/

std::ostream& operator<<(std::ostream& out, const Form& Form)
{
	out << Form.getName() << ", Form grade " << Form.getGrade() << "." << std::endl;
	return (out);
}