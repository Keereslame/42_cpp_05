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
		void				checkExecute(const Bureaucrat& executor);
		virtual	void		execute(const Bureaucrat& executor) = 0;

		//Exception
		class GradeTooHighToSign : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowToSign : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighToExecute : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowToExecute : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
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