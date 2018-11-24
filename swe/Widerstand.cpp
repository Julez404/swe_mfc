#include "stdafx.h"
#include "Widerstand.h"


CWiderstand::CWiderstand()
{
	r = 0.0;
}

CWiderstand::CWiderstand(std::string _name, double _preis, CPunkt _position, double _r)
:CBauelement(_name,_preis,_position),r(_r)
{}

CWiderstand::~CWiderstand()
{}

double CWiderstand::getR() const
{
	return r;
}

CComplex CWiderstand::getImpedanz(double _f) const
{
	return CComplex(r, 0);
}

void CWiderstand::setR(double _r)
{
	r = _r;
}

void CWiderstand::print(void) const
{
	std::cout << "Bez.: " << name << " Preis: " << preis << " EUR  Position: " << position << " R: " << r << " Ohm" <<  std::endl;
}

std::ostream& operator<<(std::ostream& stream, CWiderstand toPrint)
{
	stream << toPrint.name << ", " << toPrint.r << "Ohm, " << toPrint.preis << "EUR, " << toPrint.position;
	return stream;
}