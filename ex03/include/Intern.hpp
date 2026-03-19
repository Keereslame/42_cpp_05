#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);
		~Intern();

		AForm* makeForm(const std::string& name, const std::string& target);

	private:
		AForm*	makeShrubberyCreationForm(const std::string& target);
		AForm*	makeRobotomyRequestForm(const std::string& target);
		AForm*	makePresidentialPardonForm(const std::string& target);
};

#endif