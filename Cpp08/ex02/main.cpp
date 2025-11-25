#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int main()
/*{
	MutantStack<int> ms;
	for(int i = 0;i < 10; ++i)
	{
		ms.push(i);
	}
	MutantStack<int>::iterator it = ms.begin();
	for(; it != ms.end(); it++)
		std::cout<<*it<<" ";

	return 0;
}*/
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(12);
	std::cout <<"top : "<< mstack.top() << std::endl;
	mstack.pop();
	std::cout <<"size :"<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
