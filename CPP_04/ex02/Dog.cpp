#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	dogbrain = new Brain();
	std::cout << "Default constructor of Dog called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Copy constructor of Dog called" << std::endl;
	dogbrain = new Brain(*other.dogbrain);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Copy assignment of Dog operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete dogbrain;
		dogbrain = new Brain(*other.dogbrain);
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Bark(Dog)" << std::endl;
}

Dog::~Dog() {
	delete dogbrain;
	std::cout << "Destructor of Dog called" << std::endl;
}