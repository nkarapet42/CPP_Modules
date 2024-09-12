#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap {

public:

	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other); 
	~ClapTrap();

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

private:

	std::string		name;
	unsigned int	point;
	unsigned int	energy_point;
	unsigned int	attack_damage;

};

#endif