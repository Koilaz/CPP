#include "Fixed.hpp"

const int Fixed::_frac_bit = 8;

Fixed::Fixed() : _value(0)
{
    std::cout<<"Default constructor called"<<std::endl;
}
Fixed::Fixed(const Fixed& source)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = source; 
}

Fixed& Fixed::operator=(const Fixed& source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
		this->_value = source.getRawBits();

	return *this;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called." << std::endl;
    _value = val<<Fixed::_frac_bit;
}

Fixed::Fixed(const float f_val)
{
	std::cout << "Float constructor called." << std::endl;
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

int Fixed::getRawBits(void) const
{
    return (this->_value);
}
void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}