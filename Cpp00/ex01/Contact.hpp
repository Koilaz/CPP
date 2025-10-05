#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
    Contact();
    void setInfo(int index, const std::string& value);
    std::string getInfo(int index) const;
    
private:
    std::string  info[5];
};
#endif