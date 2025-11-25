#pragma once

template<typename T>
typename T::iterator easyfind(T &cont, int value)
{
	return std::find(cont.begin(), cont.end(), value);
}

