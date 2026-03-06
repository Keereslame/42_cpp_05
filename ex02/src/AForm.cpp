/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
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
#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

/******************************************************************************/
/*                          Orthodox canonical AForm                           */
/******************************************************************************/

AForm::AForm() : _name("Base"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :
	_name(name), _signed(false),_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (AForm::GradeTooLowException());
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw (AForm::GradeTooHighException());
}

AForm::AForm(const AForm& copy) : _name(copy._name),  _signed(false),
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
		_signed = copy._signed;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm : " << _name << " deleted." << std::endl;
}

/******************************************************************************/
/*                                  Getter                                    */
/******************************************************************************/

const std::string&	AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

/******************************************************************************/
/*                            Member function                                 */
/******************************************************************************/

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _gradeToSign)
		throw (AForm::GradeTooLowException());
	_signed = true;
}

/******************************************************************************/
/*                               Exception                                    */
/******************************************************************************/

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high to sign or execute the AForm!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low to sign or execute the AForm!");
}

/******************************************************************************/
/*                            Override function                               */
/******************************************************************************/

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << "AForm : " << AForm.getName() << " is";
	if (AForm.getSigned())
		out << " signed";
	else
		out << " not signed";
	out << ", he can be sign by the grade : " << AForm.getGradeToSign();
	out << " and can be execute by the grade : " << AForm.getGradeToExecute() << std::endl;
	return (out);
}