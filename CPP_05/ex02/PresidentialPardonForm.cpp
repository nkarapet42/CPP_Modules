#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {
	std::cout << "Default constructor of PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) {
	std::cout << "Copy constructor of PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Copy assignment of PresidentialPardonForm operator called" << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Destructor of PresidentialPardonForm called" << std::endl;
}
