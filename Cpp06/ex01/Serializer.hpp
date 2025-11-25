#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstddef>
#include <stdint.h>

struct Data
{
	int i;
	char c;
};

class Serializer
{
public:

static Data* deserialize(uintptr_t raw);
static uintptr_t serialize(Data* ptr);

private:

    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& rhs);
    ~Serializer();

};

#endif // SERIALIZER_HPP
