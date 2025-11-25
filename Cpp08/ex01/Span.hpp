#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include <climits>
# include<algorithm>


class Span
{
	public:

	void addNumber(int n);
	template<typename it>
	void addMultipleNumber(it begin, it end);

	Span(int);
	Span();
	unsigned int longestSpan(void);
	unsigned int shortestSpan(void);
    Span(const Span& other);
    Span& operator=(const Span& rhs);
    ~Span();

	private:

	std::vector<int>	_vector;
	unsigned int		_max;
	unsigned int		_filled;

	class MaxCapacityReachedException : public std::exception
	{
		public:

		virtual const char* what() const throw();
	};

	class NoSpanPossibleException : public std::exception
	{
		public:

		virtual const char* what() const throw();
	};
};

template<typename it>
void Span::addMultipleNumber(it begin, it end)
{
	while(begin <= end)
	{
		addNumber(*begin);
		begin++;
	}
}

#endif // SPAN_HPP
