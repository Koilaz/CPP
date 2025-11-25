	#include "Ice.hpp"

	Ice::Ice(const Ice &src) : AMateria()
	{ this->_type = src.getType(); }

	Ice& Ice::operator=(const Ice &src)
	{
		if (this != &src)
			AMateria::operator=(src);
		return *this;
	}

	AMateria* Ice::clone() const
	{
		AMateria *clone = new Ice;
		return(clone);
	}

	void Ice::use(ICharacter& target)
	{
		std::cout<<"* shoots an ice bolt at "<< target.getName()<< " *"<<std::endl;
	}
