#include "Harl.hpp"

int main(int argc , char **argv)
{
	Harl		level;

	if (argc == 2)
		level.complain(argv[1]);
	else
		return (1 && std::cout << "Wrong level" << std::endl);
	return (0);
}