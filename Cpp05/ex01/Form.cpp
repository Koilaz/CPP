#include "Form.hpp"
#include "Bureaucrat.hpp"

const std::string	Form::getName()const
{
	return(this->_name);
}
bool			Form::is_signed() const
{
	return(this->_signed);
}
int			Form::getReqSign() const
{
	return(this->_req_sign);
}
int			Form::getReqExec() const
{
	return(this->_req_exec);
}
void				Form::beSigned(Bureaucrat bur)
{
	if (bur.getGrade() <= this->_req_sign)
	{
		this->_signed = true;
	}
	else
		throw GradeTooLowException();
}

Form::Form() : _name("Default"), _signed(0), _req_sign(1), _req_exec(1)
{}

Form::Form(const std::string name, int req_sign, int req_exec)
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

Form::Form(const Form& other) :
_name(other._name),
_signed(other._signed),
_req_sign(other._req_sign),
_req_exec(other._req_exec)
{}

Form& Form::operator=(const Form& src)
{
	if (this != &src)
	{
		this->_signed = src._signed;
	}
	return *this;
}

Form::~Form()
{}

std::ostream &operator<<(std::ostream & os, Form const &form)
{
	std::string sig;
	if(form.is_signed())
		sig = " is signed";
	else
		sig = " is NOT signed";
	os << "Form "<< form.getName()<< " required grade to: sign:"
	<<form.getReqSign()<< " exec:"<<form.getReqExec()<< sig;
	return (os);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
