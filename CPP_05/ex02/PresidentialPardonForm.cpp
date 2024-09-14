#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Kennedy") {
	std::cout << "Default constructor of PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target) {
	std::cout << "Constructor of PresidentialPardonForm with parameters called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target) {
	std::cout << "Copy constructor of PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Copy assignment of PresidentialPardonForm operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);	
		this->target = other.target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Destructor of PresidentialPardonForm called" << std::endl;
}
