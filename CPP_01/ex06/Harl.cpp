#include "Harl.hpp"

void	Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Harl::complain( std::string level ) {
	std::string arr[] = {"DEBUG","INFO","WARNING","ERROR","NULL"};

	int i = 0;
	void(Harl::*fptr[])(void)= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	while (level != arr[i] && arr[i] != "NULL")
		i++;
	switch (i)
	{
		case(0):
			(this->*fptr[0])();		
		case(1):
			(this->*fptr[1])();		
		case(2):
			(this->*fptr[2])();		
		case(3):
			(this->*fptr[3])();		
			break;
		default:
			exit(1 && std::cout << "[ Probably complaining about insignificant problems ]" << std::endl);
	}
}