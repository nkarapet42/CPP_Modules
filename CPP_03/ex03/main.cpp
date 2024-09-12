#include "DiamondTrap.hpp"

int	main(void) {
	std::cout << "\n\n### TESTING DIAMONDTRAP ###\n" << std::endl;
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		//DiamondTrap a;
		DiamondTrap b("Giga Chadd");
		//DiamondTrap c(a);

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		// a.whoAmI();
		// a.attack("some super random dude");
		b.whoAmI();
		b.attack("Chadd-clone");
		//c.whoAmI();
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	}
	return (0);
}