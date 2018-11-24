#include "stdafx.h"
#include "Spule.h"


CSpule::CSpule()
	:CBauelement(), l(0)	
{}

CSpule::CSpule(std::string _name, double _preis, CPunkt _position, double _l)
	: CBauelement(_name, _preis, _position), l(_l)
{}

CSpule::~CSpule()
{}


double CSpule::getL() const
{
	return l;
}
CComplex CSpule::getImpedanz(double _f) const
{
	return CComplex(0, 2 * M_PI*_f*l);
}

void CSpule::print(void) const 
{
	std::cout << "Bez.: " << name << " Preis: " << preis << " EUR  Position: " << position << " L: " << l << " H" << std::endl;
}

void CSpule::setL(double _l)
{
	l = _l;
}


std::ostream& operator<<(std::ostream& stream, CSpule toPrint)
{
	stream << toPrint.name << ", " << toPrint.l << "H, " << toPrint.getPreis() << " EUR, " << toPrint.getPosition();
	return stream;
}

