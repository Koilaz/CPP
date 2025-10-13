#include "Point.hpp"
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
    Point a(1.5f,0);
    Point b(42,0);
    Point c(0,69.9);
    Point x(12, 25.87);

    if(bsp(a,b,c,x))
        std::cout<<"x is inside the triangle"<< std::endl;
    else
        std::cout<<"x is NOT inside the triangle"<< std::endl;
}

