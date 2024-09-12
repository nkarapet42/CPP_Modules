#include "AMateria.hpp"

AMateria::AMateria() : type("Unknown") {
	std::cout << "Default constructor of AMateria called" << std::endl;
}

AMateria::AMateria(const std::string& type) {
	std::cout << "Constructor of AMateria with parameters called" << std::endl;
	this->type = type;
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
	std::cout << "Copy constructor of AMateria called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	std::cout << "Copy assignment of AMateria operator called" << std::endl;
	if (this != &other)
			this->type = other.getType();
	return *this;
}

void	AMateria::use(ICharacter& target) {
	std::cout << "* AMateria use was called --> " << target.getName() << " *" << std::endl;
}

std::string const &	AMateria::getType() const {
	std::cout << "AMateria getType was called" << std::endl;
	return (this->type);
}

AMateria::~AMateria() {
	std::cout << "Destructor of AMateria called" << std::endl;
}