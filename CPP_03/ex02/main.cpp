#include "FragTrap.hpp"

int	main(void) {

	FragTrap a("Bob");

	a.attack("Josh");
	a.takeDamage(150);
	a.beRepaired(15);
	a.highFivesGuys();
	return (0);
}