#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap {

public:

	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator=(const DiamondTrap& other); 
	~DiamondTrap();

	using	ScavTrap::attack;
	void	whoAmI();

private:

	std::string	name;

};

#endif