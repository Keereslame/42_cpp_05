#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include <string>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		//Orthodox canonical form
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		//Member functions
		void				execute(const Bureaucrat& executor);

	private:
		const std::string	_target;
};

#endif