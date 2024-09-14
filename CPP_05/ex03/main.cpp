#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>


int	main(void) {
	
	std::srand(std::time(0));
	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		try
		{
			ShrubberyCreationForm	form("Tree");
			Bureaucrat				Bot("Bot", 35);

			form.beSigned(Bot);
			form.execute(Bot);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm		form;
			Bureaucrat				Bot("Bot", 35);

			form.beSigned(Bot);
			form.execute(Bot);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		try
		{
			RobotomyRequestForm		form;
			Bureaucrat				Bot("Bot", 34);

			form.beSigned(Bot);
			form.execute(Bot);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		try
		{
			PresidentialPardonForm	form;
			Bureaucrat				Bot("Bot", 4);

			form.beSigned(Bot);
			std::cout << form << std::endl;
			form.execute(Bot);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
	}
}