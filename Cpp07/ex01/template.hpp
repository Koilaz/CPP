#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

# include <iostream>

template<typename T, typename L, typename F>
void iter(T *array, L size, F function)
{
	for (L i = 0; i < size; ++i)
		function(array[i]);
}

template<typename T>
void increase_one(T &a)
{
	a = a + 1;
}
template<typename T>
void print(const T &a)
{
	std::cout<<a;
}

#endif
