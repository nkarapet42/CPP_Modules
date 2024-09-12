#include "Character.hpp"

Character::Character() : name("Unknown") {
	std::cout << "Default constructor of Character called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string const & name) : name(name) {
	std::cout << "Constructor of Character with parameters called" << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other) {
	std::cout << "Copy constructor of Character was called" << std::endl;
	name = other.name;
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character&	Character::operator=(const Character& other) {
	std::cout << "Copy assignment of Character operator called" << std::endl;
	if (this != &other) {
		name = other.name;
		for (int i = 0; i < 4; i++) {
			if (inventory[i])
				delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return *this;
}

std::string const & Character::getName() const {
	//std::cout << "Character getName was called" << std::endl;
	return (name);
}

void	Character::equip(AMateria* m) {
	std::cout << "Character equip was called" << std::endl;
	if (!m)
		return ;
	for (int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	std::cout << "Character unequip was called" << std::endl;
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx] = NULL;
}
void	Character::use(int idx, ICharacter& target) {
	std::cout << "Character use was called" << std::endl;
	if (idx >= 0 &&  idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}

Character::~Character() {
	std::cout << "Destructor of Character called" << std::endl;
	for (int i = 0; i < 4; i++){
		if (inventory[i])
			delete inventory[i];
	}
}