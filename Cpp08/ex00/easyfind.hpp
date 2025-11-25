#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T &cont, int value);

#include "easyfind.tpp"

#endif // EASYFIND_HPP
