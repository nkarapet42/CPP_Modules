#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	catbrain = new Brain();
	std::cout << "Default constructor of Cat called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Copy constructor of Cat called" << std::endl;
	catbrain = new Brain(*other.catbrain);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Copy assignment of Cat operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete catbrain;
		catbrain = new Brain(*other.catbrain);
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meow(Cat)" << std::endl;
}

Cat::~Cat() {
	delete catbrain;
	std::cout << "Destructor of Cat called" << std::endl;
}