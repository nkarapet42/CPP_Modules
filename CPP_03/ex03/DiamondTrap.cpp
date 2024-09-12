#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unknown Clap"), name("Unknown Diamond") {
	point = FragTrap::point;
	energy_point = ScavTrap::energy_point;
	attack_damage = FragTrap::attack_damage;
	std::cout << "Default constructor of DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name") {
	point = FragTrap::point;
	energy_point = ScavTrap::energy_point;
	attack_damage = FragTrap::attack_damage;
	this->name = name;
	std::cout << "Constructor of DiamondTrap with parameters called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
	std::cout << "Copy constructor of DiamondTrap called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "Copy assignment operator of DiamondTrap called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		point = other.point;
		energy_point = other.energy_point;
		attack_damage = other.attack_damage;
		ClapTrap::name = other.ClapTrap::name;
	}
	return *this;
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << "I am " << name << ",He is " << ClapTrap::name <<std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor of DiamondTrap called" << std::endl;
}