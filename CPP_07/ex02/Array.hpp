#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class	Array {

public:

	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other); 
	~Array();

	T&	operator[](size_t index);
	const T& operator[](size_t index) const;

	size_t	ArraySize() const;

private:

	T*		array;
	size_t	size;

};

#include "Array.tpp"

#endif