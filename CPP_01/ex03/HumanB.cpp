#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : weapon(nullptr) {
	if (name.empty())
		this->name = "Unnamed";
	else
		this->name = name;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void	HumanB::attack() const {
	if (weapon != nullptr && weapon->getType() != "")
		std::cout << name << "  attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << "  attacks with their " << "hand" << std::endl;
}