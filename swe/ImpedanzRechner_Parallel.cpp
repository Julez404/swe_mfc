#include "stdafx.h"
#include "ImpedanzRechner_Parallel.h"


ImpedanzRechner_Parallel::ImpedanzRechner_Parallel()
{
}


ImpedanzRechner_Parallel::~ImpedanzRechner_Parallel()
{
}

CComplex ImpedanzRechner_Parallel::berechneImpedanz(const CListe& _list, const double _f) const
{
	CBauelement* ptr = _list.getStart();
	CComplex impedanz;

	while (ptr != NULL)
	{
		if (ptr->getImpedanz(_f).getBetrag() != NULL)
		{
			impedanz = impedanz + (ptr->getImpedanz(_f).getKehrwert());
		}
		else
		{
			std::cout << "0 Ohm Resisdance" << std::endl;
		}
		ptr = ptr->getNext();
	}
	return impedanz.getKehrwert();
}