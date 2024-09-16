#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor of ScalarConverter called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	std::cout << "Copy constructor of ScalarConverter called" << std::endl;
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	std::cout << "Copy assignment of ScalarConverter operator called" << std::endl;
	if (this != &other)
			;
	return (*this);
}

static	void	print(const std::string& convert) {
	if (convert == "nan" || convert == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (convert == "+inf" || convert == "+inff"
			|| convert == "inf" || convert == "inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (convert == "-inf" || convert == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	ScalarConverter::convert(const std::string& convert) {
	print(convert);
	
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor of ScalarConverter called" << std::endl;
}