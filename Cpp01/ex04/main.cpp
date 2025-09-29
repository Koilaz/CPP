#include<string>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <sstream>

void    swap_substr(std::string& str,const std::string& s1,const std::string& s2 )
{
    std::string::size_type pos = 0;

    while((pos = str.find(s1, pos)) != std::string::npos)
    {
            str.erase(pos, s1.size());
            str.insert(pos, s2);
            pos = pos + s2.size();
    }
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr<<"Error\n3 argument expected: file, s1, s2" << std::endl;
        exit(0);
    }
    std::string str_file;
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    std::ifstream file(argv[1]);
    if (!file)
    {
        perror(argv[1]);
        exit(1);
    }
    {
        std::ostringstream oss;
        oss << file.rdbuf();
        str_file = oss.str();
    }
    file.close();
    if(s1.empty() || str_file.empty() || s1 == s2)
        return (0);
    swap_substr(str_file, s1, s2);
    std::ofstream out((std::string(argv[1]) + ".replace").c_str());
    out << str_file;
    return(0);
}
