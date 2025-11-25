#include"Brain.hpp"


Brain::Brain()
{
	std::cout << "A new mind was gifted counsciousness [Brain Constructor]" << std::endl;
}

Brain::Brain(const Brain& src)
{
	*this = src;
	std::cout << "Wolololo [Brain Copy Constructor]" << std::endl;
}

Brain& Brain::operator=(const Brain &src)
{
	for(int i = 0; i < 100; ++i)
		this->ideas[i] = src.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain is watching TV [Brain Destructor]" << std::endl;
}
