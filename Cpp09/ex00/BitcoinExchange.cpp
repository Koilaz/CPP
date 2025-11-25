#include "BitcoinExchange.hpp"

static bool validation_date(const int year,const int month,const int day);
static bool has_print(std::string &str);

void BitcoinExchange::import_data(std::string path)
{
	std::string buf;

	std::ifstream file(path.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open file: " + path);
	try
	{
	while (std::getline(file, buf))
	{
		if (buf == "date,exchange_rate")
			continue;
		data_rate[strtodate(buf)] = strtod(&buf.c_str()[11], NULL);
	}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void BitcoinExchange::output_value(std::string path)
{
	std::string buf;
	double btc_amount;
	Date input_date;
	double dollar_value;
	std::map<Date, double, Date_comparator>::iterator it;


	std::ifstream file(path.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open file: " + path);
	while (std::getline(file, buf))
	{
		try
		{
			if(!has_print(buf))
			{
				std::cout<<"Error Empty line"<<std::endl;
				continue;;
			}
			if(buf.size() < 13)
					throw UnvalidDateException(buf);
			btc_amount = strtod(&buf.c_str()[12], NULL);
			input_date = strtodate(buf);
			if(btc_amount > 1000)
				throw TooBigAmountException();
			if (btc_amount < 0)
				throw NotAPositiveException();
			it = data_rate.lower_bound(input_date);
			if(it == data_rate.end())
				it--;
			dollar_value = btc_amount * it->second;
			std::cout<<buf.substr(0, 12) <<" => "<< btc_amount<< " = "<<dollar_value<<std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
bool Date_comparator::operator()(Date const &a, Date const &b) const
{
	if (a.year < b.year)
		return true;
	if (a.year > b.year)
		return false;
	if (a.month < b.month)
		return true;
	if(a.month > b.month)
		return false;
	if (a.day < b.day)
		return true;
	return false;
}

Date	BitcoinExchange::strtodate(std::string line)
{
	Date date;

	if(line.size() < 10)
		throw UnvalidDateException(line);
	date.year = atoi(line.substr(0, 4).c_str());
	date.month = atoi(line.substr(5, 2).c_str());
	date.day = atoi(line.substr(8, 2).c_str());
	if (!validation_date(date.year,date.month,date.day) /*|| line.size() < 12 || line.substr(10,3) != " | "*/)
		throw UnvalidDateException(line);
	return date;
}

static bool has_print(std::string &str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isspace(static_cast<unsigned char>(str[i])))
			return true;
    }
    return false;
}
static bool validation_date(const int year,const int month,const int day)
{
	if (year <= 1900 || year > 3000 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	return true;
}

BitcoinExchange::UnvalidDateException::UnvalidDateException(const std::string& line) : _line(line)
{
	_msg = "Error bad input => " + _line;
}

BitcoinExchange::UnvalidDateException::~UnvalidDateException() throw() {}

const char* BitcoinExchange::UnvalidDateException::what() const throw()
{
	return _msg.c_str();
}

const char* BitcoinExchange::TooBigAmountException::what() const throw()
{
	return"Error Too large number";
}
const char* BitcoinExchange::NotAPositiveException::what() const throw()
{
	return"Error Not a positiv number";
}

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	(void) other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	(void) src;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}
