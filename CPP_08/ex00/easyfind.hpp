#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <exception>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& cont, int to_find) {
	typename T::iterator it = std::find(cont.begin(), cont.end(), to_find);

	if (it == cont.end())
		throw std::out_of_range("Can't find Occurrence");
	return (it);
}

#endif