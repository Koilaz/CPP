#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <cctype>

class Phonebook
{
    public:

        Phonebook();
        void    search_contact();
        void    add_contact();
    
    private:

        Contact list[8];
        int     index;

        void          display_info(Contact contact);
        void          display_tab();
        std::string   add_in_colone(std::string input,std::string cur_line, int colone_number);
};
#endif