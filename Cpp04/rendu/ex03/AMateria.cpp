#include"AMateria.hpp"

AMateria::AMateria(): _type("Undefined")
{}
AMateria::AMateria(std::string const &type) :_type(type)
{}
AMateria::AMateria(AMateria &src)
{
	this->_type = src.getType();
}
AMateria& AMateria::operator=(const AMateria &src)
{
	this->_type = src.getType();
	return *this;
}
AMateria::~AMateria()
{}

std::string const &AMateria::getType() const
{
	return(this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses materia on " << target.getName() << " *" << std::endl;
}
