
#include"WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->_type = "No Type";
	std::cout << "WrongAnimal " << this->_type << " was born [Constructor]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	*this = src;
	std::cout << "WrongAnimal " << this->_type << " was has a twin [Copy Constructor]" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
	this->_type = src._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << this->_type << " rest in peace [Destructor]" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Ramdom wrong animal noise \"flic flac flouc\"" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
    return (this->_type);
}

