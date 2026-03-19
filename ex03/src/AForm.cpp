/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexis <alexis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:41:01 by alexis            #+#    #+#             */
/*   Updated: 2026/03/18 12:08:43 by alexis           ###   ########.fr       */
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
	if (gradeToSign > 150)
		throw (AForm::GradeTooLowToSign());
	else if (gradeToExecute > 150)
		throw (AForm::GradeTooLowToExecute());
	else if (gradeToSign < 1)
		throw (AForm::GradeTooHighToSign());
	else if (gradeToExecute < 1)
		throw (AForm::GradeTooHighToExecute());
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
		throw (AForm::GradeTooLowToSign());
	_signed = true;
}

void	AForm::checkExecute(const Bureaucrat& b)
{
	if (!this->getSigned())
		throw (AForm::FormNotSignedException());
	if (b.getGrade() > this->getGradeToExecute())
		throw (AForm::GradeTooLowToExecute());
}

/******************************************************************************/
/*                               Exception                                    */
/******************************************************************************/

const char* AForm::GradeTooHighToSign::what() const throw()
{
	return ("Grade too high to sign the Form!");
}

const char* AForm::GradeTooLowToSign::what() const throw()
{
	return ("Grade too low to sign the Form!");
}

const char* AForm::GradeTooHighToExecute::what() const throw()
{
	return ("Grade too high to execute the Form!");
}

const char* AForm::GradeTooLowToExecute::what() const throw()
{
	return ("Grade too low to execute the Form!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("The Form is not signed. Please sign it before execute!");
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