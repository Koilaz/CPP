#include "ScalarConverter.hpp"

static bool isspecial(std::string input);
static bool isint(std::string input, int &i);
static bool ischar(std::string input, char &c);
static bool isdouble(std::string input, double &buf);
static bool isfloat(std::string input, float &f);
static void convert_special(std::string input);
static void convert_buf(double buf);
static void to_char(double d);
static void to_float(double d);
static void to_int(double d);
static void to_double(double d);

void ScalarConverter::convert(std::string input)
{
	double		buf = 0;
	int			i = 0;
	float		f = 0;
	char		c = 0;

	if (input.empty())
	{
		std::cerr<<"Error\nEmpty string"<<std::endl;
		return;
	}
	if (isspecial(input))
		convert_special(input);
	else if (isint(input, i))
		convert_buf(static_cast<double>(i));
	else if (ischar(input, c))
		convert_buf(static_cast<double>(c));
	else if (isdouble(input, buf))
		convert_buf(buf);
	else if (isfloat(input, f))
		convert_buf(static_cast<double>(f));
	else
		std::cerr<<"Error\nWrong format"<<std::endl;
}

static void convert_buf(double tmp)
{
	to_char(tmp);
	to_int(tmp);
	to_float(tmp);
	to_double(tmp);
}

static void to_int(double d)
{
	int i;
	if (d > INT_MAX || d < INT_MIN)
	{
		std::cout<<"int: Impossible"<<std::endl;
		return;
	}
	i = static_cast<int>(d);
	std::cout<<"int: "<<i<<std::endl;
}

static void to_double(double d)
{
	std::cout<<"double: "<<d<<std::endl;
}

static void to_float(double d)
{
	if(d > FLT_MAX)
	{
		std::cout<<"float: inff"<<std::endl;
		return;
	}
	if(d < -FLT_MAX)
	{
		std::cout<<"float: -inff"<<std::endl;
		return;
	}
	float f;
	f = static_cast<float>(d);
	std::cout<<"float: "<< std::fixed << std::setprecision(1) <<f<<'f'<<std::endl;
}

static void to_char(double d)
{
	char c;
	if (d > CHAR_MAX || d < CHAR_MIN || d != std::floor(d) || (d - d) != 0)
	{
		std::cout<<"char: Impossible"<<std::endl;
		return;
	}
	c = static_cast<char>(d);
	if (isprint(static_cast<unsigned char>(c)))
		std::cout<<"char: '"<< c << "\'"<<std::endl;
	else
		std::cout<<"char: Non Displayable"<<std::endl;
}

static bool isint(std::string input, int &i)
{
	char *end;
	long l;

	l = strtol(input.c_str(), &end, 10);
	if(*end != '\0' || l > INT_MAX || l < INT_MIN)
		return false;
	i = static_cast<int>(l);
	return true;
}

static bool ischar(std::string input, char &c)
{
	if (input[1] == '\0' && !isdigit(static_cast<int>(input[0])))
	{
		c = input[0];
		return true;
	}
	return false;
}
static bool isdouble(std::string input, double &buf)
{
	char *end;

	buf = strtod(input.c_str(), &end);
	if(*end != '\0')
		return false;
	return true;
}
static bool isfloat(std::string input, float &f)
{
	char *end;

	f = static_cast<float>(strtod(input.c_str(), &end));
	if((*end == 'f' || *end == 'F') && *(end+1) == '\0')
		return true;
	return false;
}

static bool isspecial(std::string input)
{
	if (input == "+inf" || input == "-inf" || input == "nan"
		||input == "nanf" ||input == "-inff" ||input == "+inff")
		return true;
	return false;
}

static void convert_special(std::string input)
{
	int n = 3;

	if (input[0] == '-' || input[0] == '+')
		n = 4;
	std::cout<<"char: Impossible"<<std::endl;
	std::cout<<"int: Impossible"<<std::endl;
	std::cout<<"float: "<<input.substr(0, n)<<"f"<<std::endl;
	std::cout<<"double: "<<input.substr(0, n)<<std::endl;
}

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	(void)src;
    return *this;
}

ScalarConverter::~ScalarConverter()
{}
