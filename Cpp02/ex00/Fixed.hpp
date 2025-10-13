#ifndef FIXED_HPP
# define FIXED_HPP

# include<string>
# include<iostream>

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
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif