#include "shape.h"


Point::Point()
{
	x=0;
	y=0;
}
Point::Point(const int &x_,const int &y_)
{
	x=x_;
	y=y_;
}


void Point::setPoint(const int &x_,const int &y_)
{
	x=x_;
	y=y_;
}

void Point::operator=(const Point & p)
{
	x=p.x;
	y=p.y;
}

void Point::operator+=(const Point & p)
{
	x += p.x;
	y += p.y;
}

Point Point::operator+(const Point & p)
{
	x= x + p.x;
	y= y + p.y;
	return Point(x+p.x,y+p.y);
}

Point::~Point()
{
 x=0;
 y=0;
}

Line::Line()
{
	p1.x=0;
	p1.y=0;
	p2.x=0;
	p2.y=0;
}

Line::Line(const Point &pt1,const Point &pt2)
{
	p1=pt1;
	p2=pt2;
}

Line::Line(const int &x1,const int &y1,const int &x2,const int &y2)
{
	p1.x=x1;
	p1.y=y1;
	p2.x=x2;
	p2.y=y2;
}

void Line::setLine(const Point &pt1,const Point &pt2)
{
	p1=pt1;
	p2=pt2;
}

void Line::setLine(const int &x1,const int &y1,const int &x2,const int &y2)
{
	p1.x=x1;
	p1.y=y1;
	p2.x=x2;
	p2.y=y2;
}

void Line::operator=(const Line & l)
{
	p1=l.p1;
	p2=l.p2;
}

Line::~Line()
{

}

Rectangle::Rectangle::Rectangle()
{
	x=0;
	y=0;
	w=0;
	h=0;
}

Rectangle::Rectangle(const int &x_,const int &y_,const int &w_,const int &h_)
{
	x=x_;
	y=y_;
	w=w_;
	h=h_;
	fill=true;
}
Rectangle::Rectangle(const int &x_,const int &y_,const int &w_,const int &h_,const bool &isFill)
{
	x=x_;
	y=y_;
	w=w_;
	h=h_;
	fill=isFill;
}

Rectangle::~Rectangle()
{

}

void Rectangle::setRectangle(const int &x_,const int &y_,const int &w_,const int &h_)
{
	x=x_;
	y=y_;
	w=w_;
	h=h_;
	fill=true;
}
void Rectangle::setRectangle(const int &x_,const int &y_,const int &w_,const int &h_,const bool &isFill)
{
	x=x_;
	y=y_;
	w=w_;
	h=h_;
	fill=isFill;
}
void Rectangle::setPosition(const int &x_,const int &y_)
{
	x=x_;
	y=y_;
}
void Rectangle::setDimension(const int &w_,const int &h_)
{
	w=w_;
	h=h_;
}

void Rectangle::setFillOrNo(const bool &isFill)
{
	fill=isFill;
}

SDL_Rect Rectangle::toSDL()
{
	return SDL_Rect {x,y,w,h};
}