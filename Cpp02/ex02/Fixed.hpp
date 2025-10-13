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
    ~Fixed();
    Fixed(const int val);
    Fixed(const float f_val);

    Fixed& operator=(const Fixed &src);
    float   toFloat(void) const;
    int     toInt( void ) const;
    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    bool    operator>(const Fixed& src) const;
    bool    operator<(const Fixed& src) const;
    bool    operator>=(const Fixed& src) const;
    bool    operator<=(const Fixed& src) const;
    bool    operator==(const Fixed& src) const;
    bool    operator!=(const Fixed& src) const;
    Fixed   operator+(const Fixed& src) const;
    Fixed   operator-(const Fixed& src) const;
    Fixed   operator*(const Fixed& src) const;
    Fixed   operator/(const Fixed& src) const;
    Fixed&	operator ++();
    Fixed	operator ++(int);
    Fixed&	operator --();
    Fixed	operator --(int);
    static Fixed& min(Fixed& A, Fixed& B);
    static const Fixed& min(const Fixed& A,const Fixed& B);
    static Fixed& max(Fixed& A, Fixed& B);
    static const Fixed& max(const Fixed& A,const Fixed& B);
};

std::ostream& operator<<(std::ostream& os, Fixed const& fix);
