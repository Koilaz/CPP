#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> v;
	std::vector<int>::iterator it;
	v.push_back(4);
	v.push_back(8);
	v.push_back(15);
	v.push_back(16);
	v.push_back(23);
	v.push_back(42);
	v.push_back(8);
	v.push_back(15);
	it = easyfind(v ,42);
	std::cout<<*it;
}
