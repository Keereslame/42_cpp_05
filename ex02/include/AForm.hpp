#ifndef AForm_HPP
# define AForm_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
	public:
		//Orthodox canonical AForm
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& copy);
		virtual ~AForm();

		//Getter
		const std::string&	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		//Member functions
		void				beSigned(const Bureaucrat& b);
		virtual	void		execute(const Bureaucrat& executor) = 0;

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
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif