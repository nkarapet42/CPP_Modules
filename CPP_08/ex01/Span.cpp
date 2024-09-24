#include "Span.hpp"

Span::Span() : N(0) {
	std::cout << "Default constructor was called" << std::endl;
}

Span::Span(unsigned int N) : N(N) {
	std::cout << "Constructor with parameters was called" << std::endl;
}

Span::Span(const Span& other) : N(other.N) {
	std::cout << "Copy constructor was called" <<  std::endl;
	num = other.num;
}

Span&	Span::operator=(const Span& other) {
	std::cout << "Copy assigment operator was called" << std::endl;
	if (this != &other) {
		N = other.N;
		num = other.num;
	}
	return (*this);
}

void	Span::addNumber(int value) {
	if (num.size() >= this->N)
		throw std::length_error("Length overflow");
	num.push_back(value);
}

int		Span::shortestSpan() {
	if (num.size() <= 1)
		throw std::length_error("Not long enough");
	std::vector<int>	sorted = num;
	std::sort(sorted.begin(), sorted.end());

	// for (size_t i = 0; i < num.size(); i++)
	// 		std::cout << "-->(" << num[i] << ")";
	// std::cout << std::endl;
	// for (size_t i = 0; i < sorted.size(); i++)
	// 		std::cout << "-->(" << sorted[i] << ")";
	// std::cout << std::endl;
	int	shortest = std::numeric_limits<int>::max();
	int	tmp;
	for (size_t i = 1; i < sorted.size(); i++) {
		tmp = sorted[i] - sorted[i - 1];
		if (tmp < shortest) {
			shortest = tmp;
		}
	}
	return (shortest);
}

int		Span::longestSpan() {
	if (num.size() <= 1)
		throw std::length_error("Not long enough");
	return (*std::max_element(num.begin(), num.end()) - *std::min_element(num.begin(), num.end()));
}

Span::~Span() {
	std::cout << "Destructor was called" << std::endl;
}