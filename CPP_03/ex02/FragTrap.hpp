#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public	ClapTrap {
	
public:

	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other); 
	virtual	~FragTrap();

	void	 highFivesGuys( void );

};

#endif