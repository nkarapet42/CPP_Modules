#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << "Default constructor of RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
	std::cout << "Copy constructor of RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Copy assignment of RobotomyRequestForm operator called" << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Destructor of RobotomyRequestForm called" << std::endl;
}
