#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2) {
		std::cout << "Error: invalid number of arguments\n";
		return (1);
	}
	PmergeMe::print(argc, argv);
	return (0);
}