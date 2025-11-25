#include"Cat.hpp"

Cat::Cat()
{
	this->_brain = new Brain;
	this->_type = "Cat";
	std::cout<<"A new kitty was born [Cat Constructor]"<<std::endl;
}

Cat::Cat(const Cat& src)
{
	this->_brain =  new Brain(*src._brain);
	this->_type = src._type;
	std::cout<<"A new kitty was clone [Cat copy Constructor]"<<std::endl;
}

Cat& Cat::operator=(const Cat &src)
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

Cat::~Cat()
{
	delete this->_brain;
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

void Cat::setIdea(const std::string n_idea, int i)
{
	this->_brain->ideas[i] = n_idea;
}

std::string Cat::getIdea(int i)
{
	return(this->_brain->ideas[i]);
}
