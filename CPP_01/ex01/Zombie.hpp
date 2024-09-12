#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

public :

		void	announce( void );

		Zombie();
		Zombie(std::string name);
		~Zombie(void);

private:

		std::string	name;

};

Zombie* zombieHorde( int N, std::string name );

#endif