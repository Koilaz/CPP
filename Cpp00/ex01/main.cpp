#include "Phonebook.hpp"
#include <iostream>


int main(void)
{
    std::string input;
    Phonebook   pb;
    
    while(42)
    {
        std::cout << "Please Enter one of the following command " << std::endl
        << "ADD, SEARCH, EXIT" << std::endl;
        if (!std::getline(std::cin, input))
            break;
        if (input == "EXIT")
            return(0);
        else if (input == "ADD")
            pb.add_contact();
        else if (input == "SEARCH")
            pb.search_contact();
        else
            std::cout << "unkown command." << std::endl;
    }
    return (0);
}