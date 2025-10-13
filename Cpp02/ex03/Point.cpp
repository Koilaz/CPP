#include"Point.hpp"

Point::Point()
{
    x.setRawBits(0);
    y.setRawBits(0);
}

Point::Point(const float fx, const float fy) : x(fx), y(fy)
{}

Point::Point(const Point& src)
{
    *this = src;
}

Point::~Point()
{}

Fixed Point::getx() const
{
    return(this->x);
}
Fixed Point::gety() const
{
    return(this->y);
}