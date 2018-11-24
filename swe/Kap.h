#pragma once

#include "Bauelement.h"
#include "Complex.h"

class CKap :
	public CBauelement
{
protected:
	double c;

public:
	CKap();
	CKap(std::string _name, double _preis, CPunkt _position, double _c);
	~CKap();

	double getC() const;
	CComplex getImpedanz(double _f)const;
	void print(void) const;

	void setC(double _c);
	};

std::ostream& operator<<(std::ostream& stream, CKap toPrint);
