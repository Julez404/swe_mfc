#pragma once

#include "Complex.h"

class CListe;

class ImpedanzRechner
{
public:
	ImpedanzRechner();
	virtual ~ImpedanzRechner();
	virtual CComplex berechneImpedanz(const CListe& _list, const double _f) const = 0;
};

