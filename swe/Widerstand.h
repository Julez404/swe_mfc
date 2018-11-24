#pragma once

#include "Bauelement.h"
#include "Complex.h"

class CWiderstand :
	public CBauelement
{
protected:
	double r;
public:
	CWiderstand();
	CWiderstand(std::string _name, double _preis, CPunkt _position, double _r);
	~CWiderstand();

	double getR() const;
	CComplex getImpedanz(double _f) const;
	void print(void) const;
	void setR(double _r);

	friend 	std::ostream& operator<<(std::ostream& stream, CWiderstand _CWiderstand);
};

