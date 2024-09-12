#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed") {}

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie(void) {}

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}