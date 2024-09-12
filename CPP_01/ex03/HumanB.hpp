#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

public:

	HumanB(const std::string& name);
	void	setWeapon(Weapon& weapon);
	void	attack() const;

private:

	std::string	name;
	Weapon		*weapon;

};

#endif