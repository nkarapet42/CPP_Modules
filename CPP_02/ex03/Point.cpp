#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float val_x, const float val_y) : x(val_x), y(val_y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

float	Point::GetX ( void ) const {
	return (x.toFloat());
}

float	Point::GetY ( void ) const {
	return (y.toFloat());
}

Point& Point::operator=(const Point& other) {
	if (this == &other)
		return (*this);
	(Fixed)this->x = other.GetX();
	(Fixed)this->y = other.GetY();
	return (*this);
}

Point::~Point() {}