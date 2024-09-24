#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T* array, size_t size, void (*func)(T &)) {
	if (!array || !func){
		std::cout << "Wrong parameters" << std::endl;
		return ;
	}
	for (size_t i = 0; i < size; i++)
		func(array[i]);
};

template<typename T>
void	iter(const T* array, size_t size, void (*func)(const T &)) {
	if (!array || !func){
		std::cout << "Wrong parameters" << std::endl;
		return ;
	}
	for (size_t i = 0; i < size; i++)
		func(array[i]);
};

template<typename T>
void	printInt(T& num) {
	std::cout << num << std::endl; 
}

template<typename T>
void	printChar(T& c) {
	std::cout << c << std::endl; 
}

#endif