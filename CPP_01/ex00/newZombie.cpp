#include "Zombie.hpp"

Zombie*	newZombie(std::string name) {
	Zombie	*new_z;
	
	new_z = new Zombie(name);
	return (new_z);
}
