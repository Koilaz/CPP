#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include<limits.h>
#include <cfloat>
#include <iomanip>
#include <math.h>



class ScalarConverter {

public:

	static void convert(std::string input);

private:

    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& rhs);
    ~ScalarConverter();

};

#endif
