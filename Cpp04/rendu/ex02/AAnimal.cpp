#include"AAnimal.hpp"

AAnimal::AAnimal()
{
	this->_type = "No Type";
	std::cout << "AAnimal " << this->_type << " was born [Constructor]" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
	*this = src;
	std::cout << "AAnimal " << this->_type << " was has a twin [Copy Constructor]" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &src)
{
	this->_type = src._type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal " << this->_type << " rest in peace [AAnimal Destructor]" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "Random animal noise" << std::endl;
}
const std::string& AAnimal::getType() const
{
	return(this->_type);
}
