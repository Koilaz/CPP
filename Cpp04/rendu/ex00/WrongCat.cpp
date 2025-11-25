#include"WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout<<"A new kitty was born [WrongCat Constructor]"<<std::endl;
}

WrongCat::WrongCat(const WrongCat& src)
{
	*this = src;
	std::cout<<"A new kitty was clone [WrongCat copy Constructor]"<<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &src)
{
	this->_type = src._type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << this->_type << " rest in peace [WrongCat Destructor]" << std::endl;
}

const std::string& WrongCat::getType() const
{
	return(this->_type);
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Cat noises" << std::endl;
}
