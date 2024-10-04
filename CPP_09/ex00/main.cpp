#include "BitcoinExchange.hpp"
#include <exception>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: invalid numbers of argument" << std::endl;
		return (1);
	}
    BitcoinExchange btc(argv[1]);
	try {
		btc.exchange();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}