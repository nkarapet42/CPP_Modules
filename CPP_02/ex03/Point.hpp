#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class	Point {

public:

	Point();
	Point(const float val_x, const float val_y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();

	float	GetX( void ) const;
	float	GetY( void ) const;

private:

	Fixed const			x;
	Fixed const			y;
	
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif