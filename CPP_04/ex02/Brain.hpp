#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class	Brain {

public:

	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other); 
	~Brain();

private:

	std::string	ideas[100];

};

#endif