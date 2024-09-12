#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	point = 100;
	energy_point = 50;
	attack_damage = 20;
	std::cout << "Default constructor of ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	point = 100;
	energy_point = 50;
	attack_damage = 20;
	std::cout << "Constructor of ScavTrap with parameters called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	std::cout << "Copy constructor of ScavTrap called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "Copy assignment operator of ScavTrap called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->point = other.point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

void	ScavTrap::attack( const std::string& target ) {
	if (this->energy_point == 0)
		std::cout << "ScavTrap " << this->name << " out of energy." << std::endl;
	else {
		if (target.empty()) {
			std::cout << "ScavTrap " << this->name << " attack " << "Unnamed";
			std::cout << ", causing " << this->attack_damage << " points of damage!" << std::endl; 
		}
		else {
			std::cout << "ScavTrap " << this->name << " attack " << target;
			std::cout << ", causing " << this->attack_damage << " points of damage!" << std::endl; 
		}
		--energy_point;
	}
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor of ScavTrap called" << std::endl;
}
