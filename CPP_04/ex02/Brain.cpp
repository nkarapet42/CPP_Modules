#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Default constructor of Brain called" << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << "Copy constructor of Brain called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Copy assignment of Brain operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Destructor of Brain called" << std::endl;
}