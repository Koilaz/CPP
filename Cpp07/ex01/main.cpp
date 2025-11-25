#include "template.hpp"
#include <string>
#include <iostream>

int main()
{
	std::string str = "abcd ABCD";
	int chiffres[10];

	for (int i = 0; i < 10; ++i)
		chiffres[i] = i;
	std::cout << "str -> ";
	iter(&str[0], static_cast<int>(str.size()),print<char>);
	std::cout<<std::endl;

	std::cout << "chiffres -> ";
	iter(chiffres, 10, print<int>);
	std::cout<<std::endl;

	iter(&str[0], static_cast<int>(str.size()), increase_one<char>);
	iter(chiffres, 10, increase_one<int>);

	// print results
	std::cout << "str -> ";
	iter(&str[0], static_cast<int>(str.size()),print<char>);
	std::cout<<std::endl;

	std::cout << "chiffres -> ";
	iter(chiffres, 10, print<int>);
	std::cout<<std::endl;

	return 0;
}
