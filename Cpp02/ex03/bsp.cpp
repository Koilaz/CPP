#include"Point.hpp"
#include<math.h>

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Point vector_PA = get_vector(point, a);
    Point vector_PB = get_vector(point, b);
    Point vector_PC = get_vector(point, c);
    Fixed PA = Pythagore(vector_PA.getx(), vector_PA.gety);
   
}

Point get_vector(Point const a, Point const b)
{
    Point vector((a.getx().toFloat() - b.getx().toFloat()),( a.gety().toFloat() - b.gety().toFloat()));
}

Fixed Pythagore(const Point va,const Point vb)
{
     Fixed ab(sqrtfx8(va.getx() * va.getx() + vb.getx() * vb.getx()));
     return (ab);
}

Fixed sqrtfx8(Fixed x)
{
    float f;
    f = x.toFloat();
    Fixed ret(sqrtf32(f));
    return ret;
}

Fixed scal(const Point va, const Point vb)
{
    return(va.getx() * vb.getx() - va.gety() * vb.gety());
}


