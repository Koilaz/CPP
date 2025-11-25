#include"Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout<<"A new kitty was born [Cat Constructor]"<<std::endl;
}

Cat::Cat(const Cat& src)
{
	*this = src;
	std::cout<<"A new kitty was clone [Cat copy Constructor]"<<std::endl;
}

Cat& Cat::operator=(const Cat &src)
{
	this->_type = src._type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat " << this->_type << " rest in peace [Cat Destructor]" << std::endl;
}

const std::string& Cat::getType() const
{
	return(this->_type);
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;
}
