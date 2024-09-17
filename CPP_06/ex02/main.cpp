#include "Base.hpp"

int	main(void) {

	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		Base*	meta = generate();

		identify(meta);
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
	}	

	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		Base	meta;
		A		gama;
		B		ama;
		C		ma;
		identify(meta);
		identify(gama);
		identify(ama);
		identify(ma);
	}
	std::cout << std::endl;
	std::cout << "\033[35m***********************************************\033[0m" << std::endl;
	std::cout << std::endl;

	return (0);
}