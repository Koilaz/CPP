#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
public:

	virtual void		execute(Bureaucrat const &executor) const;

    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
    ~ShrubberyCreationForm();

private:

    std::string _target;

};

#define ASCII_TREE \
"               ,@@@@@@@,\n" \
"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n" \
"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n" \
"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n" \
"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n" \
"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n" \
"   `&%\\ ` /%&'    |.|        \\ '|8'\n" \
"       |o|        | |         | |\n" \
"       |.|        | |         | |\n" \
"jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\//.  \\_//__/_\n"


#endif // SHRUBBERYCREATIONFORM_HPP
