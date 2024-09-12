#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter;

class	AMateria {

public:

	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other); 
	virtual ~AMateria();

	std::string const &	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

protected:

	std::string	type;

};

#include "ICharacter.hpp"

#endif