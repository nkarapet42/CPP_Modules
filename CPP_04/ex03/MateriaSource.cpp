#include "MateriaSource.hpp"

MateriaSource::MateriaSource () {
	std::cout << "Default constructor of MateriaSource called" << std::endl;
	for (int i = 0; i < 4; i++)
		templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << "Copy constructor of MateriaSource called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other.templates[i])
			templates[i] = other.templates[i]->clone();
		else
			templates[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	std::cout << "Copy assignment of MateriaSource operator called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (templates[i])
			delete templates[i];
		if (other.templates[i])
			templates[i] = other.templates[i]->clone();
		else
			templates[i] = NULL;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia) {
	std::cout << "MateriaSource learnMateria was called" << std::endl;
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++){
		if (!templates[i]) {
			templates[i] = materia;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	std::cout << "MateriaSource createMateria was called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (templates[i] && templates[i]->getType() == type)
			return (templates[i]->clone());
	}
	return (NULL);
}

MateriaSource::~MateriaSource() {
	std::cout << "Destructor of MateriaSource called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (templates[i])
			delete templates[i];
	}
}