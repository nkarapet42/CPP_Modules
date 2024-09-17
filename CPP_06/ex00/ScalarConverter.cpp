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

static	int	print(const std::string& convert) {
	if (convert[0] != '\0' && (((convert[0] > 31 && convert[0] < 48)
		|| (convert[0] > 57 && convert[0] < 127)) && convert[1] == '\0')) {
		std::cout << "char: '" << static_cast<char>(convert[0]) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(convert[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(convert[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(convert[0]) << ".0" << std::endl;
		return (1);
	}
	else if (convert == "nan" || convert == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (1);
	}
	else if (convert == "+inf" || convert == "+inff"
			|| convert == "inf" || convert == "inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return (1);
	}
	else if (convert == "-inf" || convert == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (1);
	}
	return (0);
}

static void print_char(const double& dabl) {
	if (dabl < 0 || dabl > 127)
		std::cout << "char: impossible" << std::endl;
	else if ((dabl >= 0 && dabl <=31) || dabl == 127)
		std::cout << "char: Non displayable" << std::endl;
	else {
		char	c = static_cast<char>(dabl);
		std::cout << "char: '" << c << "'" << std::endl;
	}
}

static void	print_int(const double& dabl) {
	if (dabl < -2147483648 || dabl > 2147483648)
		std::cout << "int: impossible" << std::endl;
	else {
		int		integer = static_cast<int>(dabl);
		std::cout << "int: " << integer << std::endl;
	}
}

static bool	check_dotd(const std::string& val) {
	int	i = 0;
	while (val[i] != '\0') {
		if (val[i] == '.' && (val[i + 1] == '\0' || (val[i + 1] && val[i + 1] == '0'))
			&& (val[i + 2] == '\0' || (val[i + 2] && val[i + 2] == '0'))
			&& (val[i + 3] == '\0' || (val[i + 3] && val[i + 3] == '0'))
			&& (val[i + 4] == '\0' || (val[i + 4] && val[i + 4] == '0'))
			&& (val[i + 5] == '\0' || (val[i + 5] && val[i + 5] >= '0' && val[i + 5] <= '4')))
		return (true);
		if (val[i] == '.')
			break ;
		i++;
	}
	if (val[i] == '\0')
		return (true);
	return (false);
}

static bool	check_dotf(const std::string& val) {
	int	i = 0;
	while (val[i] != '\0') {
		if (val[i] == '.' && (val[i + 1] == '\0' || (val[i + 1] && val[i + 1] == '0'))
			&& (val[i + 2] == '\0' || (val[i + 2] && val[i + 2] == '0'))
			&& (val[i + 3] == '\0' || (val[i + 3] && val[i + 3] == '0'))
			&& (val[i + 4] == '\0' || (val[i + 4] && val[i + 4] == '0'))
			&& (val[i + 5] == '\0' || (val[i + 5] && val[i + 5] >= '0' && val[i + 5] <= '5')))
		return (true);
		if (val[i] == '.')
			break ;
		i++;
	}
	if (val[i] == '\0')
		return (true);
	return (false);
}

static void print_float(const std::string& val) {
	std::stringstream	tmp(val);
	float				flp;

	tmp >> flp;
	if (tmp.fail())
		std::cout << "float: impossible" << std::endl;
	else {
		if (check_dotf(val))
			std::cout << "float: " << flp << ".0f" << std::endl;
		else
			std::cout << "float: " << flp << "f" << std::endl;
	}
}

static int	len(const std::string& str) {
		int	len = 0;
		while (str[len] != '\0')
			len++;
		return (len);
}

static bool	check_dot(const std::string& val) {
	int	i = 0;
	while (val[i] != '\0') {
		if (val[i] == '.')
			return (false);
		i++;
	}
	return (true);
}

static bool	check_after_dot(const std::string& val) {
	int i = 0;
	while (val[i] != '\0') {
		if (val[i] == '.') {
			i++;
			if (val[i] == '\0')
					return (false);
			while (val[i] != '\0' && (val[i] >= '0' && val[i] <= '9')){
				i++;
				if (val[i] == '\0')
					return (false);
			}
			return (true);
		}
		i++;
	}
	return (false);
}

void	ScalarConverter::convert(const std::string& convert) {
	if(print(convert))
		return ;
	std::string			val(convert);
	if (convert != "f") {
		if (len(convert) > 2) {
			if (convert[len(convert) - 1] == 'f') {
				val[len(convert) - 1] = '\0';
				if (check_dot(val))
					val = "";
			}
		}
	}
	std::stringstream	tmp(val);
	double				dabl;

	tmp >> dabl;
	if (tmp.fail() || check_after_dot(val)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	print_char(dabl);
	print_int(dabl);
	print_float(val);
	if (check_dotd(val))
		std::cout << "double: " << dabl << ".0" << std::endl;
	else
		std::cout << "double: " << dabl << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor of ScalarConverter called" << std::endl;
}