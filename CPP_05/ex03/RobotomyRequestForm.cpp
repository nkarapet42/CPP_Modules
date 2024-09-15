#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Liparid") {
	std::cout << "Default constructor of RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::cout << "Constructor of RobotomyRequestForm with parameters called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {
	std::cout << "Copy constructor of RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Copy assignment of RobotomyRequestForm operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::cout << "DuuDuDuuu..DuuuuuDuuDuuu...Drrrrr" << std::endl;
	if ((std::rand() % 2) == 0)
		std::cout << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy of " << target << " failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Destructor of RobotomyRequestForm called" << std::endl;
}
