#include "Base.hpp"

Base::~Base() {
	std::cout << "Default destructor was called" << std::endl;
}

Base*	generate(void) {
	std::srand(std::time(0));

	int	random = rand() % 3;
	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown obj" << std::endl;
}

void	identify(Base& p) {
	try
	{
		Base& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		try
		{
			Base& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch(const std::bad_cast& e)
		{
			try
			{
				Base& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch(const std::bad_cast& e)
			{
				std::cerr << "Unknown obj" << std::endl;
			}
		}
	}
	
}