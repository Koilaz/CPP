#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>

struct Date
{
	int	year;
	int	month;
	int	day;
};

struct Date_comparator
{
	bool operator()(Date const &a, Date const &b) const;
};

class BitcoinExchange
{
public:

	void import_data(std::string path);
	void output_value(std::string path);

	class UnvalidDateException : public std::exception
	{
	public:
		UnvalidDateException(const std::string& line);
		virtual ~UnvalidDateException() throw();
		virtual const char* what() const throw();

	private:
		std::string _line;
		std::string _msg;
	};

	class TooBigAmountException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	class NotAPositiveException : public std::exception
	{
		public:
		virtual const char* what() const throw();
	};

	BitcoinExchange();
	~BitcoinExchange();

private:

	std::map<Date, double, Date_comparator> input_file;
	std::map<Date, double, Date_comparator> data_rate;

	Date strtodate(std::string line);

	BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& rhs);
};

#endif
