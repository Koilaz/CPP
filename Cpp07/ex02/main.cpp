#include "Array.hpp"
#include <string>
#include <iostream>

int main()
{
	Array<int> *a = new Array<int>();
	std::cout << "size: " << a->size() << std::endl;

	const char *str = "salut";
	Array<char> array_char(7);
	for (int i = 0; i < 6; ++i)
		array_char[i] = str[i];
	for (int i = 0; i < 6; ++i)
		std::cout << "at index :" << i << " char = " << array_char[i] << std::endl;
	try
	{
		array_char[42] = '4';
	}
	catch(const std::exception& e)
	{
		std::cerr <<"exception catched : "<< e.what() << '\n';
	}
	std::string string = "Hello World";
	Array<std::string> a_str(string.size());
	for(size_t i = 0; i < a_str.size(); ++i)
		a_str[i] = string[i];
	for(size_t i = 0; i < a_str.size(); ++i)
		std::cout<<a_str[i];
	delete a;
	return 0;
}
