#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <vector>
#include <deque>
#include <iostream>
#include <exception>

template <typename T>
class MutantStack : public std::stack<T> {

public:

	MutantStack();
	MutantStack(const MutantStack& other);
	MutantStack& operator=(const MutantStack& other); 
	~MutantStack();

	typedef	std::deque<T> cont;
	typedef	typename cont::iterator iterator;
	typedef	typename cont::const_iterator const_iterator;
	typedef	typename cont::reverse_iterator reverse_iterator;
	typedef	typename cont::const_reverse_iterator const_reverse_iterator;

	iterator				begin();
	iterator				end();
	const_iterator			begin() const;
	const_iterator			end() const;
	reverse_iterator		rbegin();
	reverse_iterator		rend();
	const_reverse_iterator	rbegin() const;
	const_reverse_iterator	rend() const;

};

#include "MutantStack.tpp"

#endif