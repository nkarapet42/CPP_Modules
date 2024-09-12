#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void) {

	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << "\033[32mCreating Animal\033[0m" << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		const Animal* meta = new Animal("Monkey");
		std::cout << std::endl;
		std::cout << "\033[32mCreating Dog\033[0m" << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		const Animal* dog = new Dog();
		std::cout << std::endl;
		std::cout << "\033[32mCreating Cat\033[0m" << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		const Animal* cat = new Cat();
		std::cout << std::endl;
		std::cout << "\033[32mCreating WrongCat\033[0m" << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		const WrongAnimal* wcat = new WrongCat();
		std::cout << std::endl;


		std::cout << "\033[34mGetType call of Animal\033[0m" << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		std::cout << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		std::cout << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		std::cout << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		std::cout << wcat->getType() << " " << std::endl;
		std::cout << std::endl;

		std::cout << "\033[33mMakeSound call\033[0m" << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		cat->makeSound();
		std::cout << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		dog->makeSound();
		std::cout << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		wcat->makeSound();
		std::cout << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		meta->makeSound();
		std::cout << std::endl;

		std::cout << "\033[31mDeleting Animal\033[0m" << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		delete meta;
		std::cout << std::endl;
		std::cout << "\033[31mDeleting Dog\033[0m" << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		delete dog;
		std::cout << std::endl;
		std::cout << "\033[31mDeleting Cat\033[0m" << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		delete cat;
		std::cout << std::endl;
		std::cout << "\033[31mDeleting WrongCat\033[0m" << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		delete wcat;
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << "\033[32mCreating Animal with Type\033[0m" << std::endl;
		const Animal* meta = new Animal("Monkey");
		std::cout << std::endl;
		std::cout << "\033[33mMakeSound call\033[0m" << std::endl;
		meta->makeSound();
		std::cout << std::endl;
		std::cout << "\033[31mDeleting Animal with Type\033[0m" << std::endl;
		delete meta;
		std::cout << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << "\033[32mCreating Animal\033[0m" << std::endl;
		const Animal* alpa = new Animal();
		std::cout << std::endl;
		std::cout << "\033[33mMakeSound call\033[0m" << std::endl;
		alpa->makeSound();
		std::cout << std::endl;
		std::cout << "\033[31mDeleting Animal\033[0m" << std::endl;
		delete alpa;
		std::cout << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "\033[32mCreating Dog\033[0m" << std::endl;
		const Animal* dog = new Dog();
		std::cout << std::endl;
		std::cout << "\033[33mMakeSound call\033[0m" << std::endl;
		dog->makeSound();
		std::cout << std::endl;
		std::cout << "\033[31mDeleting Dog\033[0m" << std::endl;
		delete dog;
		std::cout << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "\033[32mCreating Cat\033[0m" << std::endl;
		const Animal* cat = new Cat();
		std::cout << std::endl;
		std::cout << "\033[33mMakeSound call\033[0m" << std::endl;
		cat->makeSound();
		std::cout << std::endl;
		std::cout << "\033[31mDeleting Cat\033[0m" << std::endl;
		delete cat;
		std::cout << std::endl;
		std::cout << "\033[34m----------------------------------------------\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
	}

	return (0);
}