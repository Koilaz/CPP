#include"WrongDog.hpp"

WrongDog::WrongDog()
{
	this->_type = "WrongDog";
	std::cout<<"A new puppy was born [WrongDog Constructor]"<<std::endl;
}

WrongDog::WrongDog(const WrongDog& src)
{
	*this = src;
	std::cout<<"A new puppy was clone [WrongDog copy Constructor]"<<std::endl;
}

WrongDog& WrongDog::operator=(const WrongDog &src)
{
	this->_type = src._type;
	return *this;
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog " << this->_type << " rest in peace [WrongDog Destructor]" << std::endl;
}

const std::string& WrongDog::getType() const
{
	return(this->_type);
}

void WrongDog::makeSound() const
{
	std::cout << "Wrong Dog Noises blou blou" << std::endl;
}
