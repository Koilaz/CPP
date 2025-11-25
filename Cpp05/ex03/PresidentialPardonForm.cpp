#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		allow_exec(executor);
		std::cout<<this->_target<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
	}
	catch(const std::exception& e)
	{
		throw;
	}
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("Pardon", 25, 5)
, _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Pardon", 25, 5)
, _target("Default target")
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other)
, _target(other._target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}
