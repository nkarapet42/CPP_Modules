#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Default constructor of WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
	std::cout << "Copy constructor of WrongCat called" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "Copy assignment of WrongCat operator called" << std::endl;
	if (this != &other)
			this->type = other.getType();
	return *this;
}

void	WrongCat::makeSound()	const {
	std::cout << this->getType() << " -> WrongCat makeSound was called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Destructor of WrongCat called" << std::endl;
}