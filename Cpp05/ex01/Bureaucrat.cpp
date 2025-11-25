#include "Bureaucrat.hpp"

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout<<this->_name<<" signed "<<form.getName()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout <<this->_name<<" couldn't sign "<<form.getName()<< " because "<< e.what() << '\n';
	}

}

void	Bureaucrat::promotion(int pro)
{
	if (this->_grade - pro < 1)
		throw GradeTooHighException();
	else
		this->_grade -= pro;
}
void	Bureaucrat::demotion(int dem)
{
	if (this->_grade + dem > 150)
		throw GradeTooLowException();
	else
		this->_grade += dem;
}

const std::string	Bureaucrat::getName() const
{
	return(this->_name);
}
int	Bureaucrat::getGrade() const
{
	return(this->_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("grade too low");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat() : _name("Random Bureaucrat") , _grade(150)
{}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) , _grade(other._grade)
{
		if (this->_grade > 150)
		throw GradeTooLowException();
	else if (this->_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    if (this != &src)
		this->_grade = src._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{}

std::ostream &operator<<(std::ostream & os, Bureaucrat const &bur)
{
	os << bur.getName()<< ", bureaucrat grade "<< bur.getGrade();
	return (os);
}
