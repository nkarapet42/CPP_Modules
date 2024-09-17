#include "Serializer.hpp"

int	main(void) {
	Data		meta;

	meta.num = 75;
	meta.c = 'a';
	uintptr_t	tmp = Serializer::serialize(&meta);
	std::cout << tmp << std::endl;
	Data*		delta = Serializer::deserialize(tmp);
	std::cout << delta->num << std::endl;
	std::cout << delta->c << std::endl;
	return (0);
}