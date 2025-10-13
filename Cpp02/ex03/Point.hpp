#ifndef POINT_H
 #define POINT_H

#include"Fixed.hpp"

class Point
{
    private:
    Fixed   x;
    Fixed   y;

    public:

    Point();
    Point(const float fx, const float fy);
    Point(const Point& src);
    ~Point();
    Fixed getx() const;
    Fixed gety() const;
};

#endif 