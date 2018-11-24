#include "stdafx.h"
#include "liste.h"

CListe::CListe()
	:start(NULL)
{}

CListe::CListe(CBauelement* _bauelement)
{
	start = _bauelement;
}

CListe::~CListe()
{
	CBauelement* delPtr =start;

	while (start != NULL) 
	{
		start = start->getNext();
		delete delPtr;
		delPtr = start;
	}
}

CBauelement* CListe::getStart(void) const
{
	return start;
}

int CListe::getEntryCount(void)const
{
	CBauelement* ptr = start;
	int count = 0;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->getNext();
	}
	return count;
}

void CListe::printAllElements(void) const
{
	CBauelement* ptr = NULL;

	for (ptr = start; ptr != NULL; ptr = ptr->getNext())
	{
		ptr->print();
	}
}

CBauelement* CListe::searchName(const std::string& _nameToFind) const
{
	CBauelement* nameSearchPtr = start;
	while (nameSearchPtr != NULL)
	{
		if (nameSearchPtr->getName() == _nameToFind)
		{
			return nameSearchPtr;
		}
		nameSearchPtr = nameSearchPtr->getNext();
	}
	return NULL;
}

CComplex CListe::getSerialImpedanz(double _f) const
{
	CBauelement* lookupPtr = start;
	CComplex serialImpedanz;

	while (lookupPtr != NULL)
	{
		serialImpedanz = serialImpedanz + lookupPtr->getImpedanz(_f);
		lookupPtr = lookupPtr->getNext();
	}
	return serialImpedanz;
}

CComplex CListe::getImpedanzOfList(double _f) const 
{
	return ImpPtr->berechneImpedanz(*this,_f);
}

bool CListe::setStart(CBauelement* _newStartPtr)
{
	return 0;
}

bool CListe::addToStart(CBauelement* _newStartPtr)
{
	if (_newStartPtr == NULL)
	{
		return 1;
	}
	else
	{
		(*_newStartPtr).setNext(start);
		start = _newStartPtr;
		return 0;
	}
}

bool CListe::addToEnd(CBauelement * _newStartPtr)
{
	if (_newStartPtr == NULL)
		return 1;
	else
	{
		if (start == NULL)
		{
			start = _newStartPtr;
		}
		else
		{
			CBauelement* lookupPtr = start;
			CBauelement* lookupPtrOld = lookupPtr;
			while (lookupPtr != NULL)
			{
				lookupPtrOld = lookupPtr;
				lookupPtr = lookupPtr->getNext();
			}
			lookupPtrOld->setNext(_newStartPtr);
		}
		return 0;
	}
}

bool CListe::delAtStart()
{	
	CBauelement* delPtr = start;

	if (start != NULL)
	{
		if (start->getNext() == NULL)
		{
			delete start;
			return 0;
		}
		else
		{
			start = start->getNext();
			delete delPtr;
			return 0;
		}
	}
	return 1;
}

void CListe::setImpPtr(ImpedanzRechner* _ImpPtr)
{
	ImpPtr = _ImpPtr;
}

std::ostream& operator<<(std::ostream& stream, const CListe& _list)
{
	CBauelement* ptr = _list.start;
	while (ptr != NULL)
	{
		stream << (*ptr);
		stream << std::endl;
		ptr = ptr->getNext();
	}
	return stream;
}