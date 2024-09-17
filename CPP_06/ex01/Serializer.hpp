#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>
#include "Data.hpp"

class	Serializer {

public:

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

private:

	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other); 
	~Serializer();

};

#endif