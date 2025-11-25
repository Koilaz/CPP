#include "Span.hpp"

void Span::addNumber(int n)
{
	if (_filled < _max)
	{
		_vector.push_back(n);
		_filled++;
	}
	else
		throw MaxCapacityReachedException();
}

unsigned int Span::shortestSpan(void)
{
	if (_vector.size() <= 1)
		throw NoSpanPossibleException();
	else
	{
		std::vector<int>::iterator it  = _vector.begin();
		std::vector<int>::iterator comp;
		int min = INT_MAX;
		while(it < _vector.end() - 1)
		{
			comp = it + 1;
			while(comp < _vector.end())
			{
				if(std::abs(*it - *comp) < min)
					min = std::abs(*it - *comp);
				comp++;
			}
			it++;
		}
		return min;
	}
	return -1;
}

unsigned int Span::longestSpan(void)
{
	if (_vector.size() <= 1)
		throw NoSpanPossibleException();
	else
	{
		std::vector<int>::iterator min_it  = std::min_element(_vector.begin(), _vector.end());
		std::vector<int>::iterator max_it  = std::max_element(_vector.begin(), _vector.end());
		return (*max_it - *min_it);
	}
	return -1;
}

const char* Span::MaxCapacityReachedException::what() const throw()
{
	return "Exception: Max capacity reached";
}

const char* Span::NoSpanPossibleException::what() const throw()
{
	return "Exception: no span possible";
}

Span::Span(int n) : _max(n), _filled(0)
{}

Span::Span() : _max(0), _filled(0)
{}

Span::Span(const Span& other) : _max(other._max)
{}

Span& Span::operator=(const Span& src)
{
    if (this != &src)
	{
		_filled = src._filled;
		_max = src._max;
		_vector = src._vector;
    }
    return *this;
}

Span::~Span()
{

}
