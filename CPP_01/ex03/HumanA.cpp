#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) :  weapon(weapon) {
	if (name.empty())
		this->name = "Unnamed";
	else
		this->name = name;
}

void	HumanA::attack() const {
		std::cout << name << "  attacks with their " << weapon.getType() << std::endl;
}