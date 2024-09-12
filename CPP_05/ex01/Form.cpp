#include "Form.hpp"

Form::Form() : name("Unknown"), is_signed(false), grade_s(75), grade_e(75) {
	std::cout << "Default constructor of Form called" << std::endl;
}

Form::Form(const std::string name, const int grade_s, const int grade_e) : \
					name(name), grade_s(grade_s), grade_e(grade_e) {
	std::cout << "Constructor of Form with parameters called" << std::endl;
	if (grade_s < 1 || grade_e < 1)
		throw Form::GradeTooHighException();
	else if (grade_s > 150 || grade_e > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), is_signed(other.is_signed), \
								grade_s(other.grade_s), grade_e(other.grade_e) {
	std::cout << "Copy constructor of Form called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Copy assignment of Form operator called" << std::endl;
	if (this != &other)
		this->is_signed = other.is_signed;
	return (*this);
}

const std::string Form::getName() const {
	//std::cout << "Form getName was called" << std::endl;
	return (this->name);
}

bool	Form::getIsSigned() const {
	//std::cout << "Form getIsSigned was called" << std::endl;
	return (this->is_signed);
}

int	Form::getGradeS() const {
	//std::cout << "Form getGradeS was called" << std::endl;
	return (this->grade_s);
}

int	Form::getGradeE() const {
	//std::cout << "Form getGradeE was called" << std::endl;
	return (this->grade_e);
}

void	Form::beSigned(Bureaucrat& loyal) {
	if (loyal.getGrade() > grade_s)
		throw Form::GradeTooLowException();
	else
		is_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Form::Grade is to high");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Form::Grade is to Low");
}

std::ostream& operator<<(std::ostream& os, const Form& point) {
        os << "Form name : " << point.getName() << ", Grade to sign : " << \
				point.getGradeS() << ", Grade to execute : " << point.getGradeE() \
				<< ", Form " << (point.getIsSigned() == true ? ", is signed" : ", is not signed");
        return os;
}

Form::~Form() {
	std::cout << "Destructor of Form called" << std::endl;
}