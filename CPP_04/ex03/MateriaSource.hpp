#pragma once

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource {

public:

	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other); 
	virtual ~MateriaSource();

	virtual void 		learnMateria(AMateria*);
	virtual AMateria*	createMateria(std::string const & type);

private:

	AMateria*	templates[4];

};