#include "Animal.hpp"

Animal::Animal() : type("") {
	std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(const std::string& type) {
	std::cout << "Constructor of Animal with parameters called" << std::endl;
	this->type = type;
}

Animal::Animal(const Animal& other) {
        std::cout << "Copy constructor of Animal called" << std::endl;
        *this = other;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Copy assignment of Animal operator called" << std::endl;
	if (this != &other)
			this->type = other.getType();
	return *this;
}

std::string	Animal::getType() const {
	std::cout << "Animal getType was called" << std::endl;
	return (this->type);
}

Animal::~Animal() {
	std::cout << "Destructor of Animal called" << std::endl;
}