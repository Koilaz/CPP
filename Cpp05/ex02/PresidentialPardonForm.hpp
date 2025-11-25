#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include"AForm.hpp"


class PresidentialPardonForm : public AForm
{
public:

	virtual void		execute(Bureaucrat const &executor) const;

	PresidentialPardonForm(std::string target);
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
    ~PresidentialPardonForm();

private:

	std::string	_target;

};

#endif
