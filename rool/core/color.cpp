#include "color.h"

Color::Color()
{
	r=0;
	g=0;
	b=0;
	a=255;
}

Color::Color(const Uint8 &r_,const Uint8 &g_,const Uint8 &b_,const Uint8 &a_)
{
  r=r_;
  g=g_;
  b=b_;
  a=a_;
}

SDL_Color Color::convertToSDL()
{
	SDL_Color c;
	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return c;
}

Color Color::shadowed()
{
	return Color((Uint8)((float)r/2.f),(Uint8)((float)g/2.f),(Uint8)((float)b/2.f),a);
}

bool Color::operator== (const Color &OperandeDeDroite) {
	 if ( r == OperandeDeDroite.r && g == OperandeDeDroite.g && b == OperandeDeDroite.b && a == OperandeDeDroite.a ) { 
		 return true; 
	}
	return false;
 }

  bool Color::operator!= (const Color &OperandeDeDroite) {
	 if ( r != OperandeDeDroite.r && g != OperandeDeDroite.g && b != OperandeDeDroite.b && a != OperandeDeDroite.a ) { 
		 return true; 
	}
	return false;
 }

