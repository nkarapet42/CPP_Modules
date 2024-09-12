#include "Zombie.hpp"

int	main(void) {
	std::string	name_horde;

	std::cout << "Name for horde :";
	std::cin >> name_horde;

	int	N;

	std::cout << "Num of zombies :";
	std::cin >> N;

	Zombie*	horde = zombieHorde(N, name_horde);

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] (horde);
	return (0);
}
