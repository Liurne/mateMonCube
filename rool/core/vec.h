#ifndef VEC_H
#define VEC_H

#include "include.h"

/**
 * @brief class who manage a vector 2D 
 * 
 */
class Vec2D
{
    public:
        /**
         * @brief Construct a new Vec 2D object
         * 
         * @param x_ position X
         * @param y_ position Y
         */
        Vec2D(int x_,int y_);

        /**
         * @brief Operator overload "="
         * 
         * @param vec Object Vector
         */
        void operator=(const Vec2D & vec);

        /**
         * @brief Operator overload "+="
         * 
         * @param vec Object Vector
         */
        void operator+=(const Vec2D & vec);

        /**
         * @brief Operator overload "+"
         * 
         * @param vec Object Vector
         * @return Vec2D 
         */
        Vec2D operator+(const Vec2D & vec);

        /**
         * @brief Operator overload "*"
         * 
         * @param m Object Vector
         * @return Vec2D 
         */
        Vec2D operator*(const int & m);

        friend ostream& operator<<(ostream& out, const Vec2D& vec )
		{
			return out <<"("<< vec.x <<", "<< vec.y<<")";
		}

        int x,y;

    private:


};

#endif