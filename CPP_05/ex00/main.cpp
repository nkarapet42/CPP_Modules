#include "Bureaucrat.hpp"

int	main(void) {

	{
		Bureaucrat meta;
		Bureaucrat gama("Bob", 148);

		try
		{
			meta.incrementgrade();
			meta.incrementgrade();
			meta.incrementgrade();
			meta.incrementgrade();
			std::cout << meta.getGrade() << std::endl;
			std::cout << meta.getName() << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			gama.decrementgrade();
			gama.decrementgrade();
			std::cout << gama.getGrade() << std::endl;
			gama.decrementgrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		try {
			Bureaucrat alpha("Seda", 0);
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		try {
			Bureaucrat beta("Adel", 155);
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
		try {
			Bureaucrat delta("Narek", 1);
			delta.incrementgrade();
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

}