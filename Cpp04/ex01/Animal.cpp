#include"Animal.hpp"

Animal::Animal()
{
	this->_type = "No Type";
	std::cout << "Animal " << this->_type << " was born [Constructor]" << std::endl;
}

Animal::Animal(const Animal& src)
{
	*this = src;
	std::cout << "Animal " << this->_type << " was has a twin [Copy Constructor]" << std::endl;
}

Animal& Animal::operator=(const Animal &src)
{
	this->_type = src._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal " << this->_type << " rest in peace [Animal Destructor]" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Random animal noise" << std::endl;
}
const std::string& Animal::getType() const
{
	return(this->_type);
}
