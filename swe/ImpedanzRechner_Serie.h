#pragma once

#include "ImpedanzRechner.h"
#include "Liste.h"
#include "Complex.h"


class ImpedanzRechner_Serie :
	public ImpedanzRechner
{
public:
	ImpedanzRechner_Serie();
	~ImpedanzRechner_Serie();

	CComplex berechneImpedanz(const CListe& _list, const double _f) const;
};

