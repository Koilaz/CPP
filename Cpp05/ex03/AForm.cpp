#include "AForm.hpp"
#include "Bureaucrat.hpp"

void	AForm::allow_exec(Bureaucrat const &executor) const
{
	if(!this->is_signed())
	{
		std::cout<<executor.getName()<<" could not execute "
		<<this->getName()<< " because ";
		throw FormNotSignedException();
	}
	if(executor.getGrade() > this->_req_exec)
	{
		std::cout<<executor.getName()<<" could not execute "
		<<this->getName()<< " because ";
		throw  GradeTooLowException();
	}
}

const std::string	AForm::getName()const
{
	return(this->_name);
}

bool			AForm::is_signed() const
{
	return(this->_signed);
}

int			AForm::getReqSign() const
{
	return(this->_req_sign);
}

int			AForm::getReqExec() const
{
	return(this->_req_exec);
}

void	AForm::beSigned(Bureaucrat bur)
{
	if (bur.getGrade() <= this->_req_sign)
	{
		this->_signed = true;
		std::cout<<"form "<<this->getName()<< " has been signed by "<<bur.getName()<<std::endl;
	}
	else
	{
		std::cout<<"Form can't be sign by "<< bur.getName() << " because: ";
		throw GradeTooLowException();
	}
}

AForm::AForm() : _name("Default"), _signed(0), _req_sign(1), _req_exec(1)
{}

AForm::AForm(const std::string name, int req_sign, int req_exec)
: _name(name),
_signed(false),
_req_sign(req_sign),
_req_exec(req_exec)
{
	if (_req_exec > 150 || _req_sign > 150)
		throw GradeTooLowException();
	if (_req_exec < 1 || _req_sign < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other) :
_name(other._name),
_signed(other._signed),
_req_sign(other._req_sign),
_req_exec(other._req_exec)
{}

AForm& AForm::operator=(const AForm& src)
{
	if (this != &src)
	{
		this->_signed = src._signed;
	}
	return *this;
}

AForm::~AForm()
{}

std::ostream &operator<<(std::ostream & os, AForm const &form)
{
	std::string sig;
	if(form.is_signed())
		sig = " is signed";
	else
		sig = " is NOT signed";
	os << "AForm "<< form.getName()<< " required grade to sign:"
	<<form.getReqSign()<< " exec:"<<form.getReqExec()<< sig;
	return (os);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form in not signed");
}
