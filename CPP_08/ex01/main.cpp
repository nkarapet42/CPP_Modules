#include "Span.hpp"

int	main(void) {
	
	try
	{
		Span	sp = Span(5);

		sp.addNumber(27);
		sp.addNumber(3);
		sp.addNumber(44);
		sp.addNumber(-5);
		sp.addNumber(648);
		sp.addNumber(71);
	}
	catch(const std::length_error& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Span	sp = Span(5);

		int		arr[] = {12, 52, 521, 124, -23, 1};
		sp.addNumbers(arr, arr + 5);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::length_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Span	sp = Span(6);

		std::vector<int> vs;

		vs.push_back(-54);
		vs.push_back(42);
		vs.push_back(592);
		vs.push_back(1024);
		vs.push_back(-23);
		vs.push_back(1);

		sp.addNumbers(vs.begin(), vs.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::length_error& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Span	sp = Span(6);

		std::vector<int> vs;

		vs.push_back(-54);

		sp.addNumbers(vs.begin(), vs.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::length_error& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}