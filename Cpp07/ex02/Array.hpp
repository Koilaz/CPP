#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array {

public:

    Array();
	Array(size_t n);
    Array(const Array& other);
    Array& operator=(const Array& rhs);
	T& operator[](size_t index);
	const T& operator[](size_t index) const;
    ~Array();

	size_t size() const;

private:

	size_t	_size;
	T*		head;

};

#include "Array.tpp"

#endif // ARRAY_HPP
