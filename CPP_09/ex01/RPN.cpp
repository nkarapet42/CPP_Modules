#include "RPN.hpp"
#include <string>
#include <cctype>
#include <climits>
#include <cstddef>

RPN::RPN() {}

RPN::RPN(const RPN&) {}

RPN& RPN::operator=(const RPN&) {return (*this);}

static bool isOperator(int c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

static bool check(std::string& eq) {
	for (size_t i = 0; i < eq.length(); i++) {
		if (isOperator(eq[i]) == false && std::isdigit(eq[i]) == false && std::isspace(eq[i]) == false)
			return false;
	}
	for (size_t i = 0; i < eq.length(); i++) {
		while (eq[i] && std::isspace(eq[i]))
			i++;
		if (std::isdigit(eq[i]) && std::isdigit(eq[i + 1]))
			return false;
	}
	return true;
}

static int calculator(long long num1, long long num2, int c) {
	long long check = 0;

	switch (c) {
		case '+':
			check = num1 + num2;
			break ;
		case '-':
			check = num1 - num2;
			break ;
		case '*':
			check = num1 * num2;
			break ;
		case '/':
			if (num2 == 0)
				exit (1 && (std::cout << "Error" << std::endl));
			check = num1 / num2;
			break ;
	}
	if (check < INT_MIN || check > INT_MAX)
			exit (1 && (std::cout << "Error" << std::endl));
	return (check);
}

int	RPN::solving(std::string eq) {
	if (!check(eq))
		exit (1 && (std::cout << "Error" << std::endl));
	std::stack<int>	solve;

	for (size_t i = 0; i < eq.length(); i++) {
		if (isOperator(eq[i])) {
			if (solve.size() < 2)
				exit (1 && (std::cout << "Error" << std::endl));
			int	num2 = solve.top();
			solve.pop();
			int	num1 = solve.top();
			solve.pop();
			int res = calculator(num1, num2, eq[i]);
			solve.push(res);
		}
		else if (std::isdigit(eq[i]))
			solve.push(eq[i] - '0');
	}
	if (solve.size() != 1)
		exit (1 && (std::cout << "Error" << std::endl));
	return (solve.top());
}

RPN::~RPN() {}