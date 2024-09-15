#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Default constructor of Intern called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Copy constructor of Intern called" << std::endl;
	*this = other;
}

Intern&	Intern::operator=(const Intern& other) {
	std::cout << "Copy assignment of Intern operator called" << std::endl;
	if (this != &other)
		;
	return (*this);
}

AForm*	Intern::makeForm(std::string name, std::string target) const {
	int			i = 0;
	std::string arr[] = {"presidential pardon", "robotomy request", "shrubbery creation", "NULL"};
	
	while (name != arr[i] && arr[i] != "NULL")
        i++;
	switch (i)
	{
		case (0):
			return (new PresidentialPardonForm(target));
		case (1):
			return (new RobotomyRequestForm(target));
		case (2):
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "Inten can't made form by this request -> " + name << std::endl;
			std::cout << "Allowed request's <<" + arr[0] + ">> <<" + arr[1] + ">> <<" + arr[2] + ">>" << std::endl;
			return (NULL); 
	}
}

Intern::~Intern() {
	std::cout << "Destructor of Intern called" << std::endl;
}