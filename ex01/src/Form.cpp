/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:41:01 by alexis            #+#    #+#             */
/*   Updated: 2026/03/06 13:31:02 by alexis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

/******************************************************************************/
/*                          Orthodox canonical form                           */
/******************************************************************************/

Form::Form() : _name("Base"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :
	_name(name), _signed(false),_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (Form::GradeTooLowException());
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw (Form::GradeTooHighException());
}

Form::Form(const Form& copy) : _name(copy._name),  _signed(false),
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
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

bool Form::getSigned() const
{
	return (_signed);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

/******************************************************************************/
/*                            Member function                                 */
/******************************************************************************/

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw (Form::GradeTooLowException());
	_signed = true;
}

/******************************************************************************/
/*                               Exception                                    */
/******************************************************************************/

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high to sign or execute the form!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low to sign or execute the form!");
}

/******************************************************************************/
/*                            Override function                               */
/******************************************************************************/

std::ostream& operator<<(std::ostream& out, const Form& Form)
{
	out << "Form : " << Form.getName() << " is";
	if (Form.getSigned())
		out << " signed";
	else
		out << " not signed";
	out << ", he can be sign by the grade : " << Form.getGradeToSign();
	out << " and can be execute by the grade : " << Form.getGradeToExecute() << std::endl;
	return (out);
}