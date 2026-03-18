#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include <string>
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
		//Orthodox canonical form
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();

		//Member functions
		void				execute(const Bureaucrat& executor);

	private:
		const std::string	_target;
};

#endif