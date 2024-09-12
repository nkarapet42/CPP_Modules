#include "Point.hpp"

float	my_abs(float num) {
	if (num < 0)
		return (-num);
	return (num);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	if ((point.GetX() == a.GetX() && point.GetY() == a.GetY())
		|| (point.GetX() == b.GetX() && point.GetY() == b.GetY())
		|| (point.GetX() == c.GetX() && point.GetY() == c.GetY()))
		return (false);
	if (((point.GetX()*(a.GetY() - b.GetY()) + a.GetX()*(b.GetY() - point.GetY()) + b.GetX()*(point.GetY() - a.GetY())) == 0)
		|| ((point.GetX()*(b.GetY() - c.GetY()) + b.GetX()*(c.GetY() - point.GetY()) + c.GetX()*(point.GetY() - b.GetY())) == 0)
		|| ((point.GetX()*(c.GetY() - a.GetY()) + c.GetX()*(a.GetY() - point.GetY()) + a.GetX()*(point.GetY() - c.GetY())) == 0))
		return (false);
	if ((my_abs((point.GetX()*(a.GetY() - b.GetY()) + a.GetX()*(b.GetY() - point.GetY()) + b.GetX()*(point.GetY() - a.GetY())))
		+ my_abs((point.GetX()*(b.GetY() - c.GetY()) + b.GetX()*(c.GetY() - point.GetY()) + c.GetX()*(point.GetY() - b.GetY())))
		+ my_abs((point.GetX()*(c.GetY() - a.GetY()) + c.GetX()*(a.GetY() - point.GetY()) + a.GetX()*(point.GetY() - c.GetY()))))
		== my_abs((a.GetX()*(b.GetY() - c.GetY()) + b.GetX()*(c.GetY() - a.GetY()) + c.GetX()*(a.GetY() - b.GetY()))))
		return (true);
	else
		return (false);
}