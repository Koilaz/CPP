#include"Dog.hpp"

Dog::Dog() : AAnimal()
{
	this->_brain = new Brain;
	this->_type = "Dog";
	std::cout<<"A new puppy was born [Dog Constructor]"<<std::endl;
}

Dog::Dog(const Dog& src) : AAnimal(src)
{
	this->_brain =  new Brain(*src._brain);
	this->_type = "Dog";
	std::cout<<"A new puppy was clone [Dog copy Constructor]"<<std::endl;
}

Dog& Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		if(!this->_brain)
			this->_brain =  new Brain(*src._brain);
		*this->_brain = *src._brain;
		this->_type = "Dog";
	}
	return *this;
}

Dog::~Dog()
{
	delete this->_brain;
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

