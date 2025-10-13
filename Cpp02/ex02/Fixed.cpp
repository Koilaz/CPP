#include "Fixed.hpp"

const int Fixed::_frac_bit = 8;

Fixed::Fixed() : _value(0)
{}

Fixed::Fixed(const Fixed& source)
{
    *this = source; 
}

Fixed& Fixed::operator=(const Fixed& source)
{
	if (this != &source)
		this->_value = source.getRawBits();

	return *this;
}

Fixed::~Fixed()
{}

Fixed::Fixed(const int val)
{
    _value = val<<Fixed::_frac_bit;
}

Fixed::Fixed(const float f_val)
{
	this->_value = roundf(f_val * (1 << Fixed::_frac_bit));
}

float Fixed::toFloat(void) const
{
    return((static_cast<float>(this->_value) / (1 << Fixed::_frac_bit)));
}

int Fixed::toInt( void ) const
{
    return roundf(this->_value / (1 << Fixed::_frac_bit));
}

std::ostream& operator<<(std::ostream& os, Fixed const& fix)
{
    return os << fix.toFloat();
}

bool Fixed::operator>(const Fixed& src) const
{
    return(this->_value > src._value);
}

bool Fixed::operator<(const Fixed& src) const
{
    return(this->_value < src._value);
}

bool Fixed::operator>=(const Fixed& src) const
{
    return(this->_value >= src._value);
}

bool Fixed::operator<=(const Fixed& src) const
{
    return(this->_value <= src._value);
}

bool Fixed::operator==(const Fixed& src) const
{
    return(this->_value == src._value);
}

bool Fixed::operator!=(const Fixed& src) const
{
    return(this->_value != src._value);
}

Fixed	Fixed::operator+(const Fixed& src) const
{
	Fixed	result;

	result.setRawBits(this->_value + src._value);
	return result;
}

Fixed	Fixed::operator-(const Fixed& src) const
{
	Fixed	result;

	result.setRawBits(this->_value - src._value);
	return result;
}

Fixed	Fixed::operator*(const Fixed& src) const
{
	Fixed	result;

	result.setRawBits((this->_value * src._value) >> Fixed::_frac_bit);
	return result;
}

Fixed	Fixed::operator/(const Fixed& src) const
{
	Fixed	result;

	result.setRawBits((this->_value << Fixed::_frac_bit) / src._value);
	return result;
}

Fixed&	Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed	Fixed::operator ++(int)
{
	Fixed	temp(*this);

	this->_value++;
	return temp;
}

Fixed&	Fixed::operator --()
{
	this->_value--;
	return *this;
}

Fixed	Fixed::operator --(int)
{
	Fixed	temp(*this);

	this->_value--;
	return temp;
}

Fixed& Fixed::min(Fixed& A, Fixed& B)
{
    if (A < B)
        return (A);
    else
        return (B);
}

const Fixed& Fixed::min(const Fixed& A,const Fixed& B)
{
    if (A < B)
        return (A);
    else
        return (B);
}

Fixed& Fixed::max(Fixed& A, Fixed& B)
{
    if (A > B)
        return (A);
    else
        return (B);
}

const Fixed& Fixed::max(const Fixed& A,const Fixed& B)
{
    if (A > B)
        return (A);
    else
        return (B);
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}
void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}