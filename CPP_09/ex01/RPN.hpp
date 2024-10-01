#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

class RPN {

public:

	RPN();
	~RPN();

	int	solving(std::string eq);

private:

	RPN(const RPN&);
	RPN& operator=(const RPN&);


};

#endif