#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include <string>
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		//Orthodox canonical form
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		//Member functions
		void				execute(const Bureaucrat& executor);

	private:
		const std::string	_target;
};

#endif