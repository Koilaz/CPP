#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{

public:

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin();
	iterator end();
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& rhs);
    ~MutantStack();

private:

};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP
