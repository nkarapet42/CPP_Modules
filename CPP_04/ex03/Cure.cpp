#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Default constructor of Cure called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << "Copy constructor of Cure called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	std::cout << "Copy assignment of Cure operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

AMateria*	Cure::clone() const {
	std::cout << "Cure clone was called" << std::endl;
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << "Cure use was called" << std::endl;
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure() {
	std::cout << "Destructor of Cure called" << std::endl;
}