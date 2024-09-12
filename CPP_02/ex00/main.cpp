#include <iostream>
#include "Fixed.hpp"

int main(void) {
	
	Fixed a;
	a.setRawBits(15);
	Fixed b( a );
	a.setRawBits(35);

	Fixed c;
	c = b;
	b.setRawBits(1555);
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return 0;
}