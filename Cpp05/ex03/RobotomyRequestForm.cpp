#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

bool seed = (std::srand(std::time(NULL)), true);

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	allow_exec(executor);
	std::cout<<"BrrRRRrrr TzzzZZZ Braaaa Poc! Poc! Tralala.. boum boum...."<< std::endl;
	if(std::rand() % 2)
		std::cout << "\033[32m" << this->_target << " has been SUCCESFULLY Robotomyse ! half his brain has been destroyed" << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "Sadly the robotomy of " << this->_target << " has FAILED ! half his brain has been destroyed" << "\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("Robotomy", 72, 45)
, _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy", 72, 45)
, _target("Default target")
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other)
, _target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}
