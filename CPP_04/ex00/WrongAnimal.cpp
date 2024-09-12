#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") {
	std::cout << "Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) {
	std::cout << "Constructor of WrongAnimal with parameters called" << std::endl;
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
        std::cout << "Copy constructor of WrongAnimal called" << std::endl;
        *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "Copy assignment of WrongAnimal operator called" << std::endl;
	if (this != &other)
			this->type = other.getType();
	return *this;
}

void	WrongAnimal::makeSound()	const {
	std::cout << this->getType() << " -> WrongAnimal makeSound was called" << std::endl;
}

std::string	WrongAnimal::getType() const {
	std::cout << "WrongAnimal getType was called" << std::endl;
	return (this->type);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor of WrongAnimal called" << std::endl;
}