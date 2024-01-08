#ifndef SHAPE_H
#define SHAPE_H

#include "include.h"

/**
 * @brief Class who manage point to simplify SDL2 library
 * 
 */
class Point
{
	public:
		/**
		 * @brief Construct a new Point object with default values.
		 * Built at position x: 0 and position y: on the plane screen that starts at the top of the screen.
		 */
		Point();
		/**
		 * @brief Construct a new Point object with default values with the positions chosen
		 * 
		 * @param x_ The new position at x
		 * @param y_ The new position at y
		 */
		Point(const int &x_,const int &y_);
		/**
		 * @brief Destroy the Point object
		 * 
		 */
		virtual ~Point();
		/**
		 * @brief Set the Point object
		 * 
		 * @param x_ The new position at x
		 * @param y_ The new position at y
		 */
		void setPoint(const int &x_,const int &y_);
		/**
		 * @brief Override the "=" operator so that a Point takes the same value as another
		 * 
		 * @param p The Point object whose value we take
		 */
		void operator=(const Point & p);
		/**
		 * @brief Override the "+=" operator so that a Point takes the value of the point plus a value
		 * @param p The Point object whose value we take
		 */
		void operator+=(const Point & p);
		/**
		 * @brief Override the "+" operator to add two point objects
		 * 
		 * @param p Object point 
		 * @return Object Point 
		 */
		Point operator+(const Point & p);

		friend ostream& operator<<(ostream& out, const Point& p )
		{
			return out <<"("<< p.x <<", "<< p.y<<")";
		}

		int x,y;
};

/**
 * @brief Class who manage line to simplify SDL2 library
 * 
 */
class Line
{
	public:
		/**
		 * @brief Construct a new Line object with default value
		 * Built at position x: 0 and position y: on the plane screen that starts at the top of the screen 
		 * (as the start and finish of the line are at (0,0) it is a "point")
		 */
		Line();
		/**
		 * @brief Construct a new Line object.
		 * Two point that connect into a line.
		 * 
		 * @param pt1 Object point
		 * @param pt2 Object point
		 */
		Line(const Point &pt1,const Point &pt2);
		/**
		 * @brief Construct a new Line with SDL
		 * 
		 * @param x1 X position of the first point
		 * @param y1 Y position of the first point
		 * @param x2 X position of the second point
		 * @param y2 Y position of the second point
		 */
		Line(const int &x1,const int &y1,const int &x2,const int &y2);
		/**
		 * @brief Destroy the Line object
		 * 
		 */
		virtual ~Line();
		/**
		 * @brief Set the Line object thanks to two object point (x,y) position
		 * 
		 * @param pt1 Object point
		 * @param pt2 Object point
		 */
		void setLine(const Point &pt1,const Point &pt2);
		/**
		 * @brief Set the Line object
		 * 
		 * @param x1 X position of the first point
		 * @param y1 Y position of the first point
		 * @param x2 X position of the second point
		 * @param y2 Y position of the second point
		 */
		void setLine(const int &x1,const int &y1,const int &x2,const int &y2);
		/**
		 * @brief Operator "=" overload so that one line is equal to another
		 * 
		 * @param l Object line
		 */
		void operator=(const Line & l);

		friend ostream& operator<<(ostream& out, const Line& l ) 
		{
			return out <<"l("<< l.p1.x <<", "<< l.p1.y<<"), ("<<l.p2.x<<", "<<l.p2.y<<")";
		}

		Point p1,p2;
};

/**
 * @brief Class who manage rectangle to simplify SDL2 library
 * 
 */
class Rectangle
{
	public:
		/**
		 * @brief Construct a new Rectangle object
		 * 
		 */
		Rectangle();

		/**
		 * @brief Construct a new Rectangle object
		 * 
		 * @param x_ Position X
		 * @param y_ Position Y
		 * @param w_ Width Rectangle
		 * @param h_ Height Rectangle 
		 */
		Rectangle(const int &x_,const int &y_,const int &w_,const int &h_);
		
		/**
		 * @brief Construct a new Rectangle object
		 * 
		 * @param x_ Position X rectangle
		 * @param y_ Position Y rectangle
		 * @param w_ Width rectangle
		 * @param h_  Height rectangle
		 * @param isFill True: rectangle is fill
		 */
		Rectangle(const int &x_,const int &y_,const int &w_,const int &h_,const bool &isFill);
		
		/**
		 * @brief Destroy the Rectangle object
		 * 
		 */
		virtual ~Rectangle();

		friend ostream& operator<<(ostream& out, const Rectangle& r ) 
		{
			return out <<"("<< r.x <<", "<< r.y<<", "<<r.w<<", "<<r.h<<")";
		}
		/**
		 * @brief Set the Rectangle object (position and height/width)
		 * 
		 * @param x_ Position X rectangle
		 * @param y_ Position Y rectangle
		 * @param w_ Width rectangle
		 * @param h_ Height rectangle
		 */
		void setRectangle(const int &x_,const int &y_,const int &w_,const int &h_);
		/**
		 * @brief Set the Rectangle object (position and height/width)
		 * 
		 * @param x_ Position X rectangle
		 * @param y_ Position Y rectangle
		 * @param w_ Width rectangle
		 * @param h_ Height X rectangle
		 * @param isFill Fill rectangle or not
		 */

		void setRectangle(const int &x_,const int &y_,const int &w_,const int &h_,const bool &isFill);
		/**
		 * @brief Set the Position object
		 * 
		 * @param x_ Position X
		 * @param y_ Position Y
		 */
		void setPosition(const int &x_,const int &y_);
		/**
		 * @brief Set the Dimension object
		 * 
		 * @param w_ Width 
		 * @param h_ Height
		 */
		void setDimension(const int &w_,const int &h_);
		/**
		 * @brief Set if the rectangle is fill or not
		 * 
		 * @param isFill Boolean :true it is fill
		 */
		void setFillOrNo(const bool &isFill);
		SDL_Rect toSDL();

		int x,y,w,h;
		bool fill;
};

#endif