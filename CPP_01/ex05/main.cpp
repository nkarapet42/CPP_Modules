#include "Harl.hpp"

int main(void)
{
	Harl		level;
	std::string	name;

	while (1)
	{
		std::cout << "Input level --> ";
		std::getline(std::cin, name);
		level.complain(name);
	}
	return (0);
}