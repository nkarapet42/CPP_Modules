#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unknown"), grade(75) {
	std::cout << "Default constructor of Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : name(name), grade(grade) {
	std::cout << "Constructor of Bureaucrat with parameters called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
	std::cout << "Copy constructor of Bureaucrat called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Copy assignment of Bureaucrat operator called" << std::endl;
	if (this != &other)
		this->grade = other.getGrade();
	return *this;
}

int		Bureaucrat::getGrade() const {
	//std::cout << "Bureaucrat getGrade was called" << std::endl;
	return (this->grade);
}

const	std::string Bureaucrat::getName() const {
	//std::cout << "Bureaucrat getName was called" << std::endl;
	return (this->name);
}

void	Bureaucrat::incrementgrade() {
	std::cout << "Bureaucrat getGrade was called" << std::endl;
	if (--grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementgrade() {
	std::cout << "Bureaucrat getGrade was called" << std::endl;
	if (++grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat::Grade is to high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat::Grade is to Low");
}

void	Bureaucrat::signForm(Form& form) {
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() \
			<< std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " \
			<< form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& point) {
        os << point.getName() << ", bureaucrat grade " << point.getGrade();
        return os;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor of Bureaucrat called" << std::endl;
}
