#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern {
public:

	AForm *makeForm(std::string form_name, std::string target);
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& rhs);
    ~Intern();

private:

};

#endif // INTERN_HPP
