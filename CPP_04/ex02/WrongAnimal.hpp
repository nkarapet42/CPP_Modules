#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class	WrongAnimal {

public:

	WrongAnimal();
	WrongAnimal(const std::string& type);
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other); 
	virtual	~WrongAnimal();

	virtual	void	makeSound() const;
	std::string		getType() const;

protected:

	std::string	type;

};

#endif