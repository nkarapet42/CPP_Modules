#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) {
	if (type.empty())
		this->type = "hand";
	else
		this->type = type;
}

const	std::string& Weapon::getType() const {
	return (type);
}

void	Weapon::setType(const std::string& newtype) {
	type = newtype;
}