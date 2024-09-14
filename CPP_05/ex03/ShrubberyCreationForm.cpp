#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::shrubbery = 
    "       ccee88oo\n"
    "  C8O8O8Q8PoOb o8oo\n"
    " dOB69QO8PdUOpugoO9bD\n"
    "CgggbU8OU qOp qOdoUOdcb\n"
    "    6OuU  /p u gcoUodpP\n"
    "      \\\\ //  /douUP\n"
    "        \\\\\\\\ /////\n"
    "         |||/\\\n"
    "         |||\\/\n"
    "         |||||\n"
    "   .....//||||\\....\n";

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Bob") {
	std::cout << "Default constructor of ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
	std::cout << "Constructor of ShrubberyCreationForm with parameters called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {
	std::cout << "Copy constructor of ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Copy assignment of ShrubberyCreationForm operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::ofstream	fileout(target + "_shrubbery");
	if (!fileout.is_open()) {
		std::cerr << "Can't open the file" << std::endl;
		return ;
	}
	fileout << shrubbery << std::endl;
	fileout.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Destructor of ShrubberyCreationForm called" << std::endl;
}
