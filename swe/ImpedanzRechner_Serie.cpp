#include "stdafx.h"

#include "ImpedanzRechner_Serie.h"
#include "Bauelement.h"
#include "Complex.h"


ImpedanzRechner_Serie::ImpedanzRechner_Serie()
{

}

ImpedanzRechner_Serie::~ImpedanzRechner_Serie()
{
}

CComplex ImpedanzRechner_Serie::berechneImpedanz(const CListe& _list, const double _f) const
{
	CBauelement* ptr = _list.getStart();
	CComplex impedanz;

	while (ptr != NULL)
	{
		impedanz = impedanz + ptr->getImpedanz(_f);
		ptr = ptr->getNext();
	}
	return impedanz;
}

