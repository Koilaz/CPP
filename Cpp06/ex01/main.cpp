#include "Serializer.hpp"

int main()
{
	Data ptr;
	ptr.i = 8;
	ptr.c = 'c';

	uintptr_t raw = 0;
	raw = Serializer::serialize(&ptr);

	Data *ptr2 = Serializer::deserialize(raw);
	std::cout<<ptr2->c<<std::endl;
}
