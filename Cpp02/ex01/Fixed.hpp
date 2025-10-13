#include<string>
#include<iostream>
#include<cmath>

class Fixed
{
private:
    int _value;
    static const int _frac_bit;
    
public:
    Fixed();
    Fixed(const Fixed& source);
    Fixed& operator=(const Fixed &src);
    ~Fixed();
    Fixed(const int val);
    Fixed(const float f_val);
    float toFloat(void) const;
    int toInt( void ) const;
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, Fixed const& fix);
