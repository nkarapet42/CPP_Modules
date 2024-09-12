#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void) {

	{
		unsigned int size = 4;
		Animal* animals[size];

		unsigned int i = 0;
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << "\033[32mCreating array of Dog's\033[0m" << std::endl;
		while(i < size / 2) {
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			animals[i] = new Dog();
			i++;
		}
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << "\033[32mCreating array of Cat's\033[0m" << std::endl;
		while(i < size) {
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			animals[i] = new Cat();
			i++;
		}
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		i = 0;
		std::cout << std::endl;
		std::cout << "\033[31mDeleting the array\033[0m" << std::endl;
		while (i < size) {
			std::cout << "\033[34m------------------------------------\033[0m" << std::endl;
			delete animals[i];
			i++;
		}
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
	}

	return (0);
}