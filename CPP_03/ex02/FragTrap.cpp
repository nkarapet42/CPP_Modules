#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	point = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << "Default constructor of FragTrap called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	point = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << "Constructor of FragTrap with parameters called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
	std::cout << "Copy constructor of FragTrap called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "Copy assignment operator of FragTrap called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->point = other.point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << name << " send high five request to members!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor of FragTrap called" << std::endl;
}
