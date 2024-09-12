#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Default constructor of Ice called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << "Copy constructor of Ice called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	std::cout << "Copy assignment of Ice operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

AMateria*	Ice::clone() const {
	std::cout << "Ice clone was called" << std::endl;
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target) {
	std::cout << "Ice use was called" << std::endl;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice() {
	std::cout << "Destructor of Ice called" << std::endl;
}