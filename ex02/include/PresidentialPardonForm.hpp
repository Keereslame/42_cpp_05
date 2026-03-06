#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class PresidentialPardonForm
{
	public:
		//Orthodox canonical form
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& name, int gradeToSign, int gradeToExecute);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		//Getter
		const std::string&	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		//Member functions
		void				execute(const Bureaucrat& executor);

	private:
		const std::string	_target;
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& form);

#endif