#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <limits>
#include <iostream>
#include <algorithm>
#include <exception>

class	Span {

public:

	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other); 
	~Span();

	void	addNumber(int value);

	template <typename T>
	void	addNumbers(T begin, T end);

	int		shortestSpan();
	int		longestSpan();

private:

	std::vector<int>	num;
	unsigned int		N;

};

template <typename T>
void	Span::addNumbers(T begin, T end) {
	while (begin != end) {
		addNumber(*begin);
		++begin;
	}
}

#endif