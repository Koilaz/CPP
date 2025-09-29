/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:58:53 by leo               #+#    #+#             */
/*   Updated: 2025/09/23 11:38:08 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

static bool has_printable(const std::string& str) 
{
    if (str.empty())
        return false;

    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (!std::isspace(static_cast<unsigned char>(*it)))
        {
            return true;
        }
    }
    return false;
}

static bool parse_int_ss(const std::string& s, int& out)
{
    std::istringstream iss(s);
    iss >> std::ws >> out;
    if (!iss)
        return(0);
    iss >> std::ws;
    if (iss.eof())
        return(1);
    return(0);
}

Phonebook::Phonebook() : index(0){}

std::string Phonebook::add_in_colone(std::string input,std::string cur_line, int colone_number)
{
    int start;
    
    if (input.size() > 10)
    {
        input.resize(9);
        start = colone_number * 11;
        cur_line.replace(start, 9, input);
        cur_line.replace(start + 9, 1, ".");
    }
    else
    {
        start = (colone_number * 11) + 10 - input.size();
        cur_line.replace(start, input.size(), input);
    }
    return (cur_line);
}

void    Phonebook::display_tab()
{
    int         index = 0;
    char        index_char;
    std::string current_line;
    const std::string empty_line = "          |          |          |          ";
    
    std::cout << "     Index|First name| Last name|  Nickname"<< std::endl;
    while (index < 8)
    {
        index_char = '0' + index + 1;
        std::string index_str(1, index_char);
        current_line = add_in_colone(index_str, empty_line, 0);
        for(int j = 0; j < 3; ++j)
            current_line = add_in_colone(list[index].info[j],current_line, j + 1);
        std::cout << current_line << std::endl;
        index++;
    }   
}

void    Phonebook::display_info(Contact contact)
{
    std::cout << "first name: " << contact.info[0] << std::endl;
    std::cout << "last name: " << contact.info[1] << std::endl;
    std::cout << "nickname: " << contact.info[2] << std::endl;
    std::cout << "phone number: " << contact.info[3] << std::endl;
    std::cout << "dark secret: " << contact.info[4] << std::endl;
}

void    Phonebook::search_contact()
{
    std::string         input;
    int                 intput;
    
    if (list[0].info[0] == "")
    {
        std::cout << "Contact list is empty" << std::endl;
        return;
    }
    display_tab();
    while(1)
    {
        std::cout << "Enter contact index (1-8):" << std::endl;
        if(!std::getline(std::cin, input))
            return ;
        if (parse_int_ss(input, intput) && intput >= 1 && intput <= 8
        && list[intput-1].info[0] != "")
        {
            display_info(list[intput - 1]);
            break;
        }
        else
            std::cout << "Wrong index, enter an existing contact index"<< std::endl;
    }
}

void    Phonebook::add_contact()
{
    std::string         input;
    int                 i;
    static const char*  prompts[5] =
    {
        "Enter first name:",
        "Enter Last name:",
        "Enter Nickname:",
        "Enter Phone number:",
        "Enter your darkest secret:"
    };
    
    if (index >= 8)
        index = 0;
    for(i = 0; i < 5; ++i)
    {
        while(1)
        {
            std::cout << prompts[i] << std::endl;
            std::getline(std::cin, input);
            if(has_printable(input))
            {
                list[index].info[i] = input;
                break;
            }
        }
    }
    std::cout << "Contact " << (index + 1) << " succesfully added\n";
    index++;
}