#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unknown") {
	point = 10;
	energy_point = 10;
	attack_damage = 0;
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name) {
	point = 10;
	energy_point = 10;
	attack_damage = 0;
	if (name.empty())
		this->name = "Unknown";
	std::cout << "Constructor with parameters called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->point = other.point;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

void	ClapTrap::attack( const std::string& target ) {
	if (this->energy_point == 0)
		std::cout << "ClapTrap " << this->name << " out of energy." << std::endl;
	else {
		if (target.empty()) {
			std::cout << "ClapTrap " << this->name << " attack " << "Unnamed";
			std::cout << ", causing " << this->attack_damage << " points of damage!" << std::endl; 
		}
		else {
			std::cout << "ClapTrap " << this->name << " attack " << target;
			std::cout << ", causing " << this->attack_damage << " points of damage!" << std::endl; 
		}
		--energy_point;
	}
}

void	ClapTrap::takeDamage( unsigned  int amount ) {
	if (this->energy_point == 0)
		std::cout << "ClapTrap " << this->name << " out of energy." << std::endl;
	else if (point == 0)
		std::cout << "ClapTrap " << this->name << " already died and cant got damage." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " has got " << amount << " damages!" << std::endl;
		if (amount <= point)
			this->point -= amount;
		else
			point = 0;
	}
}

void	ClapTrap::beRepaired( unsigned  int amount ) {
	if (this->energy_point == 0)
		std::cout << "ClapTrap " << this->name << " out of energy." << std::endl;
	else if (point == 0)
		std::cout << "ClapTrap " << this->name << " already died and cant be repaired." << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " has been repaired by " << amount << " points!" << std::endl;
		this->point += amount;
	}
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}
