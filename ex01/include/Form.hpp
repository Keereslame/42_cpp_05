#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
	public:
		//Orthodox canonical form
		Form();
		Form(const std::string& name, int grade);
		Form(const Form& copy);
		Form& operator=(const Form& copy);
		~Form();

		//Getter
		const std::string& getName() const;
		int	getGradeToSigned() const;
		int	getGradeToExecute() const;

		//Member functions
		void beSigned(const Bureaucrat& bureaucrat);

		//Exception
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSigned;
		const int			_gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const Form& Form);

#endif