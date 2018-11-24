#include "stdafx.h"
#include "punkt.h"


CPunkt::CPunkt()
	:x(0), y(0),next(NULL)
{}

CPunkt::CPunkt(double _x, double _y, CPunkt* _next)
	: x(_x), y(_y),next(_next)
{};

CPunkt::~CPunkt()
{}


double CPunkt::getX(void) const
{
	return x;
}
double CPunkt::getY(void) const
{
	return y;
}
double CPunkt::getDistance(void) const
{
	return sqrt(x*x + y*y);
}
CPunkt* CPunkt::getNext(void) const
{
	return next;
}

void CPunkt::setX(double _x)
{
	x = _x;
}
void CPunkt::setY(double _y)
{
	y = _y;
}
void CPunkt::setXY(double _x, double _y)
{
	x = _x;
	y = _y;
}
void CPunkt::setNext(CPunkt* _next)
{
	next = _next;
}

std::ostream& operator<<(std::ostream& stream, const CPunkt& _punkt)
{
	stream << "(" << _punkt.x << "|" << _punkt.y << ")";
	return stream;
}