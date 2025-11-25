#include"Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout<<"A new puppy was born [Dog Constructor]"<<std::endl;
}

Dog::Dog(const Dog& src)
{
	*this = src;
	std::cout<<"A new puppy was clone [Dog copy Constructor]"<<std::endl;
}

Dog& Dog::operator=(const Dog &src)
{
	this->_type = src._type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog " << this->_type << " rest in peace [Dog Destructor]" << std::endl;
}

const std::string& Dog::getType() const
{
	return(this->_type);
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

