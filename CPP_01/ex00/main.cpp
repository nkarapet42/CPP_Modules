#include "Zombie.hpp"

int	main(void) {
	std::string	name_stack;

	std::cout << "Name for stack :";
	std::cin >> name_stack;

	randomChump(name_stack);

	std::string name_heap;

	std::cout << "Name for heap :";
	std::cin >> name_heap;
	Zombie *Yoo = newZombie(name_heap);

	// Zombie *fds = new Zombie("HFDKLS");

	Yoo->announce();
	delete (Yoo);

	return (0);
}
