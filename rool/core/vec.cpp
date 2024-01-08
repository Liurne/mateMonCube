#include "vec.h"

Vec2D::Vec2D(int x_,int y_)
{
    x=x_;
    y=y_;
}

void Vec2D::operator=(const Vec2D & vec)
{
    x=vec.x;
    y=vec.y;
}
void Vec2D::operator+=(const Vec2D & vec)
{
    x+=vec.x;
    y+=vec.y;
}
Vec2D Vec2D::operator+(const Vec2D & vec)
{
    return Vec2D(x+vec.x,y+vec.y);
}

Vec2D Vec2D::operator*(const int & m)
{
    return Vec2D(x*=m,y*=m);
}