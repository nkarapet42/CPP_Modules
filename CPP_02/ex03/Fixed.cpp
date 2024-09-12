#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	//std::cout << "Int constructor called" << std::endl;
	this->value = value * (1 << this->bite);
}

Fixed::Fixed(const float value) {
	//std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->bite));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}


Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits( int const raw ) {
	//std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat( void ) const {
	return (static_cast<float>(this->value) / (1 << this->bite));
}

int		Fixed::toInt( void ) const {
	return (this->value >> this->bite);
}

bool	Fixed::operator>(const Fixed& other) const {
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const {
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const {
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const {
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& other) {
	Fixed	result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) {
	Fixed	result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) {
	Fixed	result;

	result.setRawBits(this->getRawBits() * other.getRawBits() >> this->bite);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) {
	Fixed	result;

	result.setRawBits((this->getRawBits() << this->bite) / other.getRawBits());
	return (result);
}

Fixed &Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;

	++(*this);
	return temp;
}

Fixed &Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	
	--(*this);
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return ((a > b) ? a : b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
