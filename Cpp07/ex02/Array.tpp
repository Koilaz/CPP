#pragma once
#include "Array.hpp"

template<typename T>
size_t Array<T>::size() const
{
	return(this->_size);
}

template<typename T>
Array<T>::Array() : _size(0)
{
	head = NULL;
}

template<typename T>
Array<T>::Array(size_t n) : _size(n)
{
	head = new T[n];
}

template<typename T>
Array<T>::Array(const Array& other)
{
	this->_size = other._size;
	head = new T[this->_size];
	for(size_t i = 0; i < this->_size; ++i)
		head[i] = other.head[i];
}
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other)
	{
		this->_size = other._size;
		head = new T[this->_size];
		for(size_t i = 0; i < this->_size; ++i)
			head[i] = other.head[i];
		delete[] head;
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw std::out_of_range("Index is out of range");
	return (head[index]);
}

template<typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw std::out_of_range("Index is out of range");
	return (head[index]);
}

template<typename T>
Array<T>::~Array()
{
	delete[] head;
}
