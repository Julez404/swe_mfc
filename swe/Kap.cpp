#include "stdafx.h"
#include "Kap.h"


CKap::CKap()
	:CBauelement(), c(0)
{}

CKap::CKap(std::string _name, double _preis, CPunkt _position, double _c)
	:CBauelement(_name, _preis, _position),c(_c)
{}


CKap::~CKap()
{
}

double CKap::getC() const
{
	return c;
}

CComplex CKap::getImpedanz(double _f) const
{
	return CComplex(0, -(1 / (2 * M_PI*_f*c)));
}

void CKap::print(void) const
{
	std::cout << "Bez.: " << name << " Preis: " << preis << " EUR  Position: " << position << " C: " << c << " F" << std::endl;
}

void CKap::setC(double _c)
{
	c = _c;
}

std::ostream& operator<<(std::ostream& stream, CKap toPrint)
{
	stream << toPrint.getName() << ", " << toPrint.getC() << "F, " << toPrint.getPreis() << "EUR, " << toPrint.getPosition();
	return stream;
}


