#include "AForm.hpp"

AForm::AForm() : name("Unknown"), is_signed(false), grade_s(75), grade_e(75) {
	std::cout << "Default constructor of AForm called" << std::endl;
}

AForm::AForm(const std::string name, const int grade_s, const int grade_e) : \
					name(name), grade_s(grade_s), grade_e(grade_e) {
	std::cout << "Constructor of AForm with parameters called" << std::endl;
	if (grade_s < 1 || grade_e < 1)
		throw AForm::GradeTooHighException();
	else if (grade_s > 150 || grade_e > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), is_signed(other.is_signed), \
								grade_s(other.grade_s), grade_e(other.grade_e) {
	std::cout << "Copy constructor of AForm called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "Copy assignment of AForm operator called" << std::endl;
	if (this != &other)
		this->is_signed = other.is_signed;
	return (*this);
}

const std::string AForm::getName() const {
	//std::cout << "AForm getName was called" << std::endl;
	return (this->name);
}

bool	AForm::getIsSigned() const {
	//std::cout << "AForm getIsSigned was called" << std::endl;
	return (this->is_signed);
}

int	AForm::getGradeS() const {
	//std::cout << "AForm getGradeS was called" << std::endl;
	return (this->grade_s);
}

int	AForm::getGradeE() const {
	//std::cout << "AForm getGradeE was called" << std::endl;
	return (this->grade_e);
}

void	AForm::beSigned(Bureaucrat& loyal) {
	if (loyal.getGrade() > grade_s)
		throw AForm::GradeTooLowException();
	else
		is_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (is_signed == false)
		throw AForm::ExecuteUnsignedForm();
	else
		throw AForm::GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("AForm::Grade is to high");
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("AForm::Grade is to Low");
}

const char* AForm::ExecuteUnsignedForm::what() const throw() {
	return ("AForm::Form is unsigned 😭");
}

std::ostream& operator<<(std::ostream& os, const AForm& point) {
        os << "AForm name : " << point.getName() << ", Grade to sign : " << \
				point.getGradeS() << ", Grade to execute : " << point.getGradeE() \
				<< ", AForm " << (point.getIsSigned() == true ? ", is signed" : ", is not signed");
        return os;
}

AForm::~AForm() {
	std::cout << "Destructor of AForm called" << std::endl;
}